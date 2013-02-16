#ifndef ONI_ANIMATION_H
#define ONI_ANIMATION_H

#include "BaseApplication.h"
#include "OniModel.h"

#include "OniAnimationTrack.h"

#include <deque>

namespace Oni
{
	class Animation
	{
	public:
		Animation();
		virtual ~Animation();
		virtual void initialize(Oni::Model* model);
		virtual void update(Ogre::Real deltaTime);
				
		Ogre::AnimationStateIterator getAnimationNames();
		
		Oni::AnimationTrack* getAnimationTrack(std::string name);
		
		void setBaseAnimation(std::string id, bool reset = false);
		std::string getBaseAnimation(){return "mBaseAnimID";};
		void setTopAnimation(std::string id, bool reset = false);
		std::string getTopAnimation(){return "mTopAnimID";};
	
	private:
		Oni::Model* mModel;

		std::map<std::string, Oni::AnimationTrack*> mAnims; // TODO: Try to make values non-pointers
		// all of the animations our character has, and a null ID
		// some of these affect separate body parts and will be blended together
	};
}

#endif /* ONI_ANIMATION_H */