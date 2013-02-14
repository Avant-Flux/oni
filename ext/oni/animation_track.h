#include <stdio.h>
#include <stdlib.h>
#include <ruby.h>

#include <OgreInterface.h>

VALUE Init_Oni_AnimationTrack(VALUE outer);

static VALUE alloc(VALUE class);

static VALUE initialize(VALUE self, VALUE model);
static VALUE update(VALUE self, VALUE dt);
