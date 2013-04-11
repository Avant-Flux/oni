#include "window.h"

void Init_Oni_Window(VALUE outer){
	VALUE klass = rb_define_class_under(outer, "Window", rb_cObject);
	
	rb_define_alloc_func(klass, alloc);
	rb_define_method(klass, "initialize", initialize, 1);
	
	rb_define_method(klass, "show", show, 0);
	// rb_define_method(klass, "update", update, 1);
}

static VALUE alloc(VALUE class){
	// TODO: Remove all arguments to allocator and set values in initializer instead
	/* VALUE class, void (*mark)(), void (*free)(), void *ptr */
	Ogre_WindowPtr window = Ogre_Window_new(update, buttonDown, buttonUp);
	
	if(window == NULL)
	{
		// Throw exception
		rb_raise(rb_eException, "Window could not be opened.");
	}
	
	VALUE data = Data_Wrap_Struct(class, NULL, Ogre_Window_delete, window);
	
	/* class, argc, *argv, */
	// rb_obj_call_init(data, 0, NULL);
	
	return data;
}

static VALUE initialize(VALUE self, VALUE window_title){
	Ogre_WindowPtr ptr;
	Data_Get_Struct(self, Ogre_WindowPtr, ptr);
	
	char* string_window_title = StringValueCStr(window_title);
	Ogre_Window_initialize(ptr, string_window_title);
	
	return Qnil;
}

static VALUE show(VALUE self){
	// Run the window
	// OGRE_WINDOW ptr;
	Ogre_WindowPtr ptr;
	Data_Get_Struct(self, Ogre_WindowPtr, ptr);
	
	// Assumed that VALUE is some sort of typedef-ed pointer
	update(1, (void*)self);
	buttonDown(1, (void*)self);
	buttonUp(1, (void*)self);
	
	Ogre_Window_run(ptr);
	
	// NOTE: Assuming game is done when window closes
	// Destroy all Ruby-level instance variables for self
	
	// Mark all instance variables for GC
	VALUE ruby_variables = rb_obj_instance_variables(self);
	long number_of_variables = RARRAY_LEN(ruby_variables);
		// printf("var count: %d\n", number_of_variables);
	long i;
	for(i=0; i < number_of_variables; i++){ // Iterate over a list of instance variable names
		// printf("%d\n", i);
		
		VALUE var_name = RARRAY_PTR(ruby_variables)[i];
		
		VALUE ivar = rb_funcall(self, rb_intern("instance_variable_get"), 1, var_name);
		
		VALUE rString_klass = rb_any_to_s(ivar);
		char* str_klass = StringValueCStr(rString_klass);
		printf("%d out of %d: %s\n", i+1, number_of_variables, str_klass);
		
		if(!
			(
				TYPE(ivar) == T_TRUE ||
				TYPE(ivar) == T_FALSE ||
				TYPE(ivar) == T_NIL || 
				TYPE(ivar) == T_SYMBOL
			)
		){
			rb_gc_force_recycle(ivar);
		}
	}
	printf("DONE MARKING FOR GC\n");
	
	// printf("START GC\n");
	// Force GC
	rb_gc_start();
	
	return Qnil;
}

//      _________    __    __    ____  ___   ________ _______
//	   / ____/   |  / /   / /   / __ )/   | / ____/ //_/ ___/
//	  / /   / /| | / /   / /   / __  / /| |/ /   / ,<  \__ \ 
//	 / /___/ ___ |/ /___/ /___/ /_/ / ___ / /___/ /| |___/ / 
//	 \____/_/  |_/_____/_____/_____/_/  |_\____/_/ |_/____/  
	                                                        

static void update(double dt, void* ruby_window){	
	static VALUE rb_window = NULL;
	if(ruby_window != NULL)
	{
		// Only set the value, then get out
		// This is in lieu of function overloading
		rb_window = (VALUE)ruby_window;
		return;
	}
	
	if(rb_window != NULL)
	{
		rb_funcall(rb_window, rb_intern("update"), 1, rb_float_new(dt));
	}
}

static void buttonDown(unsigned int key_id, void* ruby_window)
{
	static VALUE rb_window = NULL;
	if(ruby_window != NULL)
	{
		// Only set the value, then get out
		// This is in lieu of function overloading
		rb_window = (VALUE)ruby_window;
		return;
	}
	
	if(rb_window != NULL)
	{
		rb_funcall(rb_window, rb_intern("button_down"), 1, INT2NUM(key_id));
	}
}

static void buttonUp(unsigned int key_id, void* ruby_window)
{
	static VALUE rb_window = NULL;
	if(ruby_window != NULL)
	{
		// Only set the value, then get out
		// This is in lieu of function overloading
		rb_window = (VALUE)ruby_window;
		return;
	}
	
	if(rb_window != NULL)
	{
		rb_funcall(rb_window, rb_intern("button_up"), 1, INT2NUM(key_id));
	}
}
