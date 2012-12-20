#include "OgreInterface.h"

#ifdef __cplusplus
extern "C" {
#endif

// Ogre::Window
    Ogre_WindowPtr Ogre_Window_new(){
        GameApplication* game = new GameApplication();
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

// Ogre::Agent
    Ogre_AgentPtr Ogre_Agent_new(char* name, char* filename){
        
        std::string cpp_name(name); 
        std::string cpp_filename(filename);
        
        return (Ogre_AgentPtr) new Agent(cpp_name, cpp_filename);
    }
    
    void Ogre_Agent_delete(Ogre_AgentPtr agent){
        Agent* obj = (Agent*)(agent);
        
        delete obj;
    }
    
    void Ogre_Agent_setBaseAnimation(Ogre_AgentPtr obj, char* id, int reset){
        Agent* agent = (Agent*)obj;
        
        std::string cpp_id(id); 
        agent->setBaseAnimation(cpp_id, reset);
    }

#ifdef __cplusplus
}
#endif


/*
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
// #include "windows.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif


    {
       
    }

#ifdef __cplusplus
}
#endif
*/


/*
x = OgreWindow.new
    x.setup <-- setup should be called by OgreWindow.new at the C level
x.show

*/