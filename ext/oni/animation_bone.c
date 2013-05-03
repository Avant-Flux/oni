#include "animation_bone.h"

// Memory allocated by C++ level code, as this class should never be created at Ruby level
// however, C++ level code has no need for this wrapper
// so it should be discarded when Ruby no longer needs it
void Init_Oni_Animation_Bone(VALUE outer){
	VALUE klass = rb_define_class_under(outer, "Bone", rb_cObject);
	
	rb_define_method(klass, "update", update, 1);
	
	rb_define_method(klass, "position", getPosition, 0);
	rb_define_method(klass, "orientation", getOrientation, 0);
	rb_define_method(klass, "initial_position", getInitialPosition, 0);
	rb_define_method(klass, "initial_orientation", getInitialOrientation, 0);
	rb_define_method(klass, "position_delta", getPositionDelta, 0);
	rb_define_method(klass, "orientation_delta", getOrientationDelta, 0);
}

VALUE rb_Oni_Animation_Bone_new(Oni_Animation_BonePtr ptr_bone){
	// Should only be visible at C level
	// This class should essentially be a private nested class
	// It is merely a handle for things managed by Oni::Animation
	
	// TOOD: Figure out if there needs to be an override of new/initialize at ruby level so that this "private class" can't be created, even though Ruby doesn't seem to have private classes.
	// TODO: Consider making this function "inline"
	
	VALUE module = rb_const_get(rb_cObject, rb_intern("Oni"));
	VALUE outer_end = rb_const_get(module, rb_intern("Animation"));
	VALUE class = rb_const_get(outer_end, rb_intern("Bone"));
	
	VALUE bone = Data_Wrap_Struct(class, NULL, Oni_Animation_Bone_delete, ptr_bone);
	
	return bone;
}

static VALUE update(VALUE self, VALUE dt){
	Oni_Animation_BonePtr ptr_bone;
	Data_Get_Struct(self, Oni_Animation_BonePtr, ptr_bone);
	
	double double_dt = NUM2DBL(dt);
	
	Oni_Animation_Bone_update(ptr_bone, double_dt);
	
	return Qnil;
}

static VALUE getPosition(VALUE self){
	Oni_Animation_BonePtr ptr_bone;
	Data_Get_Struct(self, Oni_Animation_BonePtr, ptr_bone);
	
	double position[ONI_POSITION_VECTOR_SIZE];
	Oni_Animation_Bone_getPosition(ptr_bone, position);
	
	// Convert the C array into a Ruby array
	VALUE array = rb_ary_new2(ONI_POSITION_VECTOR_SIZE);
	int i;
	for(i = 0; i < ONI_POSITION_VECTOR_SIZE; i++){
		rb_ary_store(array, i, rb_float_new(position[i]));
	}
	
	return array;
}

static VALUE getOrientation(VALUE self){
	Oni_Animation_BonePtr ptr_bone;
	Data_Get_Struct(self, Oni_Animation_BonePtr, ptr_bone);
	
	double orientation[ONI_QUATERNION_VECTOR_SIZE];
	Oni_Animation_Bone_getOrientation(ptr_bone, orientation);
	
	// Convert the C array into a Ruby array
	VALUE array = rb_ary_new2(ONI_QUATERNION_VECTOR_SIZE);
	int i;
	for(i = 0; i < ONI_QUATERNION_VECTOR_SIZE; i++){
		rb_ary_store(array, i, rb_float_new(orientation[i]));
	}
	
	return array;
}

static VALUE getInitialPosition(VALUE self){
	Oni_Animation_BonePtr ptr_bone;
	Data_Get_Struct(self, Oni_Animation_BonePtr, ptr_bone);
	
	double position[ONI_POSITION_VECTOR_SIZE];
	Oni_Animation_Bone_getInitialPosition(ptr_bone, position);
	
	// Convert the C array into a Ruby array
	VALUE array = rb_ary_new2(ONI_POSITION_VECTOR_SIZE);
	int i;
	for(i = 0; i < ONI_POSITION_VECTOR_SIZE; i++){
		rb_ary_store(array, i, rb_float_new(position[i]));
	}
	
	return array;
}

static VALUE getInitialOrientation(VALUE self){
	Oni_Animation_BonePtr ptr_bone;
	Data_Get_Struct(self, Oni_Animation_BonePtr, ptr_bone);
	
	double orientation[ONI_QUATERNION_VECTOR_SIZE];
	Oni_Animation_Bone_getInitialOrientation(ptr_bone, orientation);
	
	// Convert the C array into a Ruby array
	VALUE array = rb_ary_new2(ONI_QUATERNION_VECTOR_SIZE);
	int i;
	for(i = 0; i < ONI_QUATERNION_VECTOR_SIZE; i++){
		rb_ary_store(array, i, rb_float_new(orientation[i]));
	}
	
	return array;
}

static VALUE getPositionDelta(VALUE self){
	Oni_Animation_BonePtr ptr_bone;
	Data_Get_Struct(self, Oni_Animation_BonePtr, ptr_bone);
	
	double position[ONI_POSITION_VECTOR_SIZE];
	Oni_Animation_Bone_getPositionDelta(ptr_bone, position);
	
	// Convert the C array into a Ruby array
	VALUE array = rb_ary_new2(ONI_POSITION_VECTOR_SIZE);
	int i;
	for(i = 0; i < ONI_POSITION_VECTOR_SIZE; i++){
		rb_ary_store(array, i, rb_float_new(position[i]));
	}
	
	return array;
}

static VALUE getOrientationDelta(VALUE self){
	Oni_Animation_BonePtr ptr_bone;
	Data_Get_Struct(self, Oni_Animation_BonePtr, ptr_bone);
	
	double orientation[ONI_QUATERNION_VECTOR_SIZE];
	Oni_Animation_Bone_getOrientationDelta(ptr_bone, orientation);
	
	// Convert the C array into a Ruby array
	VALUE array = rb_ary_new2(ONI_QUATERNION_VECTOR_SIZE);
	int i;
	for(i = 0; i < ONI_QUATERNION_VECTOR_SIZE; i++){
		rb_ary_store(array, i, rb_float_new(orientation[i]));
	}
	
	return array;
}
