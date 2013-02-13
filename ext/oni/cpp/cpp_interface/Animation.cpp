#include "Animation.h"

extern "C" {
	Oni_AnimationPtr Oni_Animation_new(){
		Oni::Animation* animation = new Oni::Animation();
		
		return (Oni_AnimationPtr)animation;
	}

	void Oni_Animation_delete(Oni_AnimationPtr obj){
		printf("======DELETING AGENT\n");
		Oni::Animation* animation = (Oni::Animation*)(obj);
		
		delete animation;
	}

	void Oni_Animation_markgc(Oni_AnimationPtr obj){
		printf("======MARK FOR COLLECTION\n");
		Oni::Animation* animation = (Oni::Animation*)(obj);
		
	}

	void Oni_Animation_initialize(Oni_AnimationPtr obj, Oni_ModelPtr obj2){
		Oni::Animation* animation = (Oni::Animation*)(obj);
		Oni::Model* model = (Oni::Model*)(obj2);
		
		animation->initialize(model);
	}

	void Oni_Animation_update(Oni_AnimationPtr obj, double dt){
		Oni::Animation* animation = (Oni::Animation*)(obj);
		
		animation->update(dt);
	}


	char** Oni_Animation_getAnimationNames(Oni_AnimationPtr obj){
		// DANGER:  Liable to be a source of memory leaks, as it allocates memory
		//          but expects the caller to deal with the consequences
		
		Oni::Animation* animation = (Oni::Animation*)(obj);
		
		Ogre::AnimationStateIterator iter = animation->getAnimationNames();
		
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
		iter = animation->getAnimationNames();
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
		Oni::Animation* animation = (Oni::Animation*)(obj);
		
		return animation->getBaseAnimation().c_str();
	}

	void Oni_Animation_setBaseAnimation(Oni_AnimationPtr obj, char* id, int reset){
		Oni::Animation* animation = (Oni::Animation*)(obj);
		
		std::string cpp_id(id); 
		animation->setBaseAnimation(cpp_id, reset);
	}

	const char* Oni_Animation_getTopAnimation(Oni_AnimationPtr obj){
		Oni::Animation* animation = (Oni::Animation*)(obj);
		
		return animation->getTopAnimation().c_str();
	}

	void Oni_Animation_setTopAnimation(Oni_AnimationPtr obj, char* id, int reset){
		Oni::Animation* animation = (Oni::Animation*)(obj);
		
		std::string cpp_id(id); 
		animation->setTopAnimation(cpp_id, reset);
	}
}