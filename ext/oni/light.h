#include <stdio.h>
#include <stdlib.h>
#include <ruby.h>

#include <OgreInterface.h>

void Init_Oni_Light(VALUE outer);

static VALUE alloc(VALUE class);

static VALUE initialize(VALUE self, VALUE window, VALUE name);
static VALUE update(VALUE self, VALUE dt);
