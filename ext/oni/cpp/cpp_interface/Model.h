#ifndef ONI_INTERFACE_MODEL
#define ONI_INTERFACE_MODEL

#include "OgreInterfaceBase.h"

#ifdef __cplusplus

#include "../cpp_core/GameApplication.h"
#include "../cpp_core/OniModel.h"

#endif /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

	Oni_ModelPtr Oni_Model_new();
	void Oni_Model_delete(Oni_ModelPtr model);
	void Oni_Model_markgc(Oni_ModelPtr obj);
	void Oni_Model_initialize(Oni_ModelPtr obj, Ogre_WindowPtr obj2, char* name, char* filename);
	void Oni_Model_update(Oni_ModelPtr obj, double dt);
	
	int Oni_Model_getVisible(Oni_ModelPtr obj);
	void Oni_Model_setVisible(Oni_ModelPtr obj, int visible);
	
	void Oni_Model_setPosition(Oni_ModelPtr obj, double x, double y, double z);
	void Oni_Model_translate(Oni_ModelPtr obj, double x, double y, double z);
	
	void Oni_Model_pitch(Oni_ModelPtr obj, double radians);
	void Oni_Model_yaw(Oni_ModelPtr obj, double radians);
	void Oni_Model_roll(Oni_ModelPtr obj, double radians);
	
	// Rotate to face the given vector - DEPRECIATED
	void Oni_Model_rotateTo(Oni_ModelPtr obj, double x, double y, double z);
	
	// Set rotation in horizontal plane
	void Oni_Model_setRotation(Oni_ModelPtr obj, double radians);
	
	void Oni_Model_scale(Oni_ModelPtr obj, double x, double y, double z);
	void Oni_Model_setScale(Oni_ModelPtr obj, double x, double y, double z);

#ifdef __cplusplus
}
#endif


#endif /* ONI_INTERFACE_MODEL */