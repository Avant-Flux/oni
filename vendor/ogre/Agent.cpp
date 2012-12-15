#include "Agent.h"

Agent::Agent(std::string name, std::string filename)
{
	using namespace Ogre;
	if (sceneMgr == NULL)
		return;

	mBodyNode = sceneMgr->getRootSceneNode()->createChildSceneNode();
	mBodyEntity = sceneMgr->createEntity(name, filename);
	mBodyNode->attachObject(mBodyEntity);

	mBodyNode->translate(0,5,0); // make the Ogre stand on the plane
	
	mDirection = Ogre::Vector3::ZERO;
	
	mTopAnimID = "";
	mBaseAnimID = "";
	
	mTimer = 0;
	
	setupAnimations();
	
	setTopAnimation("my_animation");
}

Agent::~Agent()
{
	
}

void
Agent::update(Ogre::Real deltaTime)
{
	this->updateAnimations(deltaTime);
	// this->updateLocomote(deltaTime);
}


void 
Agent::setupAnimations()
{
	// this is very important due to the nature of the exported animations
	mBodyEntity->getSkeleton()->setBlendMode(Ogre::ANIMBLEND_CUMULATIVE);
	
	// populate our animation list
	Ogre::AnimationStateSet* aSet = mBodyEntity->getAllAnimationStates();
	Ogre::AnimationStateIterator iter = aSet->getAnimationStateIterator();
	while (iter.hasMoreElements())
	{
		Ogre::AnimationState* a = iter.getNext();
		
		std::cout << "=======" << a->getAnimationName() << std::endl;
		
		mAnims[a->getAnimationName()] = a;
		a->setLoop(true);
		mFadingIn[a->getAnimationName()] = false;
		mFadingOut[a->getAnimationName()] = false;
	}

	// start off in the idle state (top and bottom together)
	//~ setIdleAnimation();

	// relax the hands since we're not holding anything
	//~ setHandsOpen();
}


void 
Agent::setBaseAnimation(std::string id, bool reset)
{
	if (mFadingIn.count(mBaseAnimID) > 0)
	{
		// if we have an old animation, fade it out
		mFadingIn[mBaseAnimID] = false;
		mFadingOut[mBaseAnimID] = true;
	}

	mBaseAnimID = id;

	if (mAnims.count(id) > 0)
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
Agent::setTopAnimation(std::string id, bool reset)
{
	if (mFadingIn.count(mTopAnimID) > 0)
	{
		// if we have an old animation, fade it out
		mFadingIn[mTopAnimID] = false;
		mFadingOut[mTopAnimID] = true;
	}

	mTopAnimID = id;

	if (mAnims.count(id) > 0)
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

	//~ if (this->mTimer >= (*mAnims)[mTopAnimID]->getLength())
	//~ {
		//~ 
	//~ }
	
	// increment the current base and top animation times
	// TODO: Refactor to better check existence of key
	// consider taking advantage of the fact that != 0 is true, and only one value can be stored per key
	if (mAnims.count(mBaseAnimID) > 0)
		mAnims[mBaseAnimID]->addTime(deltaTime * baseAnimSpeed);
	if (mAnims.count(mTopAnimID) > 0)
		mAnims[mTopAnimID]->addTime(deltaTime * topAnimSpeed);

	// apply smooth transitioning between our animations
	fadeAnimations(deltaTime);
}

void 
Agent::fadeAnimations(Ogre::Real deltaTime)
{
	using namespace Ogre;

	std::map<std::string, AnimationState*>::iterator iter;
	iter = mAnims.begin();
	for (int i = 0; i < mAnims.size(); i++)
	{
		std::string key = iter->first;
		iter++;
		
		if (mFadingIn[key])
		{
			// slowly fade this animation in until it has full weight
			Real newWeight = mAnims[key]->getWeight() + deltaTime * 7.5f; //ANIM_FADE_SPEED;
			mAnims[key]->setWeight(Math::Clamp<Real>(newWeight, 0, 1));
			if (newWeight >= 1) mFadingIn[key] = false;
		}
		else if (mFadingOut[key])
		{
			// slowly fade this animation out until it has no weight, and then disable it
			Real newWeight = mAnims[key]->getWeight() - deltaTime * 7.5f; //ANIM_FADE_SPEED;
			mAnims[key]->setWeight(Math::Clamp<Real>(newWeight, 0, 1));
			if (newWeight <= 0)
			{
				mAnims[key]->setEnabled(false);
				mFadingOut[key] = false;
			}
		}
	}
}

Ogre::Real
Agent::getAnimationTime()
{
	return mTimer;
}

void
Agent::resetAnimationTime()
{
	mTimer = 0;
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

// Position
void
Agent::setPosition(const Ogre::Vector3 &pos)
{
	mBodyNode->setPosition(pos);
}

void
Agent::setPosition(Ogre::Real x, Ogre::Real y, Ogre::Real z)
{
	mBodyNode->setPosition(x,y,z);
}


void
Agent::translate(const Ogre::Vector3 &d, Ogre::Node::TransformSpace relativeTo)
{
	// Moves the node along the Cartesian axes. 
	mBodyNode->translate(d, relativeTo);
}

void
Agent::translate(Ogre::Real x, Ogre::Real y, Ogre::Real z, Ogre::Node::TransformSpace relativeTo)
{
	// Moves the node along the Cartesian axes. 
	mBodyNode->translate(x,y,z, relativeTo);
}

void
Agent::translate(const Ogre::Matrix3 &axes, const Ogre::Vector3 &move, Ogre::Node::TransformSpace relativeTo)
{
	// Moves the node along arbitrary axes. 
	mBodyNode->translate(axes, move, relativeTo);
}

void
Agent::translate(const Ogre::Matrix3 &axes, Ogre::Real x, Ogre::Real y, Ogre::Real z, Ogre::Node::TransformSpace relativeTo)
{
	// Moves the node along arbitrary axes. 
	mBodyNode->translate(axes, x,y,z, relativeTo);
}
	


// Rotation
void
Agent::pitch(const Ogre::Radian &angle, Ogre::Node::TransformSpace relativeTo)
{
	
}

void
Agent::yaw(const Ogre::Radian &angle, Ogre::Node::TransformSpace relativeTo)
{
	
}

void
Agent::roll(const Ogre::Radian &angle, Ogre::Node::TransformSpace relativeTo)
{
	
}
