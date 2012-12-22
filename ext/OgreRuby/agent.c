#include "agent.h"

VALUE Init_OgreAgent(VALUE outer){
	VALUE klass = rb_define_class_under(outer, "Agent", rb_cObject);
	
	rb_define_alloc_func(klass, alloc);
	
	rb_define_method(klass, "translate", translate, 3);
	
	rb_define_method(klass, "set_base_animation", setBaseAnimation, 0);
	rb_define_method(klass, "animation_names", animation_names, 1);
}

static VALUE alloc(VALUE class){
	// Ruby interface: Agent.new(window, "name", "name.mesh")
	
	// OGRE_TYPE Agent = Ogre_Agent(); // MUST free memory later
	Ogre_AgentPtr agent = Ogre_Agent_new("cube", "cube.mesh");
	VALUE data = Data_Wrap_Struct(class, NULL, Ogre_Agent_delete, agent);
	
	return data;
}

// static VALUE translate(int argc, VALUE *argv, VALUE self){
static VALUE translate(VALUE self, VALUE x, VALUE y, VALUE z){
	Ogre_AgentPtr ptr;
	Data_Get_Struct(self, Ogre_AgentPtr, ptr);
	
	double pos_x = NUM2DBL(x);
	double pos_y = NUM2DBL(y);
	double pos_z = NUM2DBL(z);
	
	Ogre_Agent_translate(ptr, pos_x, pos_y, pos_z);
}

static VALUE setBaseAnimation(int argc, VALUE *argv, VALUE self){
	Ogre_AgentPtr ptr;
	Data_Get_Struct(self, Ogre_AgentPtr, ptr);
	
	Ogre_Agent_setBaseAnimation(ptr, "", 0);
	
	return Qnil;
}

// Return list of animation names
// Return: array of strings
static VALUE animation_names(int argc, VALUE *argv, VALUE self){
	return Qnil;
}