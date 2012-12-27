#include "agent.h"

VALUE Init_OgreAgent(VALUE outer){
	VALUE klass = rb_define_class_under(outer, "Agent", rb_cObject);
	
	rb_define_alloc_func(klass, alloc);
	rb_define_method(klass, "initialize", initialize, 3);
	rb_define_method(klass, "update", update, 1);
	
	rb_define_method(klass, "visible=", setVisible, 1);
	
	rb_define_method(klass, "translate", translate, 3);
	
	rb_define_method(klass, "set_base_animation", setBaseAnimation, 0);
	rb_define_method(klass, "animation_names", animation_names, 1);
}

static VALUE alloc(VALUE class){
	// Ruby interface: Agent.new(window, "name", "name.mesh")
	
	// OGRE_TYPE Agent = Ogre_Agent(); // MUST free memory later
	Ogre_AgentPtr agent = Ogre_Agent_new();
	VALUE data = Data_Wrap_Struct(class, NULL, Ogre_Agent_delete, agent);
	
	return data;
}

static VALUE initialize(VALUE self, VALUE window, VALUE name, VALUE filename){	
	Ogre_AgentPtr ptr_agent;
	Data_Get_Struct(self, Ogre_AgentPtr, ptr_agent);
	
	Ogre_WindowPtr ptr_window;
	Data_Get_Struct(window, Ogre_WindowPtr, ptr_window);
	
	char* string_name = StringValueCStr(name);
	char* string_filename = StringValueCStr(filename);
	
	Ogre_Agent_initialize(ptr_agent, ptr_window, string_name, string_filename);
	
	return Qnil;
}

static VALUE update(VALUE self, VALUE dt){
	Ogre_AgentPtr ptr_agent;
	Data_Get_Struct(self, Ogre_AgentPtr, ptr_agent);
	
	double double_dt = NUM2DBL(dt);
	
	Ogre_Agent_update(ptr_agent, double_dt);
}

static VALUE setVisible(VALUE self, VALUE visible)
{
	Ogre_AgentPtr ptr_agent;
	Data_Get_Struct(self, Ogre_AgentPtr, ptr_agent);
	
	Ogre_Agent_setVisible(ptr_agent, RTEST(visible));
	
	return Qnil;
}

static VALUE translate(VALUE self, VALUE x, VALUE y, VALUE z){
	Ogre_AgentPtr ptr;
	Data_Get_Struct(self, Ogre_AgentPtr, ptr);
	
	double pos_x = NUM2DBL(x);
	double pos_y = NUM2DBL(y);
	double pos_z = NUM2DBL(z);
	
	Ogre_Agent_translate(ptr, pos_x, pos_y, pos_z);
	
	return Qnil;
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