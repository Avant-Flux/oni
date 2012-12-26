#ifndef OGRE_C_INTERFACE
#define OGRE_C_INTERFACE

#ifdef __cplusplus

#include "../cpp_core/GameApplication.h"
#include "../cpp_core/Agent.h"

#endif /* __cplusplus */


typedef void* Ogre_WindowPtr;
typedef void* Ogre_AgentPtr;



// Ogre::Window
#ifdef __cplusplus
extern "C" {
#endif
	void Ogre_cpp_test();
	
	Ogre_WindowPtr Ogre_Window_new();
	void Ogre_Window_delete(Ogre_WindowPtr window);

	int Ogre_Window_run(Ogre_WindowPtr window);
    
// Ogre::Agent
	Ogre_AgentPtr Ogre_Agent_new();
	void Ogre_Agent_delete(Ogre_AgentPtr agent);
	void Ogre_Agent_initialize(Ogre_AgentPtr obj, Ogre_WindowPtr obj2, char* name, char* filename);
	
	void Ogre_Agent_translate(Ogre_AgentPtr obj, double x, double y, double z);
	void Ogre_Agent_setBaseAnimation(Ogre_AgentPtr obj, char* id, int reset);

#ifdef __cplusplus
}
#endif
#endif /* OGRE_C_INTERFACE */