#ifndef OGRE_INTERFACE_AGENT
#define OGRE_INTERFACE_AGENT


#include "OgreInterfaceBase.h"

#ifdef __cplusplus

#include "../cpp_core/GameApplication.h"
#include "../cpp_core/Agent.h"

#endif /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

	Ogre_AgentPtr Ogre_Agent_new();
	void Ogre_Agent_delete(Ogre_AgentPtr agent);
	void Ogre_Agent_markgc(Ogre_AgentPtr obj);
	void Ogre_Agent_initialize(Ogre_AgentPtr obj, Ogre_WindowPtr obj2, char* name, char* filename);
	void Ogre_Agent_update(Ogre_AgentPtr obj, double dt);
	
	int Ogre_Agent_getVisible(Ogre_AgentPtr obj);
	void Ogre_Agent_setVisible(Ogre_AgentPtr obj, int visible);
	
	void Ogre_Agent_setPosition(Ogre_AgentPtr obj, double x, double y, double z);
	void Ogre_Agent_translate(Ogre_AgentPtr obj, double x, double y, double z);
	
	void Ogre_Agent_pitch(Ogre_AgentPtr obj, double radians);
	void Ogre_Agent_yaw(Ogre_AgentPtr obj, double radians);
	void Ogre_Agent_roll(Ogre_AgentPtr obj, double radians);
	
	// Rotate to face the given vector - DEPRECIATED
	void Ogre_Agent_rotateTo(Ogre_AgentPtr obj, double x, double y, double z);
	
	// Set rotation in horizontal plane
	void Ogre_Agent_setRotation(Ogre_AgentPtr obj, double radians);
	
	char** Ogre_Agent_getAnimationNames(Ogre_AgentPtr obj);
	
	const char* Ogre_Agent_getBaseAnimation(Ogre_AgentPtr obj);
	void Ogre_Agent_setBaseAnimation(Ogre_AgentPtr obj, char* id, int reset);
	const char* Ogre_Agent_getTopAnimation(Ogre_AgentPtr obj);
	void Ogre_Agent_setTopAnimation(Ogre_AgentPtr obj, char* id, int reset);

#ifdef __cplusplus
}
#endif


#endif /* OGRE_INTERFACE_AGENT */