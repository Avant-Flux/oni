#include <stdio.h>
#include <stdlib.h>
#include <ruby.h>

#include <OgreInterface.h>

VALUE Init_Oni_AnimationTrack(VALUE outer);

static VALUE alloc(VALUE class);

static VALUE initialize(VALUE self, VALUE model);
static VALUE update(VALUE self, VALUE dt);

static VALUE fadeIn(VALUE self, VALUE time, VALUE block);
static VALUE fadeOut(VALUE self, VALUE time, VALUE block);

static VALUE setWeight(VALUE self, VALUE weight);
static VALUE getWeight(VALUE self);

static VALUE setTime(VALUE self, VALUE time);
static VALUE getTime(VALUE self);

static VALUE setLoop(VALUE self, VALUE loop);
static VALUE getLoop(VALUE self);



static VALUE getLength(VALUE self);
// Alias: duration

static VALUE setPlaybackRate(VALUE self, VALUE rate);
static VALUE getPlaybackRate(VALUE self);

static VALUE setEnabled(VALUE self, VALUE enabled);
static VALUE getEnabled(VALUE self);

static VALUE hasEnded(VALUE self); // Part of Ogre::AnimationState
static VALUE getPlaying(VALUE self); // Inverse of hasEnded()

