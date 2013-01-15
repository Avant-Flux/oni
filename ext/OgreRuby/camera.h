#include <stdio.h>
#include <stdlib.h>
#include <ruby.h>

#include <OgreInterface.h>

VALUE Init_OgreCamera(VALUE outer);

// static VALUE alloc(VALUE class);
static VALUE initialize(VALUE self, VALUE window, VALUE name);

static VALUE follow(VALUE self, VALUE entity);

static VALUE getFOV();
static VALUE setFOV();
static VALUE getPosition();
static VALUE setPosition();
static VALUE lookAt();
static VALUE nearClipDistance();