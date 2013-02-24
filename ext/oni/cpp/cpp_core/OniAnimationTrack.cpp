#include "OniAnimationTrack.h"

namespace Oni
{
	AnimationTrack::AnimationTrack()
	{
		mPlaybackRate = 1.0;
		mFadeInTime = 0.0f;
		mFadeOutTime = 0.0f;
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
		if(mAnimationState->getEnabled())
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
				
				// Stop blending if at any time the value becomes 1
				if (newWeight == 1) mFadeInTime = 0;
			}
			else if (mFadeOutTime > 0)
			{
				// slowly fade this animation out until it has no weight, and then disable it
				Ogre::Real newWeight = mAnimationState->getWeight() - deltaTime * blendRate; //ANIM_FADE_SPEED;
				// Insure weight is normalized
				mAnimationState->setWeight(Ogre::Math::Clamp<Ogre::Real>(newWeight, 0, 1));
				
				// Stop blending if at any time the value becomes 0
				if (newWeight == 0)
				{
					mAnimationState->setEnabled(false);
					mFadeOutTime = 0;
				}
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
	
	void
	AnimationTrack::setFadeInTime(Ogre::Real fadeTime)
	{
		mFadeInTime = fadeTime;
	}
	
	void
	AnimationTrack::setFadeOutTime(Ogre::Real fadeTime)
	{
		mFadeOutTime = fadeTime;
	}
}