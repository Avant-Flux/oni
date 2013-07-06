#include <stdio.h>
#include <stdlib.h>
#include <ruby.h>

#include <OgreInterface.h>

void Init_Oni_Model(VALUE outer);

static VALUE alloc(VALUE class);

static VALUE initialize(VALUE self, VALUE window, VALUE name, VALUE filename);
static VALUE update(VALUE self, VALUE dt);

static VALUE attachObjectToBone(VALUE self, VALUE name, VALUE obj);
static VALUE detachObjectFromBone(VALUE self, VALUE obj);
static VALUE isAttachedToBone(VALUE self);

static VALUE getVisible(VALUE self);
static VALUE setVisible(VALUE self, VALUE visible);

static VALUE setCastShadows(VALUE self, VALUE enabled);
static VALUE getCastShadows(VALUE self);

static VALUE getBoundingBoxWidth(VALUE self);
static VALUE getBoundingBoxDepth(VALUE self);
static VALUE getBoundingBoxHeight(VALUE self);

static VALUE setPosition(VALUE self, VALUE pos);
static VALUE translate(int argc, VALUE *argv, VALUE self);
	// static VALUE translate(VALUE self, VALUE x, VALUE y, VALUE z, VALUE transform_space);


static VALUE resetOrientation(VALUE self);
static VALUE getOrientation(int argc, VALUE *argv, VALUE self);
static VALUE setOrientation(VALUE self, VALUE quat);

static VALUE rotate3D(VALUE self, VALUE quat);
static VALUE pitch(VALUE self, VALUE radians);
static VALUE yaw(VALUE self, VALUE radians);
static VALUE roll(VALUE self, VALUE radians);

static VALUE getRotation(VALUE self);
static VALUE setRotation(VALUE self, VALUE radians);
// static VALUE rotateTo(VALUE self, VALUE x, VALUE y, VALUE z);

static VALUE scale(VALUE self, VALUE x, VALUE y, VALUE z);
static VALUE setScale(VALUE self, VALUE scale);
