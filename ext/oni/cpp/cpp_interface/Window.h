#ifndef OGRE_INTERFACE_WINDOW
#define OGRE_INTERFACE_WINDOW


#include "OgreInterfaceBase.h"

#ifdef __cplusplus

#include "../cpp_core/GameApplication.h"

#endif /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

	void Ogre_cpp_test();
	
	Ogre_WindowPtr Ogre_Window_new(updateCallback update_callback, 
                                    keyDownCallback down_callback, keyUpCallback up_callback);
	void Ogre_Window_delete(Ogre_WindowPtr window);
	
	int Ogre_Window_run(Ogre_WindowPtr window);

#ifdef __cplusplus
}
#endif


#endif /* OGRE_INTERFACE_WINDOW */