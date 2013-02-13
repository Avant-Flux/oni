#ifndef ONI_INTERFACE_MODEL
#define ONI_INTERFACE_MODEL

#include "OgreInterfaceBase.h"

#ifdef __cplusplus

#include "../cpp_core/GameApplication.h"
#include "../cpp_core/OniModel.h"
#include "../cpp_core/OniAnimation.h"

#endif /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

	Oni_AnimationPtr Oni_Animation_new();
	void Oni_Animation_delete(Oni_AnimationPtr agent);
	void Oni_Animation_markgc(Oni_AnimationPtr obj);
	void Oni_Animation_initialize(Oni_AnimationPtr obj, Oni_ModelPtr obj2);
	void Oni_Animation_update(Oni_AnimationPtr obj, double dt);
	
	char** Oni_Animation_getAnimationNames(Oni_AnimationPtr obj);
	
	const char* Oni_Animation_getBaseAnimation(Oni_AnimationPtr obj);
	void Oni_Animation_setBaseAnimation(Oni_AnimationPtr obj, char* id, int reset);
	const char* Oni_Animation_getTopAnimation(Oni_AnimationPtr obj);
	void Oni_Animation_setTopAnimation(Oni_AnimationPtr obj, char* id, int reset);

#ifdef __cplusplus
}
#endif


#endif /* ONI_INTERFACE_MODEL */