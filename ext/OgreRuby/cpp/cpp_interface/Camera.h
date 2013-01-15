#ifndef OGRE_INTERFACE_CAMERA
#define OGRE_INTERFACE_CAMERA


#include "OgreInterfaceBase.h"

#ifdef __cplusplus

#include "../cpp_core/GameApplication.h"

#endif /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

	Ogre_CameraPtr Ogre_Camera_new();
	void Ogre_Camera_delete(Ogre_CameraPtr obj);
	void Ogre_Camera_initialize(Ogre_CameraPtr obj, Ogre_WindowPtr obj2);


#ifdef __cplusplus
}
#endif


#endif /* OGRE_INTERFACE_CAMERA */