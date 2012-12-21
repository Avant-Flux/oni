#include <stdio.h>
#include <stdlib.h>
#include <ruby.h>

#include <OgreInterface.h>

VALUE Init_OgreAgent(VALUE outer);

static VALUE initialize(int argc, VALUE *argv, VALUE klass);
static VALUE finalize(int argc, VALUE *argv, VALUE klass);

static VALUE setBaseAnimation(int argc, VALUE *argv, VALUE klass);
static VALUE animation_names(int argc, VALUE *argv, VALUE klass);