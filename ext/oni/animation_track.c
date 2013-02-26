#include "animation_track.h"

// This class exists only as a Ruby-level handle to a C++ made and managed resource
// All memory management etc for these objects will be handled at the C++ level.

void Init_Oni_Animation_Track(VALUE outer){
	VALUE klass = rb_define_class_under(outer, "Track", rb_cObject);
	
	rb_define_method(klass, "update", update, 1);
	
	rb_define_method(klass, "name", getName, 0);
	
	rb_define_method(klass, "enable", enable, 0);
	rb_define_method(klass, "disable", disable, 0);
	
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
	
	rb_define_method(klass, "enabled?", getEnabled, 0);	// Will the track apply influence?
	rb_define_method(klass, "ended?", hasEnded, 0);		// Has the track completed it's playback?
	// defined at ruby level, because it's easier
	// rb_define_method(klass, "playing?", getPlaying, 0);
	
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
	
	Oni_Animation_Track_update(ptr_animation_track, double_dt);
	
	return Qnil;
}

static VALUE enable(VALUE self){
	Oni_Animation_TrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_Animation_TrackPtr, ptr_animation_track);
	
	Oni_Animation_Track_setEnabled(ptr_animation_track, 1);
	
	return Qnil;
}

static VALUE disable(VALUE self){
	Oni_Animation_TrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_Animation_TrackPtr, ptr_animation_track);
	
	Oni_Animation_Track_setEnabled(ptr_animation_track, 0);
	
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
	
	double dbl_weight = NUM2DBL(weight);
	Oni_Animation_Track_setWeight(ptr_animation_track, dbl_weight);
	
	return Qnil;
}

static VALUE getWeight(VALUE self){
	Oni_Animation_TrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_Animation_TrackPtr, ptr_animation_track);
	
	double dbl_weight = Oni_Animation_Track_getWeight(ptr_animation_track);
	VALUE weight = rb_float_new(dbl_weight);
	
	return weight;
}

static VALUE setTime(VALUE self, VALUE t){
	Oni_Animation_TrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_Animation_TrackPtr, ptr_animation_track);
	
	double dbl_time = NUM2DBL(t);
	Oni_Animation_Track_setTimePosition(ptr_animation_track, dbl_time);
	
	return Qnil;
}

static VALUE getTime(VALUE self){
	Oni_Animation_TrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_Animation_TrackPtr, ptr_animation_track);
	
	double dbl_time = Oni_Animation_Track_getTimePosition(ptr_animation_track);
	VALUE time = rb_float_new(dbl_time);
	
	return time;
}

static VALUE setLoop(VALUE self, VALUE loop){
	Oni_Animation_TrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_Animation_TrackPtr, ptr_animation_track);
	
	int int_loop = RTEST(loop);
	Oni_Animation_Track_setLoop(ptr_animation_track, int_loop);
	
	return Qnil;
}

static VALUE getLoop(VALUE self){
	Oni_Animation_TrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_Animation_TrackPtr, ptr_animation_track);
	
	int int_loop = Oni_Animation_Track_getLoop(ptr_animation_track);
	VALUE loop = int_loop ? Qtrue : Qfalse;
	
	return loop;
}

static VALUE getName(VALUE self){
	Oni_Animation_TrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_Animation_TrackPtr, ptr_animation_track);
	
	// TODO: Check if memory needs to be freed
	char* char_name = Oni_Animation_Track_getAnimationName(ptr_animation_track);
	
	VALUE name = rb_str_new2(char_name);
	
	return name;
}

static VALUE getLength(VALUE self){
	Oni_Animation_TrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_Animation_TrackPtr, ptr_animation_track);
	
	double dbl_length = Oni_Animation_Track_getLength(ptr_animation_track);
	VALUE length = rb_float_new(dbl_length);
	
	return length;
}

static VALUE setPlaybackRate(VALUE self, VALUE rate){
	Oni_Animation_TrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_Animation_TrackPtr, ptr_animation_track);
	
	double dbl_rate = NUM2DBL(rate);
	Oni_Animation_Track_setPlaybackRate(ptr_animation_track, dbl_rate);
	
	return Qnil;
}

static VALUE getPlaybackRate(VALUE self){
	Oni_Animation_TrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_Animation_TrackPtr, ptr_animation_track);
	
	double dbl_rate = Oni_Animation_Track_getPlaybackRate(ptr_animation_track);
	VALUE rate = rb_float_new(dbl_rate);
	
	return rate;
}

static VALUE setEnabled(VALUE self, VALUE enabled){
	Oni_Animation_TrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_Animation_TrackPtr, ptr_animation_track);
	
	int int_enabled = RTEST(enabled);
	Oni_Animation_Track_setEnabled(ptr_animation_track, int_enabled);
	
	return Qnil;
}

static VALUE getEnabled(VALUE self){
	Oni_Animation_TrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_Animation_TrackPtr, ptr_animation_track);
	
	int int_enabled = Oni_Animation_Track_getEnabled(ptr_animation_track);
	VALUE enabled = int_enabled ? Qtrue : Qfalse;
	
	return enabled;
}

static VALUE hasEnded(VALUE self){
	// Part of Ogre::AnimationState
	Oni_Animation_TrackPtr ptr_animation_track;
	Data_Get_Struct(self, Oni_Animation_TrackPtr, ptr_animation_track);
	
	int int_ended = Oni_Animation_Track_hasEnded(ptr_animation_track);
	VALUE ended = int_ended ? Qtrue : Qfalse;
	
	return ended;
}
