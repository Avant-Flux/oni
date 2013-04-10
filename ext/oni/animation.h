#include <stdio.h>
#include <stdlib.h>
#include <ruby.h>

#include <OgreInterface.h>

#include "animation_easing.h"

void Init_Oni_Animation(VALUE outer);

static VALUE alloc(VALUE class);

static VALUE initialize(VALUE self, VALUE model);
static VALUE update(VALUE self, VALUE dt);

static VALUE shareSkeletonWith(VALUE self, VALUE other, VALUE scale);

static VALUE animation_names(VALUE self);

static VALUE getAnimationTrack(VALUE self, VALUE track_name);