#include "agent.h"

VALUE Init_OgreAgent(VALUE outer){
	VALUE klass = rb_define_class_under(outer, "Agent", rb_cObject);
	
	rb_define_alloc_func(klass, alloc);
	rb_define_method(klass, "initialize", initialize, 3);
	rb_define_method(klass, "update", update, 1);
	
	rb_define_method(klass, "visible=", setVisible, 1);
	rb_define_method(klass, "visible", getVisible, 0);
	
	rb_define_method(klass, "position=", setPosition, 1);
	rb_define_method(klass, "translate", translate, 3);
	
	rb_define_method(klass, "pitch", pitch, 1);
	rb_define_method(klass, "yaw", yaw, 1);
	rb_define_method(klass, "roll", roll, 1);
	rb_define_method(klass, "rotate_to", rotateTo, 3);
	
	rb_define_method(klass, "base_animation", getBaseAnimation, 0);
	rb_define_method(klass, "top_animation", getTopAnimation, 0);
	rb_define_method(klass, "base_animation=", setBaseAnimation, -1);
	rb_define_method(klass, "top_animation=", setTopAnimation, -1);
	rb_define_method(klass, "animations", animation_names, 0);
}

static VALUE alloc(VALUE class){
	// Ruby interface: Agent.new(window, "name", "name.mesh")
	
	Ogre_AgentPtr agent = Ogre_Agent_new();
	VALUE data = Data_Wrap_Struct(class, Ogre_Agent_markgc, Ogre_Agent_delete, agent);
	
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

static VALUE setPosition(VALUE self, VALUE pos)
{
	Ogre_AgentPtr ptr_agent;
	Data_Get_Struct(self, Ogre_AgentPtr, ptr_agent);
	
	
	// TODO: Take single argument of one array - interpreted as a vector
	// RARRAY(pos)->ptr[0];
	VALUE x = rb_ary_entry(pos, 0);
	VALUE y = rb_ary_entry(pos, 1);
	VALUE z = rb_ary_entry(pos, 2);
	
	double dbl_x = NUM2DBL(x);
	double dbl_y = NUM2DBL(y);
	double dbl_z = NUM2DBL(z);
	
	Ogre_Agent_setPosition(ptr_agent, dbl_x, dbl_y, dbl_z);
}

static VALUE translate(VALUE self, VALUE x, VALUE y, VALUE z){
	Ogre_AgentPtr ptr;
	Data_Get_Struct(self, Ogre_AgentPtr, ptr);
	
	double dbl_x = NUM2DBL(x);
	double dbl_y = NUM2DBL(y);
	double dbl_z = NUM2DBL(z);
	
	Ogre_Agent_translate(ptr, dbl_x, dbl_y, dbl_z);
	
	return Qnil;
}

static VALUE pitch(VALUE self, VALUE radians){
	Ogre_AgentPtr ptr_agent;
	Data_Get_Struct(self, Ogre_AgentPtr, ptr_agent);
	
	double dbl_radians = NUM2DBL(radians);
	Ogre_Agent_pitch(ptr_agent, dbl_radians);
	
	return Qnil;
}

static VALUE yaw(VALUE self, VALUE radians){
	Ogre_AgentPtr ptr_agent;
	Data_Get_Struct(self, Ogre_AgentPtr, ptr_agent);
	
	double dbl_radians = NUM2DBL(radians);
	Ogre_Agent_yaw(ptr_agent, dbl_radians);
	
	return Qnil;
}

static VALUE roll(VALUE self, VALUE radians){
	Ogre_AgentPtr ptr_agent;
	Data_Get_Struct(self, Ogre_AgentPtr, ptr_agent);
	
	double dbl_radians = NUM2DBL(radians);
	Ogre_Agent_roll(ptr_agent, dbl_radians);
	
	return Qnil;
}

static VALUE rotateTo(VALUE self, VALUE x, VALUE y, VALUE z){
	Ogre_AgentPtr ptr_agent;
	Data_Get_Struct(self, Ogre_AgentPtr, ptr_agent);
	
	double dbl_x = NUM2DBL(x);
	double dbl_y = NUM2DBL(y);
	double dbl_z = NUM2DBL(z);
	
	Ogre_Agent_rotateTo(ptr_agent, dbl_x,dbl_y,dbl_z);
	
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

// Return list of animation names (array of strings)
// If no animations found, returns an empty array
static VALUE animation_names(VALUE self){
	Ogre_AgentPtr ptr_agent;
	Data_Get_Struct(self, Ogre_AgentPtr, ptr_agent);
	
	// Get an array of c-level strings
	// Array is NULL terminated, so a size is not necessary
	char** str_array = Ogre_Agent_getAnimationNames(ptr_agent);
	
	// Create a ruby array
	VALUE array = rb_ary_new();
	
	// Fill it with ruby strings
	int i;
	for(i=0; str_array[i] != NULL; i++)
	{
		VALUE string = rb_str_new2(str_array[i]);
		rb_ary_store(array, i, string);
		
		// Free memory as the array is traversed
		free(str_array[i]);
	}
	
	// Free c array returned by Ogre interface call
	free(str_array);
	
	
	return array;
}