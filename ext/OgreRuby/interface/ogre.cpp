#include "ogre.hpp"
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
