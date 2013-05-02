#ifndef ONI_ANIMATION_BONE_H
#define ONI_ANIMATION_BONE_H

#include "BaseApplication.h"

#include "OniAnimationBone.h"

namespace Oni
{
	class AnimationBone
	{
	public:
		AnimationBone();
		virtual ~AnimationBone();
		virtual void initialize(Ogre::Bone* bone);
		virtual void update(Ogre::Real deltaTime);
		
		// getOrientation();
		// getPosition();
		// pitch();
		// yaw();
		// roll();
		
	
	private:
		Ogre::Bone* mBone;
	};
}

#endif /* ONI_ANIMATION_BONE_H */