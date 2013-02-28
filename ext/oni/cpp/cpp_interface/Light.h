#ifndef ONI_INTERFACE_LIGHT
#define ONI_INTERFACE_LIGHT

#include "OgreInterfaceBase.h"

#ifdef __cplusplus

#include "../cpp_core/GameApplication.h"
#include "../cpp_core/OniLight.h"

#endif /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

	Oni_LightPtr Oni_Light_new();
	void Oni_Light_delete(Oni_LightPtr obj);
	void Oni_Light_markgc(Oni_LightPtr obj);
	void Oni_Light_initialize(Oni_LightPtr obj, Ogre_WindowPtr obj2);
	void Oni_Light_update(Oni_LightPtr obj, double dt);

#ifdef __cplusplus
}
#endif


#endif /* ONI_INTERFACE_LIGHT */