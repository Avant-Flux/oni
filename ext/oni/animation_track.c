#include "animation_track.h"

VALUE Init_Oni_AnimationTrack(VALUE outer){
	VALUE klass = rb_define_class_under(outer, "AnimationTrack", rb_cObject);
	
	rb_define_alloc_func(klass, alloc);
	rb_define_method(klass, "initialize", initialize, 1);
	rb_define_method(klass, "update", update, 1);
	
	rb_define_method(klass, "fade_in", fadeIn, 2);
	rb_define_method(klass, "fade_out", fadeOut, 2);
	rb_define_method(klass, "weight=", setWeight, 1);
	rb_define_method(klass, "weight", getWeight, 0);
	rb_define_method(klass, "time=", setTime, 1);
	rb_define_method(klass, "time", getTime, 0);
	rb_define_method(klass, "loop=", setLoop, 1);
	rb_define_method(klass, "loop", getLoop, 0);
	rb_define_method(klass, "length", getLength, 0);
	rb_define_method(klass, "rate=", setPlaybackRate, 1);
	rb_define_method(klass, "rate", getPlaybackRate, 0);
	rb_define_method(klass, "enabled=", setEnabled, 1);
	
	rb_define_method(klass, "enabled?", getEnabled, 0);
	rb_define_method(klass, "ended?", hasEnded, 0);
	rb_define_method(klass, "playing?", getPlaying, 0);
	
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

static VALUE fadeIn(VALUE self, VALUE time, VALUE block){
	Oni_AnimationTrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_AnimationTrackPtr, ptr_animation_track);
	
	// fade(time) {|influence, dt|}
	// fade(time, &block)
	
	
	return Qnil;
}

static VALUE fadeOut(VALUE self, VALUE time, VALUE block){
	Oni_AnimationTrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_AnimationTrackPtr, ptr_animation_track);
	
	// fade(time) {|influence, dt|}
	// fade(time, &block)
	
	
	return Qnil;
}

static VALUE setWeight(VALUE self, VALUE weight){
	Oni_AnimationTrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_AnimationTrackPtr, ptr_animation_track);
	
	return Qnil;
}

static VALUE getWeight(VALUE self){
	Oni_AnimationTrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_AnimationTrackPtr, ptr_animation_track);
	
	return Qnil;
}

static VALUE setTime(VALUE self, VALUE time){
	Oni_AnimationTrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_AnimationTrackPtr, ptr_animation_track);
	
	return Qnil;
}

static VALUE getTime(VALUE self){
	Oni_AnimationTrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_AnimationTrackPtr, ptr_animation_track);
	
	return Qnil;
}

static VALUE setLoop(VALUE self, VALUE loop){
	Oni_AnimationTrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_AnimationTrackPtr, ptr_animation_track);
	
	return Qnil;
}

static VALUE getLoop(VALUE self){
	Oni_AnimationTrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_AnimationTrackPtr, ptr_animation_track);
	
	return Qnil;
}

static VALUE getLength(VALUE self){
	// Alias: duration
	Oni_AnimationTrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_AnimationTrackPtr, ptr_animation_track);
	
	return Qnil;
	
}

static VALUE setPlaybackRate(VALUE self, VALUE rate){
	Oni_AnimationTrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_AnimationTrackPtr, ptr_animation_track);
	
	return Qnil;
}

static VALUE getPlaybackRate(VALUE self){
	Oni_AnimationTrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_AnimationTrackPtr, ptr_animation_track);
	
	return Qnil;
}

static VALUE setEnabled(VALUE self, VALUE enabled){
	Oni_AnimationTrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_AnimationTrackPtr, ptr_animation_track);
	
	return Qnil;
}

static VALUE getEnabled(VALUE self){
	Oni_AnimationTrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_AnimationTrackPtr, ptr_animation_track);
	
	return Qnil;
}

static VALUE hasEnded(VALUE self){
	// Part of Ogre::AnimationState
	Oni_AnimationTrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_AnimationTrackPtr, ptr_animation_track);
	
	return Qnil;
	
}
static VALUE getPlaying(VALUE self){
	// Inverse of hasEnded()
	Oni_AnimationTrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_AnimationTrackPtr, ptr_animation_track);
	
	return Qnil;
	
}
