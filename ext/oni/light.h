#include <stdio.h>
#include <stdlib.h>
#include <ruby.h>

#include <OgreInterface.h>

void Init_Oni_Light(VALUE outer);

static VALUE alloc(VALUE class);

static VALUE initialize(int argc, VALUE *argv, VALUE self);
static VALUE update(VALUE self, VALUE dt);

static VALUE getVisible(VALUE self);
static VALUE setVisible(VALUE self, VALUE visible);

static VALUE setType(VALUE self, VALUE light_type);
static VALUE getType(VALUE self);
	
static VALUE setPosition(VALUE self, VALUE pos);
	// static VALUE setPosition(VALUE self, VALUE x, VALUE y, VALUE z);
static VALUE getPosition(VALUE self);

static VALUE setDirection(VALUE self, VALUE direction_vector);
static VALUE getDirection(VALUE self);

static VALUE setDiffuseColor(VALUE self, VALUE color);
static VALUE setSpecularColor(VALUE self, VALUE color);

static VALUE setAttenuation(VALUE self, VALUE attenuation);

static VALUE setPowerScale(VALUE self, VALUE power);

static VALUE setShadowFarDistance(VALUE self, VALUE distance);
static VALUE resetShadowFarDistance(VALUE self);
static VALUE getShadowFarDistance(VALUE self);
static VALUE getShadowFarDistanceSquared(VALUE self);

static VALUE setShadowNearClipDistance(VALUE self, VALUE nearClip);
static VALUE getShadowNearClipDistance(VALUE self);
static VALUE setShadowFarClipDistance(VALUE self, VALUE farClip);
static VALUE getShadowFarClipDistance(VALUE self);