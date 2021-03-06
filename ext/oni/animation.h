#include <stdio.h>
#include <stdlib.h>
#include <ruby.h>

#include <OgreInterface.h>

#include "animation_easing.h"

void Init_Oni_Animation(VALUE outer);

static VALUE alloc(VALUE class);

static VALUE initialize(VALUE self, VALUE model);
static VALUE update(VALUE self, VALUE dt);

static VALUE shareSkeletonWith(int argc, VALUE* argv, VALUE self);
	// static VALUE shareSkeletonWith(VALUE self, VALUE other, VALUE scale = 1.0);
static VALUE getBone(VALUE self, VALUE name);

static VALUE animation_names(VALUE self);

static VALUE getAnimationTrack(VALUE self, VALUE track_name);