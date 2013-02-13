#ifndef ONI_ANIMATION_H
#define ONI_ANIMATION_H

#include "BaseApplication.h"
#include "OniModel.h"

#include <deque>

namespace Oni
{
	class Animation
	{
	public:
		Animation();
		virtual ~Animation();
		virtual void initialize(Oni::Model* model);
		virtual void update(Ogre::Real deltaTime);		// update the agent
				
		Ogre::AnimationStateIterator getAnimationNames();
		
		std::string getBaseAnimation(){return mBaseAnimID;};
		void setBaseAnimation(std::string id, bool reset = false);
		void setTopAnimation(std::string id, bool reset = false);
		std::string getTopAnimation(){return mTopAnimID;};
		void fadeAnimations(Ogre::Real deltaTime);
		
		// Time
		Ogre::Real getAnimationTime();			// Get the current animation timer
		void resetAnimationTime();

	protected:
		std::map<std::string, Ogre::AnimationState*> mAnims; // master animation list
		std::map<std::string, bool> mFadingIn;	// which animations are fading in
		std::map<std::string, bool> mFadingOut;	// which animations are fading out
		std::string mBaseAnimID;				// current base (full- or lower-body) animation
		std::string mTopAnimID;					// current top (upper-body) animation
		Ogre::Real mTimer;						// general timer to see how long animations have been playing
			
	private:
		Oni::Model* mModel;

		// all of the animations our character has, and a null ID
		// some of these affect separate body parts and will be blended together
	};
}

#endif /* ONI_ANIMATION_H */