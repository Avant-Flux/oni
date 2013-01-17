#include <stdio.h>
#include <stdlib.h>
#include <ruby.h>

#include <OgreInterface.h>

VALUE Init_Oni_Agent(VALUE outer);

static VALUE alloc(VALUE class);

static VALUE initialize(VALUE self, VALUE window, VALUE name, VALUE filename);
static VALUE update(VALUE self, VALUE dt);

static VALUE getVisible(VALUE self);
static VALUE setVisible(VALUE self, VALUE visible);

static VALUE setPosition(VALUE self, VALUE pos);
static VALUE translate(VALUE self, VALUE x, VALUE y, VALUE z);

static VALUE pitch(VALUE self, VALUE radians);
static VALUE yaw(VALUE self, VALUE radians);
static VALUE roll(VALUE self, VALUE radians);

static VALUE rotateTo(VALUE self, VALUE x, VALUE y, VALUE z);

static VALUE setRotation(VALUE self, VALUE radians);

static VALUE setBaseAnimation(int argc, VALUE *argv, VALUE self);
static VALUE getBaseAnimation(VALUE self);
static VALUE getTopAnimation(VALUE self);
static VALUE setTopAnimation(int argc, VALUE *argv, VALUE self);
static VALUE animation_names(VALUE self);
