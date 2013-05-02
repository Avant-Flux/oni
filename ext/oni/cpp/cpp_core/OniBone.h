#ifndef ONI_BONE_H
#define ONI_BONE_H

#include "BaseApplication.h"

#include "OniBone.h"

namespace Oni
{
	class Bone
	{
	public:
		Bone();
		virtual ~Bone();
		virtual void initialize(Ogre::Bone* bone);
		virtual void update(Ogre::Real deltaTime);
		
	
	private:
		Oni::Bone* mBone;
	};
}

#endif /* ONI_BONE_H */