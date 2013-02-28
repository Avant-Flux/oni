#include "light.h"

void Init_Oni_Light(VALUE outer){
	VALUE klass = rb_define_class_under(outer, "Light", rb_cObject);
	
	rb_define_alloc_func(klass, alloc);
	rb_define_method(klass, "initialize", initialize, 2);
	rb_define_method(klass, "update", update, 1);
}

static VALUE alloc(VALUE class){
	Oni_LightPtr light = Oni_Light_new();
	VALUE data = Data_Wrap_Struct(class, NULL, Oni_Light_delete, light);
	
	return data;
}

static VALUE initialize(VALUE self, VALUE window, VALUE name){
	Oni_LightPtr ptr_light;
	Data_Get_Struct(self, Oni_LightPtr, ptr_light);
	
	Ogre_WindowPtr ptr_window;
	Data_Get_Struct(window, Ogre_WindowPtr, ptr_window);
	
	char* str_name = StringValueCStr(name);
	
	Oni_Light_initialize(ptr_light, ptr_window, str_name);
	
	return Qnil;
}

static VALUE update(VALUE self, VALUE dt){
	Oni_LightPtr ptr_light;
	Data_Get_Struct(self, Oni_LightPtr, ptr_light);
	
	double double_dt = NUM2DBL(dt);
	
	Oni_Light_update(ptr_light, double_dt);
	
	return Qnil;
}