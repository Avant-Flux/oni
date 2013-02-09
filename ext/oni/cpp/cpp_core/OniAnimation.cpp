#include "OniAnimation.h"

namespace Oni
{
	Animation::Animation(Oni::AbstractModel* model)
		: ModelDecorator(model)
	{
		
	}

	Animation::~Animation()
	{
		
	}

	void
	Animation::initialize(Ogre::SceneManager* sceneMgr, std::string& name, std::string& filename)
	{
		mTopAnimID = "";
		mBaseAnimID = "";
		
		mTimer = 0;
		
		setupAnimations();
	}

	void
	Animation::update(Ogre::Real deltaTime)
	{
		Oni::ModelDecorator::update(deltaTime);
		this->updateAnimations(deltaTime);
	}
	
	void 
	Animation::setupAnimations()
	{
		Ogre::Entity* entity = mDecoratedModel->getEntity();
		
		// this is very important due to the nature of the exported animations
		entity->getSkeleton()->setBlendMode(Ogre::ANIMBLEND_CUMULATIVE);
		
		// populate our animation list
		Ogre::AnimationStateSet* aSet = entity->getAllAnimationStates();
		Ogre::AnimationStateIterator iter = aSet->getAnimationStateIterator();
		while (iter.hasMoreElements())
		{
			Ogre::AnimationState* a = iter.getNext();
			
			mAnims[a->getAnimationName()] = a;
			a->setLoop(true);
			mFadingIn[a->getAnimationName()] = false;
			mFadingOut[a->getAnimationName()] = false;
		}
	}

	Ogre::AnimationStateIterator
	Animation::getAnimationNames()
	{
		Ogre::Entity* entity = mDecoratedModel->getEntity();
		
		Ogre::AnimationStateSet* aSet = entity->getAllAnimationStates();
		Ogre::AnimationStateIterator iter = aSet->getAnimationStateIterator();
		
		return iter;
	}

	void 
	Animation::setBaseAnimation(std::string id, bool reset)
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
	Animation::setTopAnimation(std::string id, bool reset)
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
	Animation::updateAnimations(Ogre::Real deltaTime)
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
	Animation::fadeAnimations(Ogre::Real deltaTime)
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
				// Fade speed is in additional weight per second
				Real newWeight = mAnims[key]->getWeight() + deltaTime * 7.5f; //ANIM_FADE_SPEED;
				// Insure weight is normalized
				mAnims[key]->setWeight(Math::Clamp<Real>(newWeight, 0, 1));	
				if (newWeight >= 1) mFadingIn[key] = false;
			}
			else if (mFadingOut[key])
			{
				// slowly fade this animation out until it has no weight, and then disable it
				Real newWeight = mAnims[key]->getWeight() - deltaTime * 7.5f; //ANIM_FADE_SPEED;
				// Insure weight is normalized
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
	Animation::getAnimationTime()
	{
		return mTimer;
	}

	void
	Animation::resetAnimationTime()
	{
		mTimer = 0;
	}
}