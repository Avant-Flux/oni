#include "animation.h"
#include "animation_track.h"
#include "bone.h"

void Init_Oni_Animation(VALUE outer){
	VALUE klass = rb_define_class_under(outer, "Animation", rb_cObject);
	
	rb_define_alloc_func(klass, alloc);
	rb_define_method(klass, "initialize", initialize, 1);
	rb_define_method(klass, "update", update, 1);
	
	rb_define_method(klass, "share_skeleton_with", shareSkeletonWith, -1);
	rb_define_method(klass, "bone", getBone, 1);
	
	rb_define_method(klass, "animations", animation_names, 0);
	
	rb_define_method(klass, "[]", getAnimationTrack, 1);
	
	// Add easing equations
	Init_Oni_AnimationEasing(klass);
	
	
	// Nested class
	Init_Oni_Animation_Track(klass);
	Init_Oni_Animation_Bone(klass);
	Init_Oni_AnimationEasing(klass);
}

static VALUE alloc(VALUE class){
	Oni_AnimationPtr animation = Oni_Animation_new();
	VALUE data = Data_Wrap_Struct(class, NULL, Oni_Animation_delete, animation);
	
	// TODO: Consider force-GCing all Ruby-level AnimationTrack objects when a related Animation object is GCed.  If they are not GCed, then using them will result in a segfault, as the underlying C++ resources no longer exist.
	// TODO: Consider if it is possible to hold on to a AnimationTrack, while losing an Animation.  This is the only situation where the GC problem will happen.  It might actually be better to leave that bug in, as this warping of who has what is probably an indicator of poor design.
	
	return data;
}

static VALUE initialize(VALUE self, VALUE model){
	Oni_AnimationPtr ptr_animation;
	Data_Get_Struct(self, Oni_AnimationPtr, ptr_animation);
	
	Oni_ModelPtr ptr_model;
	Data_Get_Struct(model, Oni_ModelPtr, ptr_model);
	
	Oni_Animation_initialize(ptr_animation, ptr_model);
	
	return Qnil;
}

static VALUE update(VALUE self, VALUE dt){
	Oni_AnimationPtr ptr_animation;
	Data_Get_Struct(self, Oni_AnimationPtr, ptr_animation);
	
	double double_dt = NUM2DBL(dt);
	
	Oni_Animation_update(ptr_animation, double_dt);
	
	return Qnil;
}

static VALUE shareSkeletonWith(int argc, VALUE* argv, VALUE self){
	VALUE other = argv[0];
	VALUE scale = argv[1];
	
	Oni_AnimationPtr ptr_animation;
	Data_Get_Struct(self, Oni_AnimationPtr, ptr_animation);
	
	Oni_AnimationPtr ptr_otherAnimation;
	Data_Get_Struct(other, Oni_AnimationPtr, ptr_otherAnimation);
	
	double dbl_scale;
	if(argc == 2)
	{
		// share_skeleton_with(other, scale)
		dbl_scale = NUM2DBL(scale);
	}
	else if(argc == 1)
	{
		// share_skeleton_with(other)
		dbl_scale = 1.0;
	}
	
	Oni_Animation_shareSkeletonWith(ptr_animation, ptr_otherAnimation, dbl_scale);
	
	return Qnil;
}

// Return list of animation names (array of strings)
// If no animations found, returns an empty array
static VALUE animation_names(VALUE self){
	Oni_AnimationPtr ptr_animation;
	Data_Get_Struct(self, Oni_AnimationPtr, ptr_animation);
	
	// Get an array of c-level strings
	// Array is NULL terminated, so a size is not necessary
	char** str_array = Oni_Animation_getAnimationNames(ptr_animation);
	
	// Create a ruby array
	VALUE array = rb_ary_new();
	
	// Fill it with ruby strings
	int i;
	for(i=0; str_array[i] != NULL; i++)
	{
		VALUE string = rb_str_new2(str_array[i]);
		rb_ary_store(array, i, string);
		
		// Free memory as the array is traversed
		free(str_array[i]);
	}
	
	// Free c array returned by Ogre interface call
	free(str_array);
	
	
	return array;
}

static VALUE getAnimationTrack(VALUE self, VALUE track_name){
	Oni_AnimationPtr ptr_animation;
	Data_Get_Struct(self, Oni_AnimationPtr, ptr_animation);
	
	// Allocate memory
	char* str_name = StringValueCStr(track_name);
	
	// Process call
	// Can be NULL
	Oni_Animation_TrackPtr ptr_track = Oni_Animation_getAnimationTrack(ptr_animation, str_name);
	if(ptr_track == NULL)
	{
		return Qnil;
	}
	
	
	// Wrap into Ruby object
	VALUE track = rb_Oni_Animation_Track_new(ptr_track);
	
	return track;
}

static VALUE getBone(VALUE self, VALUE name){
	Oni_AnimationPtr ptr_animation;
	Data_Get_Struct(self, Oni_AnimationPtr, ptr_animation);
	
	// Allocate memory
	char* str_name = StringValueCStr(name);
	
	// Process call
	// Can be NULL
	Oni_BonePtr ptr_bone = Oni_Animation_getBone(ptr_animation, str_name);
	if(ptr_bone == NULL)
	{
		return Qnil;
	}
	
	
	// Wrap into Ruby object
	VALUE bone = rb_Oni_Animation_Track_new(ptr_bone);
	
	return bone;
}