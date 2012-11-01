#include "Agent.h"

Agent::Agent(std::string name, std::string filename, Item** items)
{
	using namespace Ogre;
	if (sceneMgr == NULL)
		return;

	mBodyNode = sceneMgr->getRootSceneNode()->createChildSceneNode();
	mBodyEntity = sceneMgr->createEntity(name, filename);
	mBodyNode->attachObject(mBodyEntity);

	mBodyNode->translate(0,5,0); // make the Ogre stand on the plane
	
	setupAnimations();

	mWalkSpeed = 35.0f;
	mDirection = Ogre::Vector3::ZERO;

	mItems = items;
	mHeldItem = NULL;
}

Agent::~Agent(){}

void
Agent::update(Ogre::Real deltaTime)
{
	this->updateAnimations(deltaTime);
	if(this->updatePickup(deltaTime))
	{
		this->updateLocomote(deltaTime);
	}
}


void 
Agent::setupAnimations()
{
	this->mTimer = 0;
	this->mVerticalVelocity = 0;
	
	// this is very important due to the nature of the exported animations
	mBodyEntity->getSkeleton()->setBlendMode(Ogre::ANIMBLEND_CUMULATIVE);
	
	Ogre::String animNames[] =
		{"IdleBase", "IdleTop", "RunBase", "RunTop", "HandsClosed", "HandsRelaxed", "DrawSwords",
		"SliceVertical", "SliceHorizontal", "Dance", "JumpStart", "JumpLoop", "JumpEnd"};

	// populate our animation list
	for (int i = 0; i < 13; i++)
	{
		mAnims[i] = mBodyEntity->getAnimationState(animNames[i]);
		mAnims[i]->setLoop(true);
		mFadingIn[i] = false;
		mFadingOut[i] = false;
	}

	// start off in the idle state (top and bottom together)
	setBaseAnimation(ANIM_IDLE_BASE);
	setTopAnimation(ANIM_IDLE_TOP);

	// relax the hands since we're not holding anything
	mAnims[ANIM_HANDS_RELAXED]->setEnabled(true);
}

void 
Agent::setBaseAnimation(AnimID id, bool reset)
{
	if (mBaseAnimID >= 0 && mBaseAnimID < 13)
	{
		// if we have an old animation, fade it out
		mFadingIn[mBaseAnimID] = false;
		mFadingOut[mBaseAnimID] = true;
	}

	mBaseAnimID = id;

	if (id != ANIM_NONE)
	{
		// if we have a new animation, enable it and fade it in
		mAnims[id]->setEnabled(true);
		mAnims[id]->setWeight(0);
		mFadingOut[id] = false;
		mFadingIn[id] = true;
		if (reset) mAnims[id]->setTimePosition(0);
	}
}
	
void Agent::setTopAnimation(AnimID id, bool reset)
{
	if (mTopAnimID >= 0 && mTopAnimID < 13)
	{
		// if we have an old animation, fade it out
		mFadingIn[mTopAnimID] = false;
		mFadingOut[mTopAnimID] = true;
	}

	mTopAnimID = id;

	if (id != ANIM_NONE)
	{
		// if we have a new animation, enable it and fade it in
		mAnims[id]->setEnabled(true);
		mAnims[id]->setWeight(0);
		mFadingOut[id] = false;
		mFadingIn[id] = true;
		if (reset) mAnims[id]->setTimePosition(0);
	}
}

void 
Agent::updateAnimations(Ogre::Real deltaTime)
{
	using namespace Ogre;

	Real baseAnimSpeed = 1;
	Real topAnimSpeed = 1;

	mTimer += deltaTime;

	if (mTimer >= mAnims[mTopAnimID]->getLength())
	{
		
	}
	
	// increment the current base and top animation times
	if (mBaseAnimID != ANIM_NONE) mAnims[mBaseAnimID]->addTime(deltaTime * baseAnimSpeed);
	if (mTopAnimID != ANIM_NONE) mAnims[mTopAnimID]->addTime(deltaTime * topAnimSpeed);

	// apply smooth transitioning between our animations
	fadeAnimations(deltaTime);
}

