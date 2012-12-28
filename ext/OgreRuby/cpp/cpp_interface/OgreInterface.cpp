#include "OgreInterface.h"

extern "C" {
    void Ogre_cpp_test(){
        std::cout << "testing c++ level call" << std::endl;
    }

    
// Ogre::Window
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

// Ogre::Agent
    Ogre_AgentPtr Ogre_Agent_new(){
        Agent* agent = new Agent();
        
        return (Ogre_AgentPtr)agent;
    }
    
    void Ogre_Agent_delete(Ogre_AgentPtr obj){
        Agent* agent = (Agent*)(obj);
        
        delete agent;
    }
    
    void Ogre_Agent_initialize(Ogre_AgentPtr obj, Ogre_WindowPtr obj2, char* name, char* filename){
        Agent* agent = (Agent*)(obj);
        GameApplication* game = (GameApplication*)obj2;
        
        std::string cpp_name(name);
        std::string cpp_filename(filename);
        
        // std::cout << "==================" << name << " " << filename << std::endl;
        
        agent->initialize(game->getSceneMgr(), cpp_name, cpp_filename);
    }
    
    void Ogre_Agent_update(Ogre_AgentPtr obj, double dt){
        Agent* agent = (Agent*)(obj);
        
        agent->update(dt);
    }
    
    int Ogre_Agent_getVisible(Ogre_AgentPtr obj)
    {
        Agent* agent = (Agent*)(obj);
        
        if(agent->getVisible())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    
    void Ogre_Agent_setVisible(Ogre_AgentPtr obj, int visible)
    {
        Agent* agent = (Agent*)(obj);
        
        if(visible)
        {
            agent->setVisible(true);
        }
        else
        {
            agent->setVisible(false);
        }
    }
    
    void Ogre_Agent_translate(Ogre_AgentPtr obj, double x, double y, double z){
        // void translate(Ogre::Real x, Ogre::Real y, Ogre::Real z, Ogre::Node::TransformSpace relativeTo=Ogre::Node::TS_PARENT);
        Agent* agent = (Agent*)(obj);
        
        agent->translate(x,y,z);
    }
    
    void Ogre_Agent_setBaseAnimation(Ogre_AgentPtr obj, char* id, int reset){
        Agent* agent = (Agent*)obj;
        
        std::string cpp_id(id); 
        agent->setBaseAnimation(cpp_id, reset);
    }
    
    void Ogre_Agent_setTopAnimation(Ogre_AgentPtr obj, char* id, int reset){
        Agent* agent = (Agent*)obj;
        
        std::string cpp_id(id); 
        agent->setTopAnimation(cpp_id, reset);
    }
}
