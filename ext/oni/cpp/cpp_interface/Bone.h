#ifndef ONI_INTERFACE_BONE
#define ONI_INTERFACE_BONE

#include "OgreInterfaceBase.h"

#ifdef __cplusplus

#include "../cpp_core/GameApplication.h"
#include "../cpp_core/OniBone.h"

#endif /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

	// Memory allocated by C++ level code, as this class should never be created at Ruby level
	// however, C++ level code has no need for this wrapper
	// so it should be discarded when Ruby no longer needs it
	void Oni_Bone_delete(Oni_BonePtr bone);
	void Oni_Bone_markgc(Oni_BonePtr obj);
	void Oni_Bone_update(Oni_BonePtr obj, double dt);

#ifdef __cplusplus
}
#endif


#endif /* ONI_INTERFACE_BONE */