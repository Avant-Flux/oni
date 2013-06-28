#include <stdio.h>
#include <stdlib.h>
#include <ruby.h>

#include <OgreInterface.h>

typedef struct cameraContainer{
	Ogre_CameraPtr camera;
} cameraContainer;


void Init_Oni_Camera(VALUE outer);

static VALUE alloc(VALUE class);
static VALUE initialize(VALUE self, VALUE window, VALUE name, VALUE z_order);

static VALUE follow(VALUE self, VALUE entity);

static VALUE getPosition(VALUE self);
static VALUE setPosition(VALUE self, VALUE pos);
static VALUE lookAt(VALUE self, VALUE vector);
static VALUE getNearClipDistance(VALUE self);
static VALUE setNearClipDistance(VALUE self, VALUE distance);

static VALUE setProjectionType(VALUE self, VALUE projection_type);

static VALUE getFOV(VALUE self);
static VALUE setFOV(VALUE self, VALUE fov);

static VALUE setOrthoWindow(VALUE self, VALUE dimensions);
static VALUE setOrthoWindowHeight(VALUE self, VALUE h);
static VALUE setOrthoWindowWidth(VALUE self, VALUE w);
static VALUE getOrthoWindowHeight(VALUE self);
static VALUE getOrthoWindowWidth(VALUE self);

static void delete_camera(cameraContainer* container);