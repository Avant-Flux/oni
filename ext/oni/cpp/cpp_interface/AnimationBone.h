#ifndef ONI_INTERFACE_ANIMATION_BONE
#define ONI_INTERFACE_ANIMATION_BONE

#include "OgreInterfaceBase.h"

#ifdef __cplusplus

#include "../cpp_core/GameApplication.h"
#include "../cpp_core/OniAnimationBone.h"

#endif /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

	// Memory allocated by C++ level code, as this class should never be created at Ruby level
	// however, C++ level code has no need for this wrapper
	// so it should be discarded when Ruby no longer needs it
	void Oni_Animation_Bone_delete(Oni_Animation_BonePtr bone);
	void Oni_Animation_Bone_markgc(Oni_Animation_BonePtr obj);
	void Oni_Animation_Bone_update(Oni_Animation_BonePtr obj, double dt);

#ifdef __cplusplus
}
#endif


#endif /* ONI_INTERFACE_ANIMATION_BONE */