#include "Window.h"

extern "C" {
	Ogre_WindowPtr Ogre_Window_new(updateCallback update_callback, 
                                    keyDownCallback down_callback, keyUpCallback up_callback){
        GameApplication* game = new GameApplication(update_callback, down_callback, up_callback);
        std::cout << "START NEW WINDOW" << std::endl;
        bool carryOn = game->setup();
        
        if(!carryOn)
        {
            delete game;
            return NULL;
        }
        
        return (Ogre_WindowPtr)game;
    }
    
    void Ogre_Window_delete(Ogre_WindowPtr window){
        GameApplication* game = (GameApplication*)window;
        delete game;
    }
    
    int Ogre_Window_run(Ogre_WindowPtr window){
        GameApplication* game = (GameApplication*)(window);
        
        try {
            game->go();
        } catch( Ogre::Exception& e ) {
            #if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
                MessageBox( NULL, e.getFullDescription().c_str(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
            #else
                std::cerr << "An exception has occured: " <<
                    e.getFullDescription().c_str() << std::endl;
            #endif
        }

        return 0;
    }
}