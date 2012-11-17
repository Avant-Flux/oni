#include "window.h"

VALUE Init_OgreWindow(VALUE outer){
	VALUE klass = rb_define_class_under(outer, "Window", rb_cObject);
	
	rb_define_method(klass, "initialize", initialize, -1);
	rb_define_method(klass, "show", show, -1);
}

static VALUE initialize(int argc, VALUE *argv, VALUE klass){
	OGRE_TYPE Agent = Ogre_Agent(); // MUST free memory later
}

static VALUE finalize(int argc, VALUE *argv, VALUE klass){
	
}

static VALUE show(int argc, VALUE *argv, VALUE klass){
	
}