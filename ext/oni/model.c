#include "model.h"

void Init_Oni_Model(VALUE outer){
	VALUE klass = rb_define_class_under(outer, "Model", rb_cObject);
	
	rb_define_alloc_func(klass, alloc);
	rb_define_method(klass, "initialize", initialize, 3);
	rb_define_method(klass, "update", update, 1);
	
	rb_define_method(klass, "visible=", setVisible, 1);
	rb_define_method(klass, "visible?", getVisible, 0);
	
	rb_define_method(klass, "position=", setPosition, 1);
	rb_define_method(klass, "translate", translate, 3);
	
	rb_define_method(klass, "pitch", pitch, 1);
	rb_define_method(klass, "yaw", yaw, 1);
	rb_define_method(klass, "roll", roll, 1);
	rb_define_method(klass, "rotate_to", rotateTo, 3);
	
	rb_define_method(klass, "rotation=", setRotation, 1);
	
	rb_define_method(klass, "scale", scale, 3);
	rb_define_method(klass, "scale=", setScale, 1);
}

static VALUE alloc(VALUE class){
	Oni_ModelPtr model = Oni_Model_new();
	VALUE data = Data_Wrap_Struct(class, NULL, Oni_Model_delete, model);
	
	return data;
}

static VALUE initialize(VALUE self, VALUE window, VALUE name, VALUE filename){	
	// Ruby interface: Model.new(window, "name", "name.mesh")
	
	Oni_ModelPtr ptr_model;
	Data_Get_Struct(self, Oni_ModelPtr, ptr_model);
	
	Ogre_WindowPtr ptr_window;
	Data_Get_Struct(window, Ogre_WindowPtr, ptr_window);
	
	char* string_name = StringValueCStr(name);
	char* string_filename = StringValueCStr(filename);
	
	Oni_Model_initialize(ptr_model, ptr_window, string_name, string_filename);
	
	return Qnil;
}

static VALUE update(VALUE self, VALUE dt){
	Oni_ModelPtr ptr_model;
	Data_Get_Struct(self, Oni_ModelPtr, ptr_model);
	
	double double_dt = NUM2DBL(dt);
	
	Oni_Model_update(ptr_model, double_dt);
	
	return Qnil;
}

static VALUE getVisible(VALUE self)
{
	Oni_ModelPtr ptr_model;
	Data_Get_Struct(self, Oni_ModelPtr, ptr_model);
	
	if(Oni_Model_getVisible(ptr_model))
	{
		return Qtrue;
	}
	else
	{
		return Qfalse;
	}
}

static VALUE setVisible(VALUE self, VALUE visible)
{
	Oni_ModelPtr ptr_model;
	Data_Get_Struct(self, Oni_ModelPtr, ptr_model);
	
	Oni_Model_setVisible(ptr_model, RTEST(visible));
	
	return Qnil;
}

static VALUE setPosition(VALUE self, VALUE pos)
{
	Oni_ModelPtr ptr_model;
	Data_Get_Struct(self, Oni_ModelPtr, ptr_model);
	
	
	// TODO: Take single argument of one array - interpreted as a vector
	// RARRAY(pos)->ptr[0];
	VALUE x = rb_ary_entry(pos, 0);
	VALUE y = rb_ary_entry(pos, 1);
	VALUE z = rb_ary_entry(pos, 2);
	
	double dbl_x = NUM2DBL(x);
	double dbl_y = NUM2DBL(y);
	double dbl_z = NUM2DBL(z);
	
	Oni_Model_setPosition(ptr_model, dbl_x, dbl_y, dbl_z);
	
	return Qnil;
}

static VALUE translate(VALUE self, VALUE x, VALUE y, VALUE z){
	Oni_ModelPtr ptr_model;
	Data_Get_Struct(self, Oni_ModelPtr, ptr_model);
	
	double dbl_x = NUM2DBL(x);
	double dbl_y = NUM2DBL(y);
	double dbl_z = NUM2DBL(z);
	
	Oni_Model_translate(ptr_model, dbl_x, dbl_y, dbl_z);
	
	return Qnil;
}

static VALUE pitch(VALUE self, VALUE radians){
	Oni_ModelPtr ptr_model;
	Data_Get_Struct(self, Oni_ModelPtr, ptr_model);
	
	double dbl_radians = NUM2DBL(radians);
	Oni_Model_pitch(ptr_model, dbl_radians);
	
	return Qnil;
}

static VALUE yaw(VALUE self, VALUE radians){
	Oni_ModelPtr ptr_model;
	Data_Get_Struct(self, Oni_ModelPtr, ptr_model);
	
	double dbl_radians = NUM2DBL(radians);
	Oni_Model_yaw(ptr_model, dbl_radians);
	
	return Qnil;
}

static VALUE roll(VALUE self, VALUE radians){
	Oni_ModelPtr ptr_model;
	Data_Get_Struct(self, Oni_ModelPtr, ptr_model);
	
	double dbl_radians = NUM2DBL(radians);
	Oni_Model_roll(ptr_model, dbl_radians);
	
	return Qnil;
}

static VALUE rotateTo(VALUE self, VALUE x, VALUE y, VALUE z){
	Oni_ModelPtr ptr_model;
	Data_Get_Struct(self, Oni_ModelPtr, ptr_model);
	
	double dbl_x = NUM2DBL(x);
	double dbl_y = NUM2DBL(y);
	double dbl_z = NUM2DBL(z);
	
	Oni_Model_rotateTo(ptr_model, dbl_x,dbl_y,dbl_z);
	
	return Qnil;
}

static VALUE setRotation(VALUE self, VALUE radians){
	Oni_ModelPtr ptr_model;
	Data_Get_Struct(self, Oni_ModelPtr, ptr_model);
	
	double dbl_radians = NUM2DBL(radians);
	
	Oni_Model_setRotation(ptr_model, dbl_radians);
	
	return Qnil;
}

static VALUE scale(VALUE self, VALUE x, VALUE y, VALUE z){
	Oni_ModelPtr ptr_model;
	Data_Get_Struct(self, Oni_ModelPtr, ptr_model);
	
	double dbl_x = NUM2DBL(x);
	double dbl_y = NUM2DBL(y);
	double dbl_z = NUM2DBL(z);
	
	Oni_Model_scale(ptr_model, dbl_x, dbl_y, dbl_z);
	
	return Qnil;
}

static VALUE setScale(VALUE self, VALUE scale){
	Oni_ModelPtr ptr_model;
	Data_Get_Struct(self, Oni_ModelPtr, ptr_model);
	
	// TODO: Take single argument of one array - interpreted as a vector
	// RARRAY(scale)->ptr[0];
	VALUE x = rb_ary_entry(scale, 0);
	VALUE y = rb_ary_entry(scale, 1);
	VALUE z = rb_ary_entry(scale, 2);
	
	double dbl_x = NUM2DBL(x);
	double dbl_y = NUM2DBL(y);
	double dbl_z = NUM2DBL(z);
	
	Oni_Model_setScale(ptr_model, dbl_x, dbl_y, dbl_z);
	
	return Qnil;
}