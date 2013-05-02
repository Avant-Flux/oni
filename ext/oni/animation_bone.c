#include "animation_bone.h"

// Memory allocated by C++ level code, as this class should never be created at Ruby level
// however, C++ level code has no need for this wrapper
// so it should be discarded when Ruby no longer needs it
void Init_Oni_Animation_Bone(VALUE outer){
	VALUE klass = rb_define_class_under(outer, "Bone", rb_cObject);
	
	rb_define_method(klass, "update", update, 1);
	
	// rb_define_method(klass, "name", getName, 0);
}

VALUE rb_Oni_Animation_Bone_new(Oni_BonePtr ptr_bone){
	// Should only be visible at C level
	// This class should essentially be a private nested class
	// It is merely a handle for things managed by Oni::Animation
	
	// TOOD: Figure out if there needs to be an override of new/initialize at ruby level so that this "private class" can't be created, even though Ruby doesn't seem to have private classes.
	// TODO: Consider making this function "inline"
	
	VALUE module = rb_const_get(rb_cObject, rb_intern("Oni"));
	VALUE outer_end = rb_const_get(module, rb_intern("Animation"));
	VALUE class = rb_const_get(outer_end, rb_intern("Bone"));
	
	VALUE bone = Data_Wrap_Struct(class, NULL, Oni_Bone_delete, ptr_bone);
	
	return bone;
}

static VALUE update(VALUE self, VALUE dt){
	Oni_BonePtr ptr_bone;
	Data_Get_Struct(self, Oni_BonePtr, ptr_bone);
	
	double double_dt = NUM2DBL(dt);
	
	Oni_Bone_update(ptr_bone, double_dt);
	
	return Qnil;
}
