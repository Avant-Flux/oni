#include <stdio.h>
#include <stdlib.h>
#include <ruby.h>

#include <OgreInterface.h>

VALUE Init_OgreAgent(VALUE outer);

static VALUE alloc(VALUE class);

static VALUE initialize(VALUE self, VALUE window, VALUE name, VALUE filename);
static VALUE update(VALUE self, VALUE dt);

static VALUE getVisible(VALUE self);
static VALUE setVisible(VALUE self, VALUE visible);

static VALUE translate(VALUE self, VALUE x, VALUE y, VALUE z);

static VALUE setBaseAnimation(int argc, VALUE *argv, VALUE self);
static VALUE animation_names(int argc, VALUE *argv, VALUE self);