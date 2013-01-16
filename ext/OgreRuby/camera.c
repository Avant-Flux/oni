#include "camera.h"

VALUE Init_OgreCamera(VALUE outer){
	VALUE klass = rb_define_class_under(outer, "Camera", rb_cObject);
	
	// rb_define_alloc_func(klass, alloc);
	rb_define_method(klass, "initialize", initialize, 3);
	
	rb_define_method(klass, "fov", getFOV, 0);
	rb_define_method(klass, "fov=", setFOV, 1);
	rb_define_method(klass, "position", getPosition, 0);
	rb_define_method(klass, "position=", setPosition, 1);
	rb_define_method(klass, "look_at", lookAt, 1);
	rb_define_method(klass, "near_clip_distance", nearClipDistance, 1);
}

// static VALUE alloc(VALUE class){
// 	// Do nothing, as all memory allocation is handled by Ogre internally
	
// 	return Qnil;
// }

static VALUE initialize(VALUE self, VALUE window, VALUE name, VALUE z_order){
	// Camera.new(window, name)
	
	// Get window
	Ogre_WindowPtr ptr_window;;
	Data_Get_Struct(window, Ogre_WindowPtr, ptr_window);
	
	// Get name of camera
	char* string_name = StringValueCStr(name);
	
	// Create camera
	Ogre_CameraPtr ptr_camera = Ogre_Camera_new(ptr_window, string_name);
	
	// Initialize camera - establish viewport
	int int_z_order = FIX2INT(z_order); // NOTE: Assumes number is integral
	Ogre_Camera_initialize(ptr_camera, ptr_window, int_z_order);
	
	// Wrap camera so it is visible to Ruby
	VALUE class = rb_obj_class(self);
	VALUE data = Data_Wrap_Struct(class, NULL, Ogre_Camera_delete, ptr_camera);
	
	return Qnil;
}

// Custom functions
static VALUE follow(VALUE self, VALUE entity){
	// Causes the camera to follow the selected entity
	Ogre_CameraPtr ptr_camera;
	Data_Get_Struct(self, Ogre_CameraPtr, ptr_camera);
	
	return Qnil;
}

// Pass-through to Ogre methods

static VALUE getFOV(VALUE self){
	Ogre_CameraPtr ptr_camera;
	Data_Get_Struct(self, Ogre_CameraPtr, ptr_camera);
	
	return Qnil;
}

static VALUE setFOV(VALUE self, VALUE fov){
	Ogre_CameraPtr ptr_camera;
	Data_Get_Struct(self, Ogre_CameraPtr, ptr_camera);
	
	return Qnil;
}

static VALUE getPosition(VALUE self){
	Ogre_CameraPtr ptr_camera;
	Data_Get_Struct(self, Ogre_CameraPtr, ptr_camera);
	
	return Qnil;
}

static VALUE setPosition(VALUE self, VALUE pos){
	Ogre_CameraPtr ptr_camera;
	Data_Get_Struct(self, Ogre_CameraPtr, ptr_camera);
	
	return Qnil;
}

static VALUE lookAt(VALUE self, VALUE vector){
	Ogre_CameraPtr ptr_camera;
	Data_Get_Struct(self, Ogre_CameraPtr, ptr_camera);
	
	return Qnil;
}

static VALUE nearClipDistance(VALUE self){
	Ogre_CameraPtr ptr_camera;
	Data_Get_Struct(self, Ogre_CameraPtr, ptr_camera);
	
	return Qnil;
}
