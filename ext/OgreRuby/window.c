#include "window.h"

VALUE Init_OgreWindow(VALUE outer){
	VALUE klass = rb_define_class_under(outer, "Window", rb_cObject);
	
	rb_define_alloc_func(klass, alloc);
	
	rb_define_method(klass, "show", show, 0);
	// rb_define_method(klass, "update", update, 1);
}

static VALUE alloc(VALUE class){
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

static VALUE show(VALUE self){
	// Run the window
	// OGRE_WINDOW ptr;
	Ogre_WindowPtr ptr;
	Data_Get_Struct(self, Ogre_WindowPtr, ptr);
	
	rb_funcall(self, rb_intern("setup"), 0);
	
	// Assumed that VALUE is some sort of typedef-ed pointer
	update(1, (void*)self);
	buttonDown(1, (void*)self);
	buttonUp(1, (void*)self);
	
	Ogre_Window_run(ptr);
	
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
