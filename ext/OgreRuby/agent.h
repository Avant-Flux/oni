#include <stdio.h>
#include <stdlib.h>
#include <ruby.h>

#include <OgreInterface.h>

VALUE Init_OgreAgent(VALUE outer);

static VALUE alloc(VALUE class);

// static VALUE translate(int argc, VALUE *argv, VALUE self);
static VALUE translate(VALUE self, VALUE x, VALUE y, VALUE z);

static VALUE setBaseAnimation(int argc, VALUE *argv, VALUE self);
static VALUE animation_names(int argc, VALUE *argv, VALUE self);