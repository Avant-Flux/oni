#include "Animation.h"

extern "C" {
	Oni_AnimationPtr Oni_Animation_new(Oni_ModelPtr model){
		Agent* agent = new Agent();

		return (Ogre_AgentPtr)agent;
	}

	void Oni_Animation_delete(Oni_AnimationPtr agent){
		printf("======DELETING AGENT\n");
		Agent* agent = (Agent*)(obj);

		delete agent;
	}

	void Oni_Animation_markgc(Oni_AnimationPtr obj){
		printf("======MARK FOR COLLECTION\n");
		Agent* agent = (Agent*)(obj);

		agent->setVisible(false);
	}

	void Oni_Animation_initialize(Oni_AnimationPtr obj, Ogre_WindowPtr obj2, char* name, char* filename){
		Agent* agent = (Agent*)(obj);
		GameApplication* game = (GameApplication*)obj2;

		std::string cpp_name(name);
		std::string cpp_filename(filename);

		agent->initialize(game->getSceneMgr(), cpp_name, cpp_filename);
	}

	void Oni_Animation_update(Oni_AnimationPtr obj, double dt){
		Agent* agent = (Agent*)(obj);

		agent->update(dt);
	}


	char** Oni_Animation_getAnimationNames(Oni_AnimationPtr obj){
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
	
	const char* Oni_Animation_getBaseAnimation(Oni_AnimationPtr obj){
		Agent* agent = (Agent*)(obj);
		
		return agent->getBaseAnimation().c_str();
	}

	void Oni_Animation_setBaseAnimation(Oni_AnimationPtr obj, char* id, int reset){
		Agent* agent = (Agent*)obj;
		
		std::string cpp_id(id); 
		agent->setBaseAnimation(cpp_id, reset);
	}

	const char* Oni_Animation_getTopAnimation(Oni_AnimationPtr obj){
		Agent* agent = (Agent*)(obj);
		
		return agent->getTopAnimation().c_str();
	}

	void Oni_Animation_setTopAnimation(Oni_AnimationPtr obj, char* id, int reset){
		Agent* agent = (Agent*)obj;
		
		std::string cpp_id(id); 
		agent->setTopAnimation(cpp_id, reset);
	}
}