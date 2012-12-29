#include "agent.h"

VALUE Init_OgreAgent(VALUE outer){
	VALUE klass = rb_define_class_under(outer, "Agent", rb_cObject);
	
	rb_define_alloc_func(klass, alloc);
	rb_define_method(klass, "initialize", initialize, 3);
	rb_define_method(klass, "update", update, 1);
	
	rb_define_method(klass, "visible=", setVisible, 1);
	rb_define_method(klass, "visible", getVisible, 0);
	
	rb_define_method(klass, "translate", translate, 3);
	
	rb_define_method(klass, "base_animation", getBaseAnimation, 0);
	rb_define_method(klass, "top_animation", getTopAnimation, 0);
	rb_define_method(klass, "base_animation=", setBaseAnimation, -1);
	rb_define_method(klass, "top_animation=", setTopAnimation, -1);
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

static VALUE getVisible(VALUE self)
{
	Ogre_AgentPtr ptr_agent;
	Data_Get_Struct(self, Ogre_AgentPtr, ptr_agent);
	
	if(Ogre_Agent_getVisible(ptr_agent))
	{
		return Qtrue;
	}
	else
	{
		return Qfalse;
	}
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

static VALUE getBaseAnimation(VALUE self)
{
	Ogre_AgentPtr ptr_agent;
	Data_Get_Struct(self, Ogre_AgentPtr, ptr_agent);
	
	const char* str_animation_name = Ogre_Agent_getBaseAnimation(ptr_agent);
	
	VALUE name = rb_str_new2(str_animation_name);
	
	return name;
}

static VALUE getTopAnimation(VALUE self)
{
	Ogre_AgentPtr ptr_agent;
	Data_Get_Struct(self, Ogre_AgentPtr, ptr_agent);
	
	const char* str_animation_name = Ogre_Agent_getTopAnimation(ptr_agent);
	
	VALUE name = rb_str_new2(str_animation_name);
	
	return name;
}

static VALUE setBaseAnimation(int argc, VALUE *argv, VALUE self){
	Ogre_AgentPtr ptr_agent;
	Data_Get_Struct(self, Ogre_AgentPtr, ptr_agent);
	
	VALUE name;
	VALUE reset;
	if(argc == 1)
	{
		// Set default for "reset"
		name = argv[0];
		reset = Qfalse;
	}
	else if(argc == 2)
	{
		// Use provided "reset" value
		name = argv[0];
		reset = argv[1];
	}
	else
	{
		rb_raise(rb_eArgError, "ERROR: Argument mismatch - Agent#base_animation=(name, reset=false)");
	}
	
	char* string_name = StringValueCStr(name);
	int int_reset = RTEST(reset);
	
	Ogre_Agent_setBaseAnimation(ptr_agent, string_name, int_reset);
	
	return Qnil;
}

static VALUE setTopAnimation(int argc, VALUE *argv, VALUE self){
	Ogre_AgentPtr ptr_agent;
	Data_Get_Struct(self, Ogre_AgentPtr, ptr_agent);
	
	VALUE name;
	VALUE reset;
	if(argc == 1)
	{
		// Set default for "reset"
		name = argv[0];
		reset = Qfalse;
	}
	else if(argc == 2)
	{
		// Use provided "reset" value
		name = argv[0];
		reset = argv[1];
	}
	else
	{
		rb_raise(rb_eArgError, "ERROR: Argument mismatch - Agent#top_animation=(name, reset=false)");
	}
	
	char* string_name = StringValueCStr(name);
	int int_reset = RTEST(reset);
	
	Ogre_Agent_setTopAnimation(ptr_agent, string_name, int_reset);
	
	return Qnil;
}

// Return list of animation names
// Return: array of strings
static VALUE animation_names(int argc, VALUE *argv, VALUE self){
	return Qnil;
}