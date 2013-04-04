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
	void Oni_Light_initialize(Oni_LightPtr obj, Ogre_WindowPtr obj2, char* name);
	void Oni_Light_update(Oni_LightPtr obj, double dt);
	
	int Oni_Light_getVisible(Oni_LightPtr obj);
	void Oni_Light_setVisible(Oni_LightPtr obj, int visible);
	
	void Oni_Light_setType(Oni_LightPtr obj, int light_type);
	int Oni_Light_getType(Oni_LightPtr obj);
	
	void Oni_Light_setPosition(Oni_LightPtr obj, double x, double y, double z);
	void Oni_Light_getPosition(Oni_LightPtr obj, double* position);
	
	void Oni_Light_setDirection(Oni_LightPtr obj, double x, double y, double z);
	void Oni_Light_getDirection(Oni_LightPtr ob, double* direction);
	
	void Oni_Light_setDiffuseColor(Oni_LightPtr obj, double r, double g, double b);
	void Oni_Light_setSpecularColor(Oni_LightPtr obj, double r, double g, double b);
	
	void Oni_Light_setAttenuation(Oni_LightPtr obj, double range, double constant, double linear, double quadratic);
	
	void Oni_Light_setPowerScale(Oni_LightPtr obj, double power);
	
	void Oni_Light_setShadowFarDistance(Oni_LightPtr obj, double distance);
	void Oni_Light_resetShadowFarDistance(Oni_LightPtr obj);
	double Oni_Light_getShadowFarDistance(Oni_LightPtr obj);
	double Oni_Light_getShadowFarDistanceSquared(Oni_LightPtr obj);
	
	void Oni_Light_setShadowNearClipDistance(Oni_LightPtr obj, double nearClip);
	double Oni_Light_getShadowNearClipDistance(Oni_LightPtr obj);
	void Oni_Light_setShadowFarClipDistance(Oni_LightPtr obj, double farClip);
	double Oni_Light_getShadowFarClipDistance(Oni_LightPtr obj);

#ifdef __cplusplus
}
#endif


#endif /* ONI_INTERFACE_LIGHT */