#include <stdio.h>
#include <stdlib.h>
#include <ruby.h>

#include <OgreInterface.h>

VALUE Init_OgreCamera(VALUE outer);

// static VALUE alloc(VALUE class);
static VALUE initialize(VALUE self, VALUE window, VALUE name);

static VALUE follow(VALUE self, VALUE entity);

static VALUE getFOV(VALUE self);
static VALUE setFOV(VALUE self, VALUE fov);
static VALUE getPosition(VALUE self);
static VALUE setPosition(VALUE self, VALUE pos);
static VALUE lookAt(VALUE self, VALUE vector);
static VALUE nearClipDistance(VALUE self);	