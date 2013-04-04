#include "light.h"

void Init_Oni_Light(VALUE outer){
	VALUE klass = rb_define_class_under(outer, "Light", rb_cObject);
	
	rb_define_alloc_func(klass, alloc);
	rb_define_method(klass, "initialize", initialize, 2);
	rb_define_method(klass, "update", update, 1);
	
	rb_define_method(klass, "visible", getVisible, 0);
	rb_define_method(klass, "visible=", setVisible, 1);
	
	rb_define_method(klass, "type=", setType, 1);
	rb_define_method(klass, "type", getType, 0);
	
	rb_define_method(klass, "position=", setPosition, 1);
	rb_define_method(klass, "position", getPosition, 0);
	
	rb_define_method(klass, "direction=", setDirection, 1);
	rb_define_method(klass, "direction", getDirection, 0);
	
	rb_define_method(klass, "diffuse=", setDiffuseColor, 1);
	rb_define_method(klass, "specular=", setSpecularColor, 1);
	
	// [dbl_range, dbl_constant, dbl_linear, dbl_quadratic]
	rb_define_method(klass, "attenuation=", setAttenuation, 1);
	
	rb_define_method(klass, "power_scale=", setPowerScale, 1);
	
	rb_define_method(klass, "shadow_far_distance=", setShadowFarDistance, 1);
	rb_define_method(klass, "reset_shadow_far_distance", resetShadowFarDistance, 0);
	rb_define_method(klass, "shadow_far_distance", getShadowFarDistance, 0);
	rb_define_method(klass, "shadow_far_distance_squared", getShadowFarDistanceSquared, 0);
		rb_define_alias(klass, "shadow_far_distance_sq", "shadow_far_distance_squared");
	
	rb_define_method(klass, "shadow_near_clip_distance=", setShadowNearClipDistance, 1);
	rb_define_method(klass, "shadow_near_clip_distance", getShadowNearClipDistance, 0);
	rb_define_method(klass, "shadow_far_clip_distance=", setShadowFarClipDistance, 1);
	rb_define_method(klass, "shadow_far_clip_distance", getShadowFarClipDistance, 0);
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
	
	// if(SYM2ID(light_type)){
		
	// }
	
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

static VALUE getType(VALUE self){
	Oni_LightPtr ptr_light;
	Data_Get_Struct(self, Oni_LightPtr, ptr_light);
	
	int int_type = Oni_Light_getType(ptr_light);
	
	VALUE sym;
	if(int_type == 0){
		sym = ID2SYM(rb_intern("point"));
	}else if(int_type == 1){
		sym = ID2SYM(rb_intern("directional"));
	}else if(int_type == 2){
		sym = ID2SYM(rb_intern("spotlight"));
	}
	
	return sym;
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

static VALUE getPosition(VALUE self){
	Oni_LightPtr ptr_light;
	Data_Get_Struct(self, Oni_LightPtr, ptr_light);
	
	// Returns an array
	double dbl_position [3];
	Oni_Light_getDirection(ptr_light, dbl_position);
	
	VALUE pos = rb_ary_new3(
		3,
		
		rb_float_new(dbl_position[0]),
		rb_float_new(dbl_position[1]),
		rb_float_new(dbl_position[2])
	);
	
	return pos;
}

static VALUE setDirection(VALUE self, VALUE x, VALUE y, VALUE z){
	Oni_LightPtr ptr_light;
	Data_Get_Struct(self, Oni_LightPtr, ptr_light);
	
	double dbl_x = NUM2DBL(x);
	double dbl_y = NUM2DBL(y);
	double dbl_z = NUM2DBL(z);
	
	Oni_Light_setDirection(ptr_light, dbl_x, dbl_y, dbl_z);
	return Qnil;
}

static VALUE getDirection(VALUE self){
	Oni_LightPtr ptr_light;
	Data_Get_Struct(self, Oni_LightPtr, ptr_light);
	
	// Returns an array
	// Pointer should be provided as an argument
	double dbl_direction [3];
	Oni_Light_getDirection(ptr_light, dbl_direction);
	
	VALUE direction = rb_ary_new3(
		3,
		
		rb_float_new(dbl_direction[0]),
		rb_float_new(dbl_direction[1]),
		rb_float_new(dbl_direction[2])
	);
	
	return direction;
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

static VALUE setAttenuation(VALUE self, VALUE attenuation){
	Oni_LightPtr ptr_light;
	Data_Get_Struct(self, Oni_LightPtr, ptr_light);
	
	double dbl_range = NUM2DBL(rb_ary_entry(attenuation, 0));
	double dbl_constant = NUM2DBL(rb_ary_entry(attenuation, 1));
	double dbl_linear = NUM2DBL(rb_ary_entry(attenuation, 2));
	double dbl_quadratic = NUM2DBL(rb_ary_entry(attenuation, 3));
	
	Oni_Light_setAttenuation(ptr_light, dbl_range, dbl_constant, dbl_linear, dbl_quadratic);
	
	return Qnil;
}

static VALUE setPowerScale(VALUE self, VALUE power){
	Oni_LightPtr ptr_light;
	Data_Get_Struct(self, Oni_LightPtr, ptr_light);
	
	double dbl_power = NUM2DBL(power);
	
	Oni_Light_setPowerScale(ptr_light, dbl_power);
	
	return Qnil;
}
static VALUE setShadowFarDistance(VALUE self, VALUE distance){
	Oni_LightPtr ptr_light;
	Data_Get_Struct(self, Oni_LightPtr, ptr_light);
	
	double dbl_distance = NUM2DBL(distance);
	
	Oni_Light_setShadowFarDistance(ptr_light, dbl_distance);
	
	return Qnil;
}

static VALUE resetShadowFarDistance(VALUE self){
	Oni_LightPtr ptr_light;
	Data_Get_Struct(self, Oni_LightPtr, ptr_light);
	
	Oni_Light_resetShadowFarDistance(ptr_light);
	
	return Qnil;
}
static VALUE getShadowFarDistance(VALUE self){
	Oni_LightPtr ptr_light;
	Data_Get_Struct(self, Oni_LightPtr, ptr_light);
	
	double dbl_farDistance = Oni_Light_getShadowFarDistance(ptr_light);
	
	VALUE farDistance = rb_float_new(dbl_farDistance);
	
	return farDistance;
}
static VALUE getShadowFarDistanceSquared(VALUE self){
	Oni_LightPtr ptr_light;
	Data_Get_Struct(self, Oni_LightPtr, ptr_light);
	
	double dbl_farDistance = Oni_Light_getShadowFarDistanceSquared(ptr_light);
	
	VALUE farDistance = rb_float_new(dbl_farDistance);
	
	return farDistance;
}
static VALUE setShadowNearClipDistance(VALUE self, VALUE nearClip){
	Oni_LightPtr ptr_light;
	Data_Get_Struct(self, Oni_LightPtr, ptr_light);
	
	double dbl_nearClip = NUM2DBL(nearClip);
	
	Oni_Light_setShadowNearClipDistance(ptr_light, dbl_nearClip);
	
	return Qnil;
}
static VALUE getShadowNearClipDistance(VALUE self){
	Oni_LightPtr ptr_light;
	Data_Get_Struct(self, Oni_LightPtr, ptr_light);
	
	double dbl_nearClipDistance = Oni_Light_getShadowNearClipDistance(ptr_light);
	
	VALUE nearClipDistance = rb_float_new(dbl_nearClipDistance);
	
	return nearClipDistance;
}
static VALUE setShadowFarClipDistance(VALUE self, VALUE farClip){
	Oni_LightPtr ptr_light;
	Data_Get_Struct(self, Oni_LightPtr, ptr_light);
	
	double dbl_farClip = NUM2DBL(farClip);
	
	Oni_Light_setShadowFarClipDistance(ptr_light, dbl_farClip);
	
	return Qnil;
}
static VALUE getShadowFarClipDistance(VALUE self){
	Oni_LightPtr ptr_light;
	Data_Get_Struct(self, Oni_LightPtr, ptr_light);
	
	double dbl_shadowFarClipDistance = Oni_Light_getShadowFarClipDistance(ptr_light);
	
	VALUE shadowFarClipDistance = rb_float_new(dbl_shadowFarClipDistance);
	
	return shadowFarClipDistance;
}
