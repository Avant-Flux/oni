#include <stdio.h>
#include <stdlib.h>
#include <ruby.h>

#include <OgreInterface.h>

void Init_Oni_Animation_Track(VALUE outer);

VALUE rb_Oni_Animation_Track_new(Oni_Animation_TrackPtr ptr_track);

static VALUE update(VALUE self, VALUE dt);

static VALUE enable(VALUE self);
static VALUE disable(VALUE self);

static VALUE setWeight(VALUE self, VALUE weight);
static VALUE getWeight(VALUE self);

static VALUE setTime(VALUE self, VALUE t);
static VALUE getTime(VALUE self);

static VALUE setLoop(VALUE self, VALUE loop);
static VALUE getLoop(VALUE self);


static VALUE getName(VALUE self);

static VALUE getLength(VALUE self);
// Alias: duration

static VALUE setPlaybackRate(VALUE self, VALUE rate);
static VALUE getPlaybackRate(VALUE self);

static VALUE setEnabled(VALUE self, VALUE enabled);
static VALUE getEnabled(VALUE self);

static VALUE hasEnded(VALUE self); // Part of Ogre::AnimationState
static VALUE getPlaying(VALUE self); // Inverse of hasEnded()