void 
Agent::fadeAnimations(Ogre::Real deltaTime)
{
	using namespace Ogre;

	for (int i = 0; i < 13; i++)
	{
		if (mFadingIn[i])
		{
			// slowly fade this animation in until it has full weight
			Real newWeight = mAnims[i]->getWeight() + deltaTime * 7.5f; //ANIM_FADE_SPEED;
			mAnims[i]->setWeight(Math::Clamp<Real>(newWeight, 0, 1));
			if (newWeight >= 1) mFadingIn[i] = false;
		}
		else if (mFadingOut[i])
		{
			// slowly fade this animation out until it has no weight, and then disable it
			Real newWeight = mAnims[i]->getWeight() - deltaTime * 7.5f; //ANIM_FADE_SPEED;
			mAnims[i]->setWeight(Math::Clamp<Real>(newWeight, 0, 1));
			if (newWeight <= 0)
			{
				mAnims[i]->setEnabled(false);
				mFadingOut[i] = false;
			}
		}
	}
}

void
Agent::getObjects()
{
	for(int i=0; i<5; i++) // all objects
	{
		Item* pickup = mItems[i];
		this->pickUpObject(pickup);
	}
}

void
Agent::pickUpObject(Item* pickup)
{
	// Turn to face pickup
	Ogre::Real height = 5; // height of Sinbad
	
	Ogre::Vector3 pos = pickup->getPosition();
	mWalkList.push_back(Ogre::Vector3(pos.x, height, pos.z));
	mShoppingList.push_back(pickup);
}

bool
Agent::updatePickup(Ogre::Real deltaTime)
{
	// TODO: Optimize branching conditions to remove blank branches
	// Note: Needs to be called every frame
	
	if(mShoppingList.empty())
	{
		return bendToStand(deltaTime);
	}
	else
	{
		Item* pickup = mShoppingList.front();
		Ogre::Vector3 pickupPosition = pickup->getPosition();
		Ogre::Vector3 bodyPosition = mBodyNode->getPosition();
		
		// Only pickup target item
		// NOTE: Does not take elevation into account
		if(pickupPosition.x == bodyPosition.x &&
		pickupPosition.z == bodyPosition.z)
		{
			// Bend over
			bendOver(deltaTime);
			if(mTimer > 2)
			{
				// Hide last item in hand, if any
				//~ if(!mInventory.empty()){
					//~ mInventory.back()->hide();
				//~ }
				if(mHeldItem != NULL){
					mHeldItem->hide();
					mHeldItem = pickup;
				}
				
				
				// Pick it up
				mInventory.push_back(pickup);
				pickup->equipTo(mBodyEntity, "Hand.R");
				
				// Close hand
				mAnims[ANIM_HANDS_CLOSED]->setEnabled(true);
				mAnims[ANIM_HANDS_RELAXED]->setEnabled(false);
				
				// Adjust positional properties based on which object is equipped.
				if(pickup->getName() == "fish"){
					pickup->translate(0, 0.5, 0);
				}
				else if(pickup->getName() == "9mm"){
					pickup->roll(Ogre::Degree(90));
					pickup->pitch(Ogre::Degree(180));
					
					pickup->translate(-0.2, 1.3, -0.3);
				}
				else if(pickup->getName() == "38pistol"){
					pickup->yaw(Ogre::Degree(180));
					
					pickup->translate(0, 1.3, 0);
				}
				else if(pickup->getName() == "briefcase"){
					pickup->roll(Ogre::Degree(180));
					
					pickup->translate(0, 1.8, 0);
				}
				else if(pickup->getName() == "thermos"){
					pickup->roll(Ogre::Degree(90));
					pickup->yaw(Ogre::Degree(180));
					
					pickup->translate(2.1, 1.4, -0.25);
				}
				
				// Turn item in hand invisible, if any
				//~ if(mHeldItem != NULL){
					//~ mHeldItem->hide();
				//~ }
				//~ mHeldItem = pickup;
				
				// Remove from shopping list
				mShoppingList.pop_front();
			}
			
			return false;
		}
		else
		{
			return bendToStand(deltaTime);
		}
	}
	
	return true;
}

