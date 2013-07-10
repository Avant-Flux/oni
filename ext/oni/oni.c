#include <stdio.h>
#include <stdlib.h>
#include <ruby.h>

// #include <OgreInterface.h>

// Use extern instead of including headers, as the headers only
// have one function each which is not declared "extern"
extern Init_Oni_Window(VALUE module);	// Defined in window.h
extern Init_Oni_Camera(VALUE module);	// Defined in camera.h

extern Init_Oni_Node(VALUE module);

extern Init_Oni_Light(VALUE module);

extern Init_Oni_Model(VALUE module);
extern Init_Oni_Animation(VALUE module);

void Init_oni(){
	VALUE module = rb_define_module("Oni");
	
	Init_Oni_Window(module);
	
	Init_Oni_Camera(module);
	
	Init_Oni_Node(module);
	
	Init_Oni_Light(module);
	
	Init_Oni_Model(module);
	Init_Oni_Animation(module);
}
