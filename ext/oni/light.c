#include "light.h"

void Init_Oni_Light(VALUE outer){
	VALUE klass = rb_define_class_under(outer, "Light", rb_cObject);
	
	rb_define_alloc_func(klass, alloc);
	rb_define_method(klass, "initialize", initialize, 2);
	rb_define_method(klass, "update", update, 1);
	
	rb_define_method(klass, "visible", getVisible, 0);
	rb_define_method(klass, "visible=", setVisible, 1);
	
	rb_define_method(klass, "type=", setType, 1);
	rb_define_method(klass, "position=", setPosition, 1);
	
	rb_define_method(klass, "diffuse=", setDiffuseColor, 1);
	rb_define_method(klass, "specular=", setSpecularColor, 1);
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

static VALUE getVisible(VALUE self)
{
	Oni_LightPtr ptr_light;
	Data_Get_Struct(self, Oni_LightPtr, ptr_light);
	
	if(Oni_Light_getVisible(ptr_light))
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
	Oni_LightPtr ptr_light;
	Data_Get_Struct(self, Oni_LightPtr, ptr_light);
	
	Oni_Light_setVisible(ptr_light, RTEST(visible));
	
	return Qnil;
}

static VALUE setType(VALUE self, VALUE light_type){
	Oni_LightPtr ptr_light;
	Data_Get_Struct(self, Oni_LightPtr, ptr_light);
	
	ID point = rb_intern("point");
	ID directional = rb_intern("directional");
	ID spotlight = rb_intern("spotlight");
	
	if(SYM2ID(light_type)){
		
	}
	
	ID type = SYM2ID(light_type);
	if(type == point){
		Oni_Light_setType(ptr_light, 0);
	}else if(type == directional){
		Oni_Light_setType(ptr_light, 1);
	}else if(type == spotlight){
		Oni_Light_setType(ptr_light, 2);
	}
	
	return Qnil;
}

static VALUE setPosition(VALUE self, VALUE pos){
	Oni_LightPtr ptr_light;
	Data_Get_Struct(self, Oni_LightPtr, ptr_light);
	
	// TODO: Take single argument of one array - interpreted as a vector
	// RARRAY(pos)->ptr[0];
	VALUE x = rb_ary_entry(pos, 0);
	VALUE y = rb_ary_entry(pos, 1);
	VALUE z = rb_ary_entry(pos, 2);
	
	double dbl_x = NUM2DBL(x);
	double dbl_y = NUM2DBL(y);
	double dbl_z = NUM2DBL(z);
	
	Oni_Light_setPosition(ptr_light, dbl_x, dbl_y, dbl_z);
	
	return Qnil;
}

static VALUE setDiffuseColor(VALUE self, VALUE color){
	Oni_LightPtr ptr_light;
	Data_Get_Struct(self, Oni_LightPtr, ptr_light);
	
	// TODO: Take single argument of one array - interpreted as a vector
	// RARRAY(color)->ptr[0];
	VALUE x = rb_ary_entry(color, 0);
	VALUE y = rb_ary_entry(color, 1);
	VALUE z = rb_ary_entry(color, 2);
	
	double dbl_x = NUM2DBL(x);
	double dbl_y = NUM2DBL(y);
	double dbl_z = NUM2DBL(z);
	
	Oni_Light_setDiffuseColor(ptr_light, dbl_x, dbl_y, dbl_z);
	
	return Qnil;
}

static VALUE setSpecularColor(VALUE self, VALUE color){
	Oni_LightPtr ptr_light;
	Data_Get_Struct(self, Oni_LightPtr, ptr_light);
	
	// TODO: Take single argument of one array - interpreted as a vector
	// RARRAY(color)->ptr[0];
	VALUE x = rb_ary_entry(color, 0);
	VALUE y = rb_ary_entry(color, 1);
	VALUE z = rb_ary_entry(color, 2);
	
	double dbl_x = NUM2DBL(x);
	double dbl_y = NUM2DBL(y);
	double dbl_z = NUM2DBL(z);
	
	Oni_Light_setSpecularColor(ptr_light, dbl_x, dbl_y, dbl_z);
	
	return Qnil;
}