// Processes the next place the entity should head towards
// Includes processing how far away such a target is.
bool 
Agent::nextLocation()
{
	if(mWalkList.empty())
	{
		return false;
	}
	
	// Get next point from the queue
	mDestination = mWalkList.front();
	mWalkList.pop_front();
	
	mDirection = mDestination - mBodyNode->getPosition();
	
	mDistance = mDirection.normalise(); // Normalize direction in-place, and return length
	
	return true;
}

void 
Agent::updateLocomote(Ogre::Real deltaTime)
{
	if (mDirection == Ogre::Vector3::ZERO) 
	{
		if (nextLocation())
		{
			// Set walking animation
			setTopAnimation(ANIM_RUN_TOP, false);
			setBaseAnimation(ANIM_RUN_BASE, false);
			
			faceForward();
		}
	}
	else
	{
		Ogre::Real move = mWalkSpeed * deltaTime;
		mDistance -= move;
		
		if (mDistance <= 0.0f)
		{
			mBodyNode->setPosition(mDestination);
			mDirection = Ogre::Vector3::ZERO;
		
			if (!nextLocation())
			{
				// Set Idle animation                     
				setTopAnimation(ANIM_IDLE_BASE, true);
				setBaseAnimation(ANIM_IDLE_TOP, true);
			}
			else
			{
				// Correct rotation towards the next node
				faceForward();
			}
		}
		else
		{
			mBodyNode->translate(mDirection * move);
		}
	}
}

void
Agent::faceForward()
{
	// This variant accounts for 180 degree turns
	Ogre::Vector3 src = mBodyNode->getOrientation() * Ogre::Vector3::UNIT_Z;
	if ((1.0f + src.dotProduct(mDirection)) < 0.0001f) 
	{
		mBodyNode->yaw(Ogre::Degree(180));
	}
	else
	{
		src.y = 0;									// Ignore pitch difference angle
		mDirection.y = 0;
		src.normalise();
		Ogre::Real mDistance = mDirection.normalise();	// Both vectors modified so renormalize them
		
		Ogre::Quaternion quat = src.getRotationTo(mDirection);
		mBodyNode->rotate(quat);
	} // else
}

bool
Agent::bendOver(Ogre::Real deltaTime)
{
	Ogre::SkeletonInstance* skeleton = mBodyEntity->getSkeleton();
	Ogre::Bone* waist = skeleton->getBone("Waist");
	
	if(!waist->isManuallyControlled())
	{
		setBaseAnimation(ANIM_IDLE_BASE, true);
		setTopAnimation(ANIM_IDLE_TOP, true);
		waist->setManuallyControlled(true);
	}
	else
	{
		Ogre::Degree targetRotation = Ogre::Degree(45);
		if(waist->getOrientation().getPitch() < targetRotation) // animation not yet complete
		{
			waist->pitch(targetRotation * deltaTime);
		}
		else // animation complete
		{
			//~ waist->setManuallyControlled(false);
			//~ runAnimationBendOver = false;
			return true;
		}
	}
	
	return false;
}

bool
Agent::bendToStand(Ogre::Real deltaTime)
{
	// Bone should be set to manually controlled at this point, because of bendOver()
	Ogre::SkeletonInstance* skeleton = mBodyEntity->getSkeleton();
	Ogre::Bone* waist = skeleton->getBone("Waist");
	
	if(waist->isManuallyControlled()){
		Ogre::Degree targetRotation = Ogre::Degree(0);
		
		if(waist->getOrientation().getPitch() > targetRotation) // animation not yet complete
		{
			
			waist->pitch(Ogre::Degree(-45) * deltaTime);
		}
		else // animation complete, return control of bone back to animation system
		{
			waist->setManuallyControlled(false);
			mTimer = 0;
			
			// If you have a destination to go to, run there, else return to idle
			if(mDestination.positionEquals(mBodyNode->getPosition()))
			{
				setTopAnimation(ANIM_IDLE_TOP, true);
				setBaseAnimation(ANIM_IDLE_BASE, true);
			}
			else
			{
				setTopAnimation(ANIM_RUN_TOP, true);
				setBaseAnimation(ANIM_RUN_BASE, true);
			}
		}
		
		return false;
	}
	
	return true;
}
