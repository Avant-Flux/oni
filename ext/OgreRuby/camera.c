#include "camera.h"

// TODO: Fix "warning: assignment from incompatible pointer type" on Data_Get_Struct

VALUE Init_OgreCamera(VALUE outer){
	VALUE klass = rb_define_class_under(outer, "Camera", rb_cObject);
	
	rb_define_alloc_func(klass, alloc);
	rb_define_method(klass, "initialize", initialize, 3);
	
	rb_define_method(klass, "fov", getFOV, 0);
	rb_define_method(klass, "fov=", setFOV, 1);
	rb_define_method(klass, "position", getPosition, 0);
	rb_define_method(klass, "position=", setPosition, 1);
	rb_define_method(klass, "look_at", lookAt, 1);
	rb_define_method(klass, "near_clip_distance", getNearClipDistance, 0);
	rb_define_method(klass, "near_clip_distance=", setNearClipDistance, 1);
	
	return Qnil;
}

static VALUE alloc(VALUE class){
	// Do nothing, as all memory allocation is handled by Ogre internally
	cameraContainer* container = ALLOC(cameraContainer);
	VALUE data = Data_Wrap_Struct(class, NULL, delete, container);
	
	return data;
}

static VALUE initialize(VALUE self, VALUE window, VALUE name, VALUE z_order){
	// Camera.new(window, name)
	
	// Get window
	Ogre_WindowPtr ptr_window;;
	Data_Get_Struct(window, Ogre_WindowPtr, ptr_window);
	
	// Get name of camera
	char* string_name = StringValueCStr(name);
	
	// Get camera container
	cameraContainer* container;
	Data_Get_Struct(self, cameraContainer*, container);
	
	// Create camera
	Ogre_CameraPtr ptr_camera = Ogre_Camera_new(ptr_window, string_name);
	
	// Initialize camera - establish viewport
	int int_z_order = FIX2INT(z_order); // NOTE: Assumes number is integral
	Ogre_Camera_initialize(ptr_camera, ptr_window, int_z_order);
	
	// Put camera in container
	container->camera = ptr_camera;
	
	return Qnil;
}

// Custom functions
static VALUE follow(VALUE self, VALUE entity){
	// Causes the camera to follow the selected entity
	cameraContainer* container;
	Data_Get_Struct(self, cameraContainer*, container);
	Ogre_CameraPtr ptr_camera = container->camera;
	
	
	return Qnil;
}

// Pass-through to Ogre methods

static VALUE getFOV(VALUE self){
	cameraContainer* container;
	Data_Get_Struct(self, cameraContainer*, container);
	Ogre_CameraPtr ptr_camera = container->camera;
	
	
	
	return Qnil;
}

static VALUE setFOV(VALUE self, VALUE fov){
	cameraContainer* container;
	Data_Get_Struct(self, cameraContainer*, container);
	Ogre_CameraPtr ptr_camera = container->camera;
	
	double double_angle = NUM2DBL(fov);
	
	Ogre_Camera_setFOV(ptr_camera, double_angle);
	
	return Qnil;
}

static VALUE getPosition(VALUE self){
	cameraContainer* container;
	Data_Get_Struct(self, cameraContainer*, container);
	Ogre_CameraPtr ptr_camera = container->camera;
	
	
	
	return Qnil;
}

static VALUE setPosition(VALUE self, VALUE pos){
	cameraContainer* container;
	Data_Get_Struct(self, cameraContainer*, container);
	Ogre_CameraPtr ptr_camera = container->camera;
	
	VALUE x = rb_ary_entry(pos, 0);
	VALUE y = rb_ary_entry(pos, 1);
	VALUE z = rb_ary_entry(pos, 2);
	double double_x = NUM2DBL(x);
	double double_y = NUM2DBL(y);
	double double_z = NUM2DBL(z);
	
	Ogre_Camera_setPosition(ptr_camera, double_x, double_y, double_z);
	
	return Qnil;
}

static VALUE lookAt(VALUE self, VALUE vector){
	cameraContainer* container;
	Data_Get_Struct(self, cameraContainer*, container);
	Ogre_CameraPtr ptr_camera = container->camera;
	
	VALUE x = rb_ary_entry(vector, 0);
	VALUE y = rb_ary_entry(vector, 1);
	VALUE z = rb_ary_entry(vector, 2);
	double double_x = NUM2DBL(x);
	double double_y = NUM2DBL(y);
	double double_z = NUM2DBL(z);
	
	Ogre_Camera_lookAt(ptr_camera, double_x, double_y, double_z);
	
	return Qnil;
}

static VALUE getNearClipDistance(VALUE self){
	cameraContainer* container;
	Data_Get_Struct(self, cameraContainer*, container);
	Ogre_CameraPtr ptr_camera = container->camera;
	
	double double_distance = Ogre_Camera_getNearClipDistance(ptr_camera);
	
	VALUE distance = rb_float_new(double_distance);
	
	return distance;
}

static VALUE setNearClipDistance(VALUE self, VALUE distance){
	cameraContainer* container;
	Data_Get_Struct(self, cameraContainer*, container);
	Ogre_CameraPtr ptr_camera = container->camera;
	
	double double_distance = NUM2DBL(distance);
	
	Ogre_Camera_setNearClipDistance(ptr_camera, double_distance);
	
	return Qnil;
}

static void delete(cameraContainer* container){
	// TODO: Fix segfault on exit
	Ogre_Camera_delete(container->camera);
	free(container);
}