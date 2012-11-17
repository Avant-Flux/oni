#include "agent.h"

VALUE Init_OgreAgent(VALUE outer){
	VALUE klass = rb_define_class_under(module, "Agent", rb_cObject);
	
	rb_define_method(klass, "initialize", initialize, -1);
}

static VALUE initialize(int argc, VALUE *argv, VALUE klass){
	OGRE_TYPE Agent = Ogre_Agent(); // MUST free memory later
}

static VALUE finalize(int argc, VALUE *argv, VALUE klass){
	
}



static VALUE setBaseAnimation(int argc, VALUE *argv, VALUE klass){
	Ogre_Agent_setBaseAnimation();
}

// Return list of animation names
// Return: array of strings
static VALUE animation_names(int argc, VALUE *argv, VALUE klass){
	
}