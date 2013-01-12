#include <stdio.h>
#include <stdlib.h>
#include <ruby.h>

#include <OgreInterface.h>

// Use extern instead of including headers, as the headers only
// have one function each which is not declared "extern"
extern Init_OgreWindow(VALUE module);	// Defined in window.h
extern Init_OgreAgent(VALUE module);	// Defined in agent.h

void Init_OgreRuby(){
	VALUE module = rb_define_module("OgreRuby");
	
	Init_OgreWindow(module);
	Init_OgreAgent(module);
}
