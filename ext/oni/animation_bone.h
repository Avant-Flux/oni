#include <stdio.h>
#include <stdlib.h>
#include <ruby.h>

#include <OgreInterface.h>

#define ONI_POSITION_VECTOR_SIZE 3
#define ONI_QUATERNION_VECTOR_SIZE 4

void Init_Oni_Animation_Bone(VALUE outer);

VALUE rb_Oni_Animation_Bone_new(Oni_Animation_BonePtr ptr_bone);

static VALUE update(VALUE self, VALUE dt);

static VALUE getPosition(VALUE self);
static VALUE getOrientation(VALUE self);

static VALUE getInitialPosition(VALUE self);
static VALUE getInitialOrientation(VALUE self);

static VALUE getPositionDelta(VALUE self);
static VALUE getOrientationDelta(VALUE self);
