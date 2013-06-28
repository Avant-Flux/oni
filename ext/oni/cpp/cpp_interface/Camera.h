#ifndef OGRE_INTERFACE_CAMERA
#define OGRE_INTERFACE_CAMERA


#include "OgreInterfaceBase.h"

#ifdef __cplusplus

#include "../cpp_core/GameApplication.h"

#endif /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif
	
	typedef enum { ORTHOGRAPHIC, PERSPECTIVE } OniCameraProjectionType; 
	
	Ogre_CameraPtr Ogre_Camera_new(Ogre_WindowPtr window, char* name);
	void Ogre_Camera_delete(Ogre_CameraPtr obj);
	void Ogre_Camera_initialize(Ogre_CameraPtr obj, Ogre_WindowPtr obj2, int z_order);
	
	void Ogre_Camera_setPosition(Ogre_CameraPtr obj, double x, double y, double z);
	void Ogre_Camera_lookAt(Ogre_CameraPtr obj, double x, double y, double z);
	
	double Ogre_Camera_getNearClipDistance(Ogre_CameraPtr obj);
	void Ogre_Camera_setNearClipDistance(Ogre_CameraPtr obj, double distance);
	
	void Ogre_Camera_setProjectionType(Ogre_CameraPtr obj, OniCameraProjectionType type);
	
	// Perspective camera only
	double Ogre_Camera_getFOV(Ogre_CameraPtr obj);
	void Ogre_Camera_setFOV(Ogre_CameraPtr obj, double x_angle);
	
	// Ortho camera only
	void Ogre_Camera_setOrthoWindow(Ogre_CameraPtr obj, double w, double h);
	void Ogre_Camera_setOrthoWindowHeight(Ogre_CameraPtr obj, double h);
	void Ogre_Camera_setOrthoWindowWidth(Ogre_CameraPtr obj, double w);
	double Ogre_Camera_getOrthoWindowHeight(Ogre_CameraPtr obj);
	double Ogre_Camera_getOrthoWindowWidth(Ogre_CameraPtr obj);
	

#ifdef __cplusplus
}
#endif


#endif /* OGRE_INTERFACE_CAMERA */