#include <stdio.h>
#include <stdlib.h>
#include <ruby.h>

#include "ogre.h"

void Init_ogre(){
	VALUE module = rb_define_module("Ogre");
	
	VALUE klass = rb_define_class_under(module, "Agent", rb_cObject);
	
	rb_define_method(klass, "initialize")
	
	
	
	
}

static VALUE initialize(int argc, VALUE *argv, VALUE klass){
	OGRE_TYPE Agent = Ogre_Agent(); // MUST free memory later
}

static VALUE finalize(int argc, VALUE *argv, VALUE klass){
	
}

static VALUE setBaseAnimation(){
	Ogre_Agent_setBaseAnimation();
}


// Metacode level (aka ruby acess)
static VALUE foo(int argc, VALUE *argv, VALUE klass){
	
}

// Backend level (pure C access)
// NOTE: This is actually useless, as the C++ extern effectively generates this code
static void Ogre_foo(){
	
}

// C++ interface level

// C++ Backend (actual Ogre code)
