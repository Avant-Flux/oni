#include "model.h"
#include "node_management.h"

void Init_Oni_Model(VALUE outer){
	VALUE klass = rb_define_class_under(outer, "Model", rb_cObject);
	
	rb_define_alloc_func(klass, alloc);
	rb_define_method(klass, "initialize", initialize, -1);
	rb_define_method(klass, "update", update, 1);
	
	rb_define_method(klass, "name", getName, 0);
	
	// rb_define_method(klass, "bone", getBone, 1);
	rb_define_method(klass, "attach_object_to_bone", attachObjectToBone, 2);
	rb_define_method(klass, "detach_object_from_bone", detachObjectFromBone, 1);
	rb_define_method(klass, "attached_to_bone?", isAttachedToBone, 0);
	
	rb_define_method(klass, "visible=", setVisible, 1);
	rb_define_method(klass, "visible?", getVisible, 0);
	
	rb_define_method(klass, "cast_shadows=", setCastShadows, 1);
	rb_define_method(klass, "cast_shadows?", getCastShadows, 0);
	
	rb_define_method(klass, "bb_width", getBoundingBoxWidth, 0);
	rb_define_method(klass, "bb_depth", getBoundingBoxDepth, 0);
	rb_define_method(klass, "bb_height", getBoundingBoxHeight, 0);
	
	rb_define_method(klass, "position=", setPosition, 1);
	rb_define_method(klass, "translate", translate, -1);
	
	// Note: should probably flip this to rotation_2d and rotation
	rb_define_method(klass, "reset_orientation", resetOrientation, 0);
	rb_define_method(klass, "orientation", getOrientation, -1);
	rb_define_method(klass, "orientation=", setOrientation, 1);
	
	rb_define_method(klass, "rotate_3D", rotate3D, 1);
	rb_define_method(klass, "pitch", pitch, 1);
	rb_define_method(klass, "yaw", yaw, 1);
	rb_define_method(klass, "roll", roll, 1);
	
	rb_define_method(klass, "rotation", getRotation, 0);
	rb_define_method(klass, "rotation=", setRotation, 1);
	
	rb_define_method(klass, "scale_by", scale, 3);
	rb_define_method(klass, "scale", getScale, 0);
	rb_define_method(klass, "scale=", setScale, 1);
}

static VALUE alloc(VALUE class){
	Oni_ModelPtr model = Oni_Model_new();
	VALUE data = Data_Wrap_Struct(class, NULL, Oni_Model_delete, model);
	
	return data;
}

static VALUE initialize(int argc, VALUE *argv, VALUE self){	
	// Ruby interface: Model.new(window, "name", "name.mesh")
	
	Oni_ModelPtr ptr_model;
	Data_Get_Struct(self, Oni_ModelPtr, ptr_model);
	
	
	VALUE window, name, filename, parent;
	rb_scan_args(argc, argv, "31", &window, &name, &filename, &parent);
	
	
	Ogre_WindowPtr ptr_window;
	Data_Get_Struct(window, Ogre_WindowPtr, ptr_window);
	
	char* string_name = StringValueCStr(name);
	char* string_filename = StringValueCStr(filename);
	
	Ogre_NodePtr ptr_parent;
	if(NIL_P(parent)){
		ptr_parent = NULL;
	}
	else
	{
		ptr_parent = Oni_getNodePointer(parent);
	}
	
	Oni_Model_initialize(ptr_model, ptr_window, string_name, string_filename, ptr_parent);
	
	return Qnil;
}

static VALUE update(VALUE self, VALUE dt){
	Oni_ModelPtr ptr_model;
	Data_Get_Struct(self, Oni_ModelPtr, ptr_model);
	
	double double_dt = NUM2DBL(dt);
	
	Oni_Model_update(ptr_model, double_dt);
	
	return Qnil;
}

static VALUE getName(VALUE self){
	Oni_ModelPtr ptr_model;
	Data_Get_Struct(self, Oni_ModelPtr, ptr_model);
	
	const char* string_name = Oni_Model_getName(ptr_model);
	VALUE name = rb_str_new2(string_name);
	
	return name;
}


// static VALUE getBone(VALUE self, VALUE name){
// 	Oni_ModelPtr ptr_model;
// 	Data_Get_Struct(self, Oni_ModelPtr, ptr_model);
	
	
	
// 	return 
// }

static VALUE attachObjectToBone(VALUE self, VALUE name, VALUE obj){
	Oni_ModelPtr ptr_model;
	Data_Get_Struct(self, Oni_ModelPtr, ptr_model);
	
	Oni_ModelPtr ptr_otherModel;
	Data_Get_Struct(obj, Oni_ModelPtr, ptr_otherModel);
	
	char* string_name = StringValueCStr(name);
	Oni_Model_attachObjectToBone(ptr_model, string_name, ptr_otherModel);
	
	return Qnil;
}

static VALUE detachObjectFromBone(VALUE self, VALUE obj){
	Oni_ModelPtr ptr_model;
	Data_Get_Struct(self, Oni_ModelPtr, ptr_model);
	
	Oni_ModelPtr ptr_otherModel;
	Data_Get_Struct(obj, Oni_ModelPtr, ptr_otherModel);
	
	Oni_Model_detachObjectFromBone(ptr_model, ptr_otherModel);
	
	return Qnil;
}

