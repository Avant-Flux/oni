#include "window.h"

VALUE Init_OgreWindow(VALUE outer){
	VALUE klass = rb_define_class_under(outer, "Window", rb_cObject);
	
	rb_define_method(klass, "initialize", initialize, -1);
	rb_define_method(klass, "show", show, 0);
	rb_define_method(klass, "add_time", add_time, 1);
}

static VALUE initialize(int argc, VALUE *argv, VALUE self){
	// OGRE_TYPE Agent = Ogre_Agent(); // MUST free memory later
	
	// Allocate space for a OGRE_WINDOW (pointer)
	// Initialize the window
}

static VALUE finalize(int argc, VALUE *argv, VALUE self){
	// Free space used by the window
}

static VALUE show(VALUE self){
	// Run the window
}

static VALUE add_time(VALUE self, VALUE dt){
	rb_funcall(self, rb_intern("add_time"), 1, dt);
}
