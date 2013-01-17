#include "Agent.h"

extern "C" {
	Ogre_AgentPtr Ogre_Agent_new(){
        Agent* agent = new Agent();
        
        return (Ogre_AgentPtr)agent;
    }
    
    void Ogre_Agent_delete(Ogre_AgentPtr obj){
        printf("======DELETING AGENT\n");
        Agent* agent = (Agent*)(obj);
        
        delete agent;
    }
    
    void Ogre_Agent_markgc(Ogre_AgentPtr obj){
        printf("======MARK FOR COLLECTION\n");
        Agent* agent = (Agent*)(obj);
        
        agent->setVisible(false);
    }
    
    void Ogre_Agent_initialize(Ogre_AgentPtr obj, Ogre_WindowPtr obj2, char* name, char* filename){
        Agent* agent = (Agent*)(obj);
        GameApplication* game = (GameApplication*)obj2;
        
        std::string cpp_name(name);
        std::string cpp_filename(filename);
        
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
    
    void Ogre_Agent_setPosition(Ogre_AgentPtr obj, double x, double y, double z){
        Agent* agent = (Agent*)(obj);
        
        agent->setPosition(x,y,z);
    }
    
    void Ogre_Agent_translate(Ogre_AgentPtr obj, double x, double y, double z){
        // void translate(Ogre::Real x, Ogre::Real y, Ogre::Real z, Ogre::Node::TransformSpace relativeTo=Ogre::Node::TS_PARENT);
        Agent* agent = (Agent*)(obj);
        
        agent->translate(x,y,z);
    }
    
    void Ogre_Agent_pitch(Ogre_AgentPtr obj, double radians){
        Agent* agent = (Agent*)(obj);
        
        agent->pitch(Ogre::Radian(radians));
    }
    
    void Ogre_Agent_yaw(Ogre_AgentPtr obj, double radians){
        Agent* agent = (Agent*)(obj);
        
        agent->yaw(Ogre::Radian(radians));
    }
    
    void Ogre_Agent_roll(Ogre_AgentPtr obj, double radians){
        Agent* agent = (Agent*)(obj);
        
        agent->roll(Ogre::Radian(radians));
    }
    
    void Ogre_Agent_rotateTo(Ogre_AgentPtr obj, double x, double y, double z){
        Agent* agent = (Agent*)(obj);

        agent->rotateTo(x,y,z);
    }
    
    void Ogre_Agent_setRotation(Ogre_AgentPtr obj, double radians){
        Agent* agent = (Agent*)(obj);
        
        agent->setHorizontalPlaneRotation(Ogre::Radian(radians));
    }
    
    char** Ogre_Agent_getAnimationNames(Ogre_AgentPtr obj){
        // DANGER:  Liable to be a source of memory leaks, as it allocates memory
        //          but expects the caller to deal with the consequences
        
        Agent* agent = (Agent*)(obj);
        
        Ogre::AnimationStateIterator iter = agent->getAnimationNames();
        
        int animation_count = 0;
        while (iter.hasMoreElements())
        {
            Ogre::AnimationState* a = iter.getNext();
            
            animation_count++;
        }
        
        // Can't know animation count at compile time
        // Must use dynamic memory allocation
        char** string_array = new char* [animation_count+1]; // Leave space for null at the end
        
        // Fill the array
        iter = agent->getAnimationNames();
        int i;
        for(i=0; iter.hasMoreElements(); i++)
        {
            Ogre::AnimationState* a = iter.getNext();
            
            std::string name = a->getAnimationName();
            
            char* cstr = new char [name.size()+1]; // Add one for the null terminator
            strcpy (cstr, name.c_str());

            string_array[i] = cstr;
        }
        
        // Set the last element in the array to NULL
        string_array[animation_count] = NULL;
        
        return string_array;
    }
    
    const char* Ogre_Agent_getBaseAnimation(Ogre_AgentPtr obj)
    {
        Agent* agent = (Agent*)(obj);
        
        return agent->getBaseAnimation().c_str();
    }
    
    const char* Ogre_Agent_getTopAnimation(Ogre_AgentPtr obj)
    {
        Agent* agent = (Agent*)(obj);
        
        return agent->getTopAnimation().c_str();
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