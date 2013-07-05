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


static VALUE getPosition(VALUE self);
static VALUE setPosition(VALUE self, VALUE pos);
static VALUE translate(int argc, VALUE *argv, VALUE self);
	// static VALUE translate(VALUE self, VALUE x, VALUE y, VALUE z, VALUE transform_space);

static VALUE resetOrientation(VALUE self);
static VALUE getOrientation(int argc, VALUE *argv, VALUE self);
	// static VALUE getOrientation(VALUE self, VALUE sym_quat_or_euler_angles);
static VALUE setOrientation(VALUE self, VALUE quat);
	// static VALUE setOrientation(VALUE self, VALUE w, VALUE x, VALUE y, VALUE z);

static VALUE rotate3D(VALUE self, VALUE quat);
static VALUE pitch(VALUE self, VALUE radians);
static VALUE yaw(VALUE self, VALUE radians);
static VALUE roll(VALUE self, VALUE radians);

// Manage 2D rotations in horizontal plane
// static VALUE getRotation(VALUE self);
// static VALUE setRotation(VALUE self, VALUE radians);



static VALUE setType(VALUE self, VALUE light_type);
static VALUE getType(VALUE self);
	
static VALUE setLightPosition(VALUE self, VALUE pos);
	// static VALUE setLightPosition(VALUE self, VALUE x, VALUE y, VALUE z);
static VALUE getLightPosition(VALUE self);

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