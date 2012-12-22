#include "window.h"

VALUE Init_OgreWindow(VALUE outer){
	VALUE klass = rb_define_class_under(outer, "Window", rb_cObject);
	
	rb_define_alloc_func(klass, alloc);
	
	rb_define_method(klass, "show", show, 0);
	rb_define_method(klass, "add_time", add_time, 1);
}

static VALUE alloc(VALUE class){
	/* VALUE class, void (*mark)(), void (*free)(), void *ptr */
	Ogre_WindowPtr window = Ogre_Window_new();
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
	
	Ogre_Window_run(ptr);
	
	return Qnil;
} 

static VALUE add_time(VALUE self, VALUE dt){
	// rb_funcall(self, rb_intern("add_time"), 1, dt);
	
	return Qnil;
}
