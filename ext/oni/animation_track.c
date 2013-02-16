#include "animation_track.h"

// This class exists only as a Ruby-level handle to a C++ made and managed resource
// All memory management etc for these objects will be handled at the C++ level.

void Init_Oni_Animation_Track(VALUE outer){
	VALUE klass = rb_define_class_under(outer, "Track", rb_cObject);
	
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
	
	// Aliases
	rb_define_alias(klass, "duration", "length");
	rb_define_alias(klass, "size", "length");
}

VALUE rb_Oni_Animation_Track_new(Oni_Animation_TrackPtr ptr_track){
	// Should only be visible at C level
	// This class should essentially be a private nested class
	// It is merely a handle for things managed by Oni::Animation
	
	// TODO: Consider making this function "inline"
	
	VALUE module = rb_const_get(rb_cObject, rb_intern("Oni"));
	VALUE outer_end = rb_const_get(module, rb_intern("Animation"));
	VALUE class = rb_const_get(outer_end, rb_intern("Track"));
	
	VALUE track = Data_Wrap_Struct(class, NULL, NULL, ptr_track);
	
	return track;
}

static VALUE update(VALUE self, VALUE dt){
	Oni_Animation_TrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_Animation_TrackPtr, ptr_animation_track);
	
	double double_dt = NUM2DBL(dt);
	
	Oni_AnimationTrack_update(ptr_animation_track, double_dt);
	
	return Qnil;
}

static VALUE fadeIn(VALUE self, VALUE time, VALUE block){
	Oni_Animation_TrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_Animation_TrackPtr, ptr_animation_track);
	
	// fade(time) {|influence, dt|}
	// fade(time, &block)
	
	
	return Qnil;
}

static VALUE fadeOut(VALUE self, VALUE time, VALUE block){
	Oni_Animation_TrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_Animation_TrackPtr, ptr_animation_track);
	
	// fade(time) {|influence, dt|}
	// fade(time, &block)
	
	
	return Qnil;
}

static VALUE setWeight(VALUE self, VALUE weight){
	Oni_Animation_TrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_Animation_TrackPtr, ptr_animation_track);
	
	return Qnil;
}

static VALUE getWeight(VALUE self){
	Oni_Animation_TrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_Animation_TrackPtr, ptr_animation_track);
	
	return Qnil;
}

static VALUE setTime(VALUE self, VALUE time){
	Oni_Animation_TrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_Animation_TrackPtr, ptr_animation_track);
	
	return Qnil;
}

static VALUE getTime(VALUE self){
	Oni_Animation_TrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_Animation_TrackPtr, ptr_animation_track);
	
	return Qnil;
}

static VALUE setLoop(VALUE self, VALUE loop){
	Oni_Animation_TrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_Animation_TrackPtr, ptr_animation_track);
	
	return Qnil;
}

static VALUE getLoop(VALUE self){
	Oni_Animation_TrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_Animation_TrackPtr, ptr_animation_track);
	
	return Qnil;
}

static VALUE getLength(VALUE self){
	Oni_Animation_TrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_Animation_TrackPtr, ptr_animation_track);
	
	return Qnil;
	
}

static VALUE setPlaybackRate(VALUE self, VALUE rate){
	Oni_Animation_TrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_Animation_TrackPtr, ptr_animation_track);
	
	return Qnil;
}

static VALUE getPlaybackRate(VALUE self){
	Oni_Animation_TrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_Animation_TrackPtr, ptr_animation_track);
	
	return Qnil;
}

static VALUE setEnabled(VALUE self, VALUE enabled){
	Oni_Animation_TrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_Animation_TrackPtr, ptr_animation_track);
	
	return Qnil;
}

static VALUE getEnabled(VALUE self){
	Oni_Animation_TrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_Animation_TrackPtr, ptr_animation_track);
	
	return Qnil;
}

static VALUE hasEnded(VALUE self){
	// Part of Ogre::AnimationState
	Oni_Animation_TrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_Animation_TrackPtr, ptr_animation_track);
	
	return Qnil;
	
}
static VALUE getPlaying(VALUE self){
	// Inverse of hasEnded()
	Oni_Animation_TrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_Animation_TrackPtr, ptr_animation_track);
	
	return Qnil;
	
}