#include <stdio.h>
#include <stdlib.h>
#include <ruby.h>

#include <OgreInterface.h>

#include "animation_easing.h"

VALUE Init_Oni_Animation(VALUE outer);

static VALUE alloc(VALUE class);

static VALUE initialize(VALUE self, VALUE model);
static VALUE update(VALUE self, VALUE dt);

static VALUE setBaseAnimation(int argc, VALUE *argv, VALUE self);
static VALUE getBaseAnimation(VALUE self);
static VALUE getTopAnimation(VALUE self);
static VALUE setTopAnimation(int argc, VALUE *argv, VALUE self);
static VALUE animation_names(VALUE self);
