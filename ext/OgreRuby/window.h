#include <stdio.h>
#include <stdlib.h>
#include <ruby.h>

#include <OgreInterface.h>


VALUE Init_OgreWindow(VALUE outer);

VALUE OgreWindow_new(VALUE class);
static VALUE allocate(VALUE class);

static VALUE initialize(int argc, VALUE *argv, VALUE klass);
static VALUE finalize(int argc, VALUE *argv, VALUE klass);

static VALUE show(VALUE klass);
static VALUE add_time(VALUE klass, VALUE dt);