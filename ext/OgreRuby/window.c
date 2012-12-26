#include "window.h"

VALUE Init_OgreWindow(VALUE outer){
	VALUE klass = rb_define_class_under(outer, "Window", rb_cObject);
	
	rb_define_alloc_func(klass, alloc);
	
	rb_define_method(klass, "show", show, 0);
	rb_define_method(klass, "update", update, 1);
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
	
	rb_funcall(self, rb_intern("setup"), 0);
	
	Ogre_Window_run(ptr);
	
	return Qnil;
} 

static VALUE update(VALUE self, VALUE dt){
	// rb_funcall(self, rb_intern("update"), 1, dt);
	
	return Qnil;
}
