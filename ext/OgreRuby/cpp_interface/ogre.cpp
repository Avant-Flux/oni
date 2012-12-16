#include "ogre.h"
// This is C++ code

// Declare f(int,char,float) using extern "C":
extern "C" void f(int i, char c, float x);

// Define f(int,char,float) in some C++ module:
void f(int i, char c, float x)
{
	
}

// Functions wrapped this way need to return values that C can understand.
// Thus, this package CAN NOT wrap functions which return pointers to
// class instances, etc.  All of that needs to be written in C++, and just
// wrapped.

// If you want to create an instance of a class through scripting, 
// the C++ needs to manage the entire lifecycle of that class by itself.


// Transformations of C++ objects need to written in C style.
// Thus, if I want to write a script handle for a method foo for class Object
// aka Object::foo(), then it needs to be something like..
void TestSpace::test(Object* o, void* function, void* argv, void * arga){
	// An interface like this would be ideal, as it would allow calling
	// any and all methods of a class with minimal glue code.
	
	// Though perhaps that's bad, because it wrecks encapsulation?
}

Agent* a = new Agent("sinbad", "sinbad.mesh", NULL);


#ifdef __cplusplus
extern "C" {
#endif

// Ogre::Window
    Ogre_Window Ogre_Window_new(){
        GameApplication game = new GameApplication;
        return (Ogre_Window)game;
    }
    
    void Ogre_Window_delete(Ogre_Window window){
        delete window;
    }
    
    void Ogre_Window_addTime(Ogre_Window window){
        Ogre::Window* obj = (Ogre::Window*)(window);
        
        obj->addTime();        
    }

// Ogre::Agent
    Ogre_Agent Ogre_Agent_new(){
        
    }
    
    void Ogre_Agent_delete(Ogre_Agent agent){
        Ogre::Agent* obj = (Ogre::Agent*)(agent);
        
        delete obj;
    }
    
    void Ogre_Agent_addTime(Ogre_Agent agent, double dt){
        Ogre::Agent* obj = (Ogre::Agent*)(agent);
        
        obj->addTime(dt);
    }

#ifdef __cplusplus
}
#endif









// Must return a type that C can understand, so all objects get returned as void* instead
// TODO: Consider sanitizing inputs (similar to SQL)
extern "C" void* Agent::setBaseAnimation(AnimID id, bool reset = false){
	
}


extern "C" OGRE_TYPE Ogre_Agent(){
	return (OGRE_TYPE) new Agent();
}

extern "C" OGRE_TYPE Ogre_Agent(){
	return (OGRE_TYPE) new Agent();
}

extern "C" OGRE_TYPE Ogre_Agent_setBaseAnimation(OGRE_TYPE* obj, AnimID id, bool reset = false){
	Agent* agent = (Agent* )obj;
	agent->setBaseAnimation(id, reset);
}





GameApplication* createGameWindow()
{
    return new GameApplication();
}

void destroyGameWindow(GameApplication* window)
{
    delete window;
}

void runGame(GameApplication& window)
{
    
}




extern "C" {
    typedef void* OGRE_WINDOW;
    
    OGRE_WINDOW Ogre_create_window()
    {
        return (OGRE_WINDOW)(createGameWindow());
    }
    
    void Ogre_run_game(OGRE_WINDOW window)
    {
        runGame((GameApplication*)(window));
    }
}




#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
// #include "windows.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif


    {
        // Create application object
        GameApplication app;

        try {
            app->go();
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

#ifdef __cplusplus
}
#endif


/*
x = OgreWindow.new
    x.setup <-- setup should be called by OgreWindow.new at the C level
x.show

*/