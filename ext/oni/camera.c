#include "camera.h"

// TODO: Fix "warning: assignment from incompatible pointer type" on Data_Get_Struct

void Init_Oni_Camera(VALUE outer){
	VALUE klass = rb_define_class_under(outer, "Camera", rb_cObject);
	
	rb_define_alloc_func(klass, alloc);
	rb_define_method(klass, "initialize", initialize, 3);
	
	
	rb_define_method(klass, "position", getPosition, 0);
	rb_define_method(klass, "position=", setPosition, 1);
	rb_define_method(klass, "look_at", lookAt, 1);
	rb_define_method(klass, "near_clip_distance", getNearClipDistance, 0);
	rb_define_method(klass, "near_clip_distance=", setNearClipDistance, 1);
	
	rb_define_method(klass, "projection_type=", setProjectionType, 1);
	
	rb_define_method(klass, "fov", getFOV, 0);
	rb_define_method(klass, "fov=", setFOV, 1);
	
	rb_define_method(klass, "ortho_window_size=", setOrthoWindow, 1); // arg is [width, height]
	rb_define_method(klass, "ortho_window_height=", setOrthoWindowHeight, 1);
	rb_define_method(klass, "ortho_window_width=", setOrthoWindowWidth, 1);
	rb_define_method(klass, "ortho_window_height", getOrthoWindowHeight, 0);
	rb_define_method(klass, "ortho_window_width", getOrthoWindowWidth, 0);
}

static VALUE alloc(VALUE class){
	// Do nothing, as all memory allocation is handled by Ogre internally
	cameraContainer* container = ALLOC(cameraContainer);
	VALUE data = Data_Wrap_Struct(class, NULL, delete_camera, container);
	
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
	
	double dbl_distance = Ogre_Camera_getNearClipDistance(ptr_camera);
	
	VALUE distance = rb_float_new(dbl_distance);
	
	return distance;
}

static VALUE setNearClipDistance(VALUE self, VALUE distance){
	cameraContainer* container;
	Data_Get_Struct(self, cameraContainer*, container);
	Ogre_CameraPtr ptr_camera = container->camera;
	
	double dbl_distance = NUM2DBL(distance);
	
	Ogre_Camera_setNearClipDistance(ptr_camera, dbl_distance);
	
	return Qnil;
}

static VALUE setProjectionType(VALUE self, VALUE projection_type){
	cameraContainer* container;
	Data_Get_Struct(self, cameraContainer*, container);
	Ogre_CameraPtr ptr_camera = container->camera;
	
	ID ortho = rb_intern("orthographic");
	ID persp = rb_intern("perspective");
	
	ID type = SYM2ID(projection_type);
	
	OniCameraProjectionType pt;
	if(type == ortho)
	{
		pt = ORTHOGRAPHIC;
	}
	else if(type == persp){
		pt = PERSPECTIVE;
	}
	else
	{
		// TODO: Throw exception - invalid argument
	}
	
	Ogre_Camera_setProjectionType(ptr_camera, pt);
	
	return Qnil;
}

// Pass-through to Ogre methods

static VALUE getFOV(VALUE self){
	cameraContainer* container;
	Data_Get_Struct(self, cameraContainer*, container);
	Ogre_CameraPtr ptr_camera = container->camera;
	
	double dbl_fov = Ogre_Camera_getFOV(ptr_camera);
	VALUE fov = rb_float_new(dbl_fov);
	
	return fov;
}

static VALUE setFOV(VALUE self, VALUE fov){
	cameraContainer* container;
	Data_Get_Struct(self, cameraContainer*, container);
	Ogre_CameraPtr ptr_camera = container->camera;
	
	double double_angle = NUM2DBL(fov);
	
	Ogre_Camera_setFOV(ptr_camera, double_angle);
	
	return Qnil;
}

static VALUE setOrthoWindow(VALUE self, VALUE dimensions){
	cameraContainer* container;
	Data_Get_Struct(self, cameraContainer*, container);
	Ogre_CameraPtr ptr_camera = container->camera;
	
	VALUE w = rb_ary_entry(dimensions, 0);
	VALUE h = rb_ary_entry(dimensions, 1);
	Ogre_Camera_setOrthoWindow(ptr_camera, NUM2DBL(w), NUM2DBL(h));
	
	return Qnil;
}

static VALUE setOrthoWindowHeight(VALUE self, VALUE h){
	cameraContainer* container;
	Data_Get_Struct(self, cameraContainer*, container);
	Ogre_CameraPtr ptr_camera = container->camera;
	
	Ogre_Camera_setOrthoWindowHeight(ptr_camera, NUM2DBL(h));
	
	return Qnil;
}

static VALUE setOrthoWindowWidth(VALUE self, VALUE w){
	cameraContainer* container;
	Data_Get_Struct(self, cameraContainer*, container);
	Ogre_CameraPtr ptr_camera = container->camera;
	
	Ogre_Camera_setOrthoWindowWidth(ptr_camera, NUM2DBL(w));
	
	return Qnil;
}

static VALUE getOrthoWindowHeight(VALUE self){
	cameraContainer* container;
	Data_Get_Struct(self, cameraContainer*, container);
	Ogre_CameraPtr ptr_camera = container->camera;
	
	double dbl_height = Ogre_Camera_getOrthoWindowHeight(ptr_camera);
	VALUE height = rb_float_new(dbl_height);
	
	return height;
}

static VALUE getOrthoWindowWidth(VALUE self){
	cameraContainer* container;
	Data_Get_Struct(self, cameraContainer*, container);
	Ogre_CameraPtr ptr_camera = container->camera;
	
	double dbl_width = Ogre_Camera_getOrthoWindowWidth(ptr_camera);
	VALUE width = rb_float_new(dbl_width);
	
	return width;
}


static void delete_camera(cameraContainer* container){
	// TODO: EXAMINE - Seems like destructor is not being called.
	printf("---C-EXTENSION!!! Delete camera\n");
	Ogre_Camera_delete(container->camera);
	free(container);
}