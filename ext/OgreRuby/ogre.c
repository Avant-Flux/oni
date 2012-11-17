#include <stdio.h>
#include <stdlib.h>
#include <ruby.h>

#include "ogre.h"
#include "window.h"

void Init_ogre(){
	VALUE module = rb_define_module("Ogre");
	
	Init_OgreWindow(module);
	Init_OgreAgent(module);
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
