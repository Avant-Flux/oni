#include <stdio.h>
#include <stdlib.h>
#include <ruby.h>

#include <OgreInterface.h>

#include "ogre.h"
#include "window.h"
#include "agent.h"

void Init_OgreRuby(){
	VALUE module = rb_define_module("OgreRuby");
	
	Init_OgreWindow(module);
	Init_OgreAgent(module);
}