static VALUE isAttachedToBone(VALUE self){
	Oni_ModelPtr ptr_model;
	Data_Get_Struct(self, Oni_ModelPtr, ptr_model);
	
	if(Oni_Model_isAttachedToBone(ptr_model))
	{
		return Qtrue;
	}
	else
	{
		return Qfalse;
	}
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

static VALUE getCastShadows(VALUE self){
	Oni_ModelPtr ptr_model;
	Data_Get_Struct(self, Oni_ModelPtr, ptr_model);
	
	if(Oni_Model_getCastShadows(ptr_model))
	{
		return Qtrue;
	}
	else
	{
		return Qfalse;
	}
}

static VALUE setCastShadows(VALUE self, VALUE enabled){
	Oni_ModelPtr ptr_model;
	Data_Get_Struct(self, Oni_ModelPtr, ptr_model);
	
	Oni_Model_setCastShadows(ptr_model, RTEST(enabled));
	
	return Qnil;
}

static VALUE getBoundingBoxWidth(VALUE self){
	Oni_ModelPtr ptr_model;
	Data_Get_Struct(self, Oni_ModelPtr, ptr_model);
	
	return rb_float_new(Oni_Model_getBoundingBoxWidth(ptr_model));
}

static VALUE getBoundingBoxDepth(VALUE self){
	Oni_ModelPtr ptr_model;
	Data_Get_Struct(self, Oni_ModelPtr, ptr_model);
	
	return rb_float_new(Oni_Model_getBoundingBoxDepth(ptr_model));
}

static VALUE getBoundingBoxHeight(VALUE self){
	Oni_ModelPtr ptr_model;
	Data_Get_Struct(self, Oni_ModelPtr, ptr_model);
	
	return rb_float_new(Oni_Model_getBoundingBoxHeight(ptr_model));
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

static VALUE translate(int argc, VALUE *argv, VALUE self){
	// VALUE self, VALUE x, VALUE y, VALUE z, VALUE transform_space
	Oni_ModelPtr ptr_model;
	Data_Get_Struct(self, Oni_ModelPtr, ptr_model);
	
	double dbl_x = NUM2DBL(argv[0]);
	double dbl_y = NUM2DBL(argv[1]);
	double dbl_z = NUM2DBL(argv[2]);
	
	// transform space should be a symbol, either :local, :parent, or :world
	ID local = rb_intern("local");
	ID parent = rb_intern("parent");
	ID world = rb_intern("world");
	
	ID ts;
	if(argc == 4){
		ts = SYM2ID(argv[3]);
	}
	else{
		ts = rb_intern("parent");
	}
	
	
	if(ts == local){
		Oni_Model_translate(ptr_model, dbl_x, dbl_y, dbl_z, LOCAL);
	}
	else if(ts == parent){
		Oni_Model_translate(ptr_model, dbl_x, dbl_y, dbl_z, PARENT);
	}
	else if(ts == world){
		Oni_Model_translate(ptr_model, dbl_x, dbl_y, dbl_z, WORLD);
	}
	
	return Qnil;
}

static VALUE resetOrientation(VALUE self){
	Oni_ModelPtr ptr_model;
	Data_Get_Struct(self, Oni_ModelPtr, ptr_model);
	
	Oni_Model_resetOrientation(ptr_model);
	
	return Qnil;
}

static VALUE getOrientation(int argc, VALUE *argv, VALUE self){
	// takes one optional parameter, which determines what type to return
	// Returns orientation in one of two formats:
		// Euler rotations
		// Quaternion
	
	return Qnil;
}

static VALUE setOrientation(VALUE self, VALUE quat){
	// There's probably a faster way to do this at the C++ level
	resetOrientation(self);
	rotate3D(self, quat);
	
	return Qnil;
}

static VALUE rotate3D(VALUE self, VALUE quat){
	// Convenience method
	// Only for snapping to a given orientation
	// Do not attempt to use with any sort of interpolation
	
	Oni_ModelPtr ptr_model;
	Data_Get_Struct(self, Oni_ModelPtr, ptr_model);
	
	// TODO: Take single argument of one array - interpreted as a vector
	// RARRAY(quat)->ptr[0];
	VALUE w = rb_ary_entry(quat, 0);
	VALUE x = rb_ary_entry(quat, 1);
	VALUE y = rb_ary_entry(quat, 2);
	VALUE z = rb_ary_entry(quat, 3);
	
	double dbl_w = NUM2DBL(w);
	double dbl_x = NUM2DBL(x);
	double dbl_y = NUM2DBL(y);
	double dbl_z = NUM2DBL(z);
	
	Oni_Model_rotate(ptr_model, dbl_w, dbl_x, dbl_y, dbl_z);
	
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

// DEPRECIATED
// static VALUE rotateTo(VALUE self, VALUE x, VALUE y, VALUE z){
// 	Oni_ModelPtr ptr_model;
// 	Data_Get_Struct(self, Oni_ModelPtr, ptr_model);
	
// 	double dbl_x = NUM2DBL(x);
// 	double dbl_y = NUM2DBL(y);
// 	double dbl_z = NUM2DBL(z);
	
// 	Oni_Model_rotateTo(ptr_model, dbl_x,dbl_y,dbl_z);
	
// 	return Qnil;
// }

static VALUE getRotation(VALUE self){
	Oni_ModelPtr ptr_model;
	Data_Get_Struct(self, Oni_ModelPtr, ptr_model);
		
	double dbl_rotation = Oni_Model_getRotation(ptr_model);
	
	VALUE rotation = rb_float_new(dbl_rotation);
	
	return rotation;
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

static VALUE getScale(VALUE self){
	Oni_ModelPtr ptr_model;
	Data_Get_Struct(self, Oni_ModelPtr, ptr_model);
	
	double scale[3];
	Oni_Model_getScale(ptr_model, scale);
	
	
	VALUE array = rb_ary_new2(3);
	int i;
	for(i = 0; i < 3; i++){
		rb_ary_store(array, i, rb_float_new(scale[i]));
	}
	
	return array;
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