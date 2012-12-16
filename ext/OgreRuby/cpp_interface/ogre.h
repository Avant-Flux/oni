#ifndef OGRE_C_INTERFACE
#define OGRE_C_INTERFACE

#ifdef __cplusplus

#include <Agent.h>

#endif /* __cplusplus */


typedef void* Ogre_WindowPtr;
typedef void* Ogre_AgentPtr;



// Ogre::Window
#ifdef __cplusplus
extern "C" {
#endif
	Ogre_WindowPtr Ogre_Window_new();
	void Ogre_Window_delete(Ogre_WindowPtr window);

	void Ogre_Window_run(Ogre_WindowPtr window);
    
// Ogre::Agent
	Ogre_AgentPtr Ogre_Agent_new();
	void Ogre_Agent_delete(Ogre_AgentPtr agent);
	
	void Ogre_Agent_setBaseAnimation(Ogre_AgentPtr obj, std::string id, bool reset = false);
	void Ogre_Agent_addTime(Ogre_AgentPtr agent, double dt);

#ifdef __cplusplus
}
#endif
#endif /* OGRE_C_INTERFACE */