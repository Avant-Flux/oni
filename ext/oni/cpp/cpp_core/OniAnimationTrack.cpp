#include "OniAnimationTrack.h"

namespace Oni
{
	AnimationTrack::AnimationTrack()
	{
		
	}

	AnimationTrack::~AnimationTrack()
	{
		
	}
	
	void
	AnimationTrack::initialize(Ogre::AnimationState* state)
	{
		mAnimationState = state;
	}
	
	void
	AnimationTrack::update(Ogre::Real deltaTime)
	{
		mAnimationState->addTime(deltaTime * mPlaybackRate);
		
		Ogre::Real blendRate = 7.5f;
		
		// Control fading
		if(mFadeInTime > 0)
		{
			// slowly fade this animation in until it has full weight
			// Fade speed is in additional weight per second
			Ogre::Real newWeight = mAnimationState->getWeight() + deltaTime * blendRate; //ANIM_FADE_SPEED;
			// Insure weight is normalized
			mAnimationState->setWeight(Ogre::Math::Clamp<Ogre::Real>(newWeight, 0, 1));	
			if (newWeight >= 1) mFadeInTime = 0;
		}
		else if (mFadeOutTime > 0)
		{
			// slowly fade this animation out until it has no weight, and then disable it
			Ogre::Real newWeight = mAnimationState->getWeight() - deltaTime * blendRate; //ANIM_FADE_SPEED;
			// Insure weight is normalized
			mAnimationState->setWeight(Ogre::Math::Clamp<Ogre::Real>(newWeight, 0, 1));
			if (newWeight <= 0)
			{
				mAnimationState->setEnabled(false);
				mFadeOutTime = 0;
			}
		}
	}
	
	// Accessors and Mutators
	void
	AnimationTrack::setPlaybackRate(Ogre::Real rate)
	{
		mPlaybackRate = rate;
	}
	
	Ogre::Real
	AnimationTrack::getPlaybackRate()
	{
		return mPlaybackRate;
	}
}