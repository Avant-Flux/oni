#include <stdio.h>
#include <stdlib.h>
#include <ruby.h>

#include <OgreInterface.h>


VALUE Init_OgreWindow(VALUE outer);

static VALUE alloc(VALUE class);

static VALUE show(VALUE klass);
static VALUE add_time(VALUE klass, VALUE dt);