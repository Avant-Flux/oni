#include "animation.h"
#include "Animation.h" // CPP interface header

VALUE Init_Oni_Animation(VALUE outer){
	VALUE klass = rb_define_class_under(outer, "Animation", rb_cObject);
	
	rb_define_alloc_func(klass, alloc);
	rb_define_method(klass, "initialize", initialize, 1);
	rb_define_method(klass, "update", update, 1);
	
	rb_define_method(klass, "base_animation", getBaseAnimation, 0);
	rb_define_method(klass, "top_animation", getTopAnimation, 0);
	rb_define_method(klass, "base_animation=", setBaseAnimation, -1);
	rb_define_method(klass, "top_animation=", setTopAnimation, -1);
	rb_define_method(klass, "animations", animation_names, 0);
	
	return Qnil;
}

static VALUE alloc(VALUE class){
	Oni_AnimationPtr animation = Oni_Animation_new();
	VALUE data = Data_Wrap_Struct(class, NULL, Oni_Animation_delete, animation);
	
	return data;
}

static VALUE initialize(VALUE self, VALUE model){
	Oni_AnimationPtr ptr_animation;
	Data_Get_Struct(self, Oni_AnimationPtr, ptr_animation);
	
	Oni_ModelPtr ptr_model;
	Data_Get_Struct(model, Oni_ModelPtr, ptr_model);
	
	Oni_Animation_initialize(ptr_animation, ptr_model);
	
	return Qnil;
}

static VALUE update(VALUE self, VALUE dt){
	Oni_AnimationPtr ptr_animation;
	Data_Get_Struct(self, Oni_AnimationPtr, ptr_animation);
	
	double double_dt = NUM2DBL(dt);
	
	Oni_Animation_update(ptr_animation, double_dt);
	
	return Qnil;
}

static VALUE getBaseAnimation(VALUE self)
{
	Oni_AnimationPtr ptr_animation;
	Data_Get_Struct(self, Oni_AnimationPtr, ptr_animation);
	
	const char* str_animation_name = Oni_Animation_getBaseAnimation(ptr_animation);
	
	VALUE name = rb_str_new2(str_animation_name);
	
	return name;
}

static VALUE getTopAnimation(VALUE self)
{
	Oni_AnimationPtr ptr_animation;
	Data_Get_Struct(self, Oni_AnimationPtr, ptr_animation);
	
	const char* str_animation_name = Oni_Animation_getTopAnimation(ptr_animation);
	
	VALUE name = rb_str_new2(str_animation_name);
	
	return name;
}

static VALUE setBaseAnimation(int argc, VALUE *argv, VALUE self){
	Oni_AnimationPtr ptr_animation;
	Data_Get_Struct(self, Oni_AnimationPtr, ptr_animation);
	
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
	
	Oni_Animation_setBaseAnimation(ptr_animation, string_name, int_reset);
	
	return Qnil;
}

static VALUE setTopAnimation(int argc, VALUE *argv, VALUE self){
	Oni_AnimationPtr ptr_animation;
	Data_Get_Struct(self, Oni_AnimationPtr, ptr_animation);
	
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
	
	Oni_Animation_setTopAnimation(ptr_animation, string_name, int_reset);
	
	return Qnil;
}

// Return list of animation names (array of strings)
// If no animations found, returns an empty array
static VALUE animation_names(VALUE self){
	Oni_AnimationPtr ptr_animation;
	Data_Get_Struct(self, Oni_AnimationPtr, ptr_animation);
	
	// Get an array of c-level strings
	// Array is NULL terminated, so a size is not necessary
	char** str_array = Oni_Animation_getAnimationNames(ptr_animation);
	
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