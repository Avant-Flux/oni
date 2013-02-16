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

	void Oni_Animation_Track_update(Oni_Animation_TrackPtr obj, double dt);
	
	

#ifdef __cplusplus
}
#endif


#endif /* ONI_INTERFACE_ANIMATION_TRACK */