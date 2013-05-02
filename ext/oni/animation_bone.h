#include <stdio.h>
#include <stdlib.h>
#include <ruby.h>

#include <OgreInterface.h>

void Init_Oni_Animation_Bone(VALUE outer);

VALUE rb_Oni_Animation_Bone_new(Oni_Animation_BonePtr ptr_bone);

static VALUE update(VALUE self, VALUE dt);