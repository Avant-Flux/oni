#include "animation_track.h"

VALUE Init_Oni_AnimationTrack(VALUE outer){
	VALUE klass = rb_define_class_under(outer, "AnimationTrack", rb_cObject);
	
	rb_define_alloc_func(klass, alloc);
	rb_define_method(klass, "initialize", initialize, 1);
	rb_define_method(klass, "update", update, 1);
	
	return Qnil;
}

static VALUE alloc(VALUE class){
	Oni_AnimationTrackPtr animation = Oni_AnimationTrack_new();
	VALUE data = Data_Wrap_Struct(class, NULL, Oni_Animation_delete, animation);
	
	return data;
}

static VALUE initialize(VALUE self, VALUE animation_state){
	Oni_AnimationTrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_AnimationTrackPtr, ptr_animation_track);
	
	Ogre_AnimationStatePtr ptr_animation_state;
	Data_Get_Struct(animation_state, Ogre_AnimationStatePtr, ptr_animation_state);
	
	Oni_AnimationTrack_initialize(ptr_animation_track, ptr_animation_state);
	
	return Qnil;
}

static VALUE update(VALUE self, VALUE dt){
	Oni_AnimationTrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_AnimationTrackPtr, ptr_animation_track);
	
	double double_dt = NUM2DBL(dt);
	
	Oni_AnimationTrack_update(ptr_animation_track, double_dt);
	
	return Qnil;
}

