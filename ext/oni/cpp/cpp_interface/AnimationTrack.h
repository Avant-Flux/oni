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

	Oni_Animation_TrackPtr Oni_Animation_Track_new();
	void Oni_Animation_Track_delete(Oni_Animation_TrackPtr obj);
	void Oni_Animation_Track_markgc(Oni_Animation_TrackPtr obj);
	void Oni_Animation_Track_initialize(Oni_Animation_TrackPtr obj, Ogre_AnimationStatePtr obj2);
	void Oni_Animation_Track_update(Oni_Animation_TrackPtr obj, double dt);
	
	

#ifdef __cplusplus
}
#endif


#endif /* ONI_INTERFACE_ANIMATION_TRACK */