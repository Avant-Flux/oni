#include "agent.h"

VALUE Init_OgreAgent(VALUE outer){
	VALUE klass = rb_define_class_under(module, "Agent", rb_cObject);
	
	rb_define_method(klass, "initialize", initialize, -1);
}

static VALUE initialize(int argc, VALUE *argv, VALUE klass){
	// Ruby interface: Agent.new(window, "name", "name.mesh")
	
	// OGRE_TYPE Agent = Ogre_Agent(); // MUST free memory later
	
	
}

static VALUE finalize(int argc, VALUE *argv, VALUE klass){
	// Remove Agent from GameApplication collection
	// Free that element as it leaves the collection <-- can just use RAII
	// Set pointer to null
}



static VALUE setBaseAnimation(int argc, VALUE *argv, VALUE klass){
	Ogre_Agent_setBaseAnimation();
}

// Return list of animation names
// Return: array of strings
static VALUE animation_names(int argc, VALUE *argv, VALUE klass){
	
}