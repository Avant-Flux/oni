#include "window.h"

VALUE Init_OgreWindow(VALUE outer){
	VALUE klass = rb_define_class_under(outer, "Window", rb_cObject);
	
	rb_define_singleton_method(klass, "new", OgreWindow_new, 1);
	rb_define_method(klass, "initialize", initialize, -1);
	
	rb_define_method(klass, "show", show, 0);
	rb_define_method(klass, "add_time", add_time, 1);
}

VALUE OgreWindow_new(VALUE class){
	/* VALUE class, void (*mark)(), void (*free)(), void *ptr */
	// Ogre_WindowPtr window = Ogre_Window_new();
	// VALUE data = Data_Wrap_Struct(class, NULL, Ogre_Window_delete, window);
	
	// /* class, argc, *argv, */
	// rb_obj_call_init(data, 0, NULL);
	
	// return data;
	return Qnil;
}

static VALUE initialize(int argc, VALUE *argv, VALUE self){
	return Qnil;
}

static VALUE finalize(int argc, VALUE *argv, VALUE self){
	// Free space used by the window
	return Qnil;
}

static VALUE show(VALUE self){
	// Run the window
	// OGRE_WINDOW ptr;
	// Data_Get_Struct(self, OGRE_WINDOW, ptr);
	
	return Qnil;
} 

static VALUE add_time(VALUE self, VALUE dt){
	// rb_funcall(self, rb_intern("add_time"), 1, dt);
	
	return Qnil;
}
