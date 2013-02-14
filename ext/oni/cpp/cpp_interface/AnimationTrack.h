#ifndef ONI_INTERFACE_ANIMATION_TRACK
#define ONI_INTERFACE_ANIMATION_TRACK

#include "OgreInterfaceBase.h"

#ifdef __cplusplus

#include "../cpp_core/GameApplication.h"
#include "../cpp_core/OniAnimationTrack.h"

#endif /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

	Oni_AnimationTrackPtr Oni_AnimationTrack_new();
	void Oni_AnimationTrack_delete(Oni_AnimationTrackPtr obj);
	void Oni_AnimationTrack_markgc(Oni_AnimationTrackPtr obj);
	void Oni_AnimationTrack_initialize(Oni_AnimationTrackPtr obj, Ogre_AnimationStatePtr obj2);
	void Oni_AnimationTrack_update(Oni_AnimationTrackPtr obj, double dt);
	
	

#ifdef __cplusplus
}
#endif


#endif /* ONI_INTERFACE_ANIMATION_TRACK */