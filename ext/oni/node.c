#include "node.h"
#include "node_management.h"

void Init_Oni_Node(VALUE outer){
	VALUE klass = rb_define_class_under(outer, "Node", rb_cObject);
	
	rb_define_alloc_func(klass, alloc);
	rb_define_method(klass, "initialize", initialize, -1);
	rb_define_method(klass, "update", update, 1);
	
	rb_define_method(klass, "name", getName, 0);
	
	rb_define_method(klass, "visible=", setVisible, 1); // Manages visibility of all children
	rb_define_method(klass, "visible?", getVisible, 0); // true if at least one child visible
	
	rb_define_method(klass, "cast_shadows=", setCastShadows, 1); // all children
	rb_define_method(klass, "cast_shadows?", getCastShadows, 0); // true if at least one child
	
	// Ogre::Nodes does not implement these
	// would be good to get bounding box based on all underlying elements though
	rb_define_method(klass, "bb_width", getBoundingBoxWidth, 0);
	rb_define_method(klass, "bb_depth", getBoundingBoxDepth, 0);
	rb_define_method(klass, "bb_height", getBoundingBoxHeight, 0);
	
	
	
	rb_define_method(klass, "position", getPosition, 0);
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
	rb_define_method(klass, "scale=", setScale, 1);
	
	// TODO: Maybe allow getting children?
	// would allow ability to walk the hierarchy in code
	// would create extra references to things though, which would complicate GC
}

static VALUE alloc(VALUE class){
	Oni_NodePtr node = Oni_Node_new();
	VALUE data = Data_Wrap_Struct(class, NULL, Oni_Node_delete, node);
	
	return data;
}

static VALUE initialize(int argc, VALUE *argv, VALUE self){	
	// Ruby interface: Model.new(window, "name", "name.mesh")
	
	Oni_NodePtr ptr_node;
	Data_Get_Struct(self, Oni_NodePtr, ptr_node);
	
	
	VALUE window, name, parent;
	rb_scan_args(argc, argv, "21", &window, &name, &parent);
	
	
	Ogre_WindowPtr ptr_window;
	Data_Get_Struct(window, Ogre_WindowPtr, ptr_window);
	
	char* string_name = StringValueCStr(name);
		
	Ogre_NodePtr ptr_parent;
	if(NIL_P(parent)){
		ptr_parent = NULL;
	}
	else
	{
		ptr_parent = Oni_getNodePointer(parent);
	}
	
	Oni_Node_initialize(ptr_node, ptr_window, string_name, ptr_parent);
	
	return Qnil;
}

static VALUE update(VALUE self, VALUE dt){
	Oni_NodePtr ptr_node;
	Data_Get_Struct(self, Oni_NodePtr, ptr_node);
	
	double double_dt = NUM2DBL(dt);
	
	Oni_Node_update(ptr_node, double_dt);
	
	return Qnil;
}

static VALUE getName(VALUE self){
	Oni_NodePtr ptr_node;
	Data_Get_Struct(self, Oni_NodePtr, ptr_node);
	
	const char* string_name = Oni_Node_getName(ptr_node);
	VALUE name = rb_str_new2(string_name);
	
	return name;
}

static VALUE getVisible(VALUE self)
{
	Oni_NodePtr ptr_node;
	Data_Get_Struct(self, Oni_NodePtr, ptr_node);
	
	// if(Oni_Node_getVisible(ptr_node))
	// {
	// 	return Qtrue;
	// }
	// else
	// {
	// 	return Qfalse;
	// }
	
	return Qnil;
}

static VALUE setVisible(VALUE self, VALUE visible)
{
	Oni_NodePtr ptr_node;
	Data_Get_Struct(self, Oni_NodePtr, ptr_node);
	
	// Oni_Node_setVisible(ptr_node, RTEST(visible));
	
	return Qnil;
}

static VALUE getCastShadows(VALUE self){
	Oni_NodePtr ptr_node;
	Data_Get_Struct(self, Oni_NodePtr, ptr_node);
	
	// if(Oni_Node_getCastShadows(ptr_node))
	// {
	// 	return Qtrue;
	// }
	// else
	// {
	// 	return Qfalse;
	// }
	
	return Qnil;
}

static VALUE setCastShadows(VALUE self, VALUE enabled){
	Oni_NodePtr ptr_node;
	Data_Get_Struct(self, Oni_NodePtr, ptr_node);
	
	// Oni_Node_setCastShadows(ptr_node, RTEST(enabled));
	
	return Qnil;
}

static VALUE getBoundingBoxWidth(VALUE self){
	Oni_NodePtr ptr_node;
	Data_Get_Struct(self, Oni_NodePtr, ptr_node);
	
	// return rb_float_new(Oni_Node_getBoundingBoxWidth(ptr_node));
	return Qnil;
}

static VALUE getBoundingBoxDepth(VALUE self){
	Oni_NodePtr ptr_node;
	Data_Get_Struct(self, Oni_NodePtr, ptr_node);
	
	// return rb_float_new(Oni_Node_getBoundingBoxDepth(ptr_node));
	return Qnil;
}

static VALUE getBoundingBoxHeight(VALUE self){
	Oni_NodePtr ptr_node;
	Data_Get_Struct(self, Oni_NodePtr, ptr_node);
	
	// return rb_float_new(Oni_Node_getBoundingBoxHeight(ptr_node));
	return Qnil;
}

static VALUE getPosition(VALUE self){
	Oni_NodePtr ptr_node;
	Data_Get_Struct(self, Oni_NodePtr, ptr_node);
	
	double position[3];
	Oni_Node_getPosition(ptr_node, position);
	
	
	VALUE array = rb_ary_new2(3);
	int i;
	for(i = 0; i < 3; i++){
		rb_ary_store(array, i, rb_float_new(position[i]));
	}
	
	return array;
}

static VALUE setPosition(VALUE self, VALUE pos)
{
	Oni_NodePtr ptr_node;
	Data_Get_Struct(self, Oni_NodePtr, ptr_node);
	
	
	// TODO: Take single argument of one array - interpreted as a vector
	// RARRAY(pos)->ptr[0];
	VALUE x = rb_ary_entry(pos, 0);
	VALUE y = rb_ary_entry(pos, 1);
	VALUE z = rb_ary_entry(pos, 2);
	
	double dbl_x = NUM2DBL(x);
	double dbl_y = NUM2DBL(y);
	double dbl_z = NUM2DBL(z);
	
	Oni_Node_setPosition(ptr_node, dbl_x, dbl_y, dbl_z);
	
	return Qnil;
}

static VALUE translate(int argc, VALUE *argv, VALUE self){
	// VALUE self, VALUE x, VALUE y, VALUE z, VALUE transform_space
	Oni_NodePtr ptr_node;
	Data_Get_Struct(self, Oni_NodePtr, ptr_node);
	
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
		Oni_Node_translate(ptr_node, dbl_x, dbl_y, dbl_z, LOCAL);
	}
	else if(ts == parent){
		Oni_Node_translate(ptr_node, dbl_x, dbl_y, dbl_z, PARENT);
	}
	else if(ts == world){
		Oni_Node_translate(ptr_node, dbl_x, dbl_y, dbl_z, WORLD);
	}
	
	return Qnil;
}

static VALUE resetOrientation(VALUE self){
	Oni_NodePtr ptr_node;
	Data_Get_Struct(self, Oni_NodePtr, ptr_node);
	
	Oni_Node_resetOrientation(ptr_node);
	
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
	
	Oni_NodePtr ptr_node;
	Data_Get_Struct(self, Oni_NodePtr, ptr_node);
	
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
	
	Oni_Node_rotate(ptr_node, dbl_w, dbl_x, dbl_y, dbl_z);
	
	return Qnil;
}

static VALUE pitch(VALUE self, VALUE radians){
	Oni_NodePtr ptr_node;
	Data_Get_Struct(self, Oni_NodePtr, ptr_node);
	
	double dbl_radians = NUM2DBL(radians);
	Oni_Node_pitch(ptr_node, dbl_radians);
	
	return Qnil;
}

static VALUE yaw(VALUE self, VALUE radians){
	Oni_NodePtr ptr_node;
	Data_Get_Struct(self, Oni_NodePtr, ptr_node);
	
	double dbl_radians = NUM2DBL(radians);
	Oni_Node_yaw(ptr_node, dbl_radians);
	
	return Qnil;
}

static VALUE roll(VALUE self, VALUE radians){
	Oni_NodePtr ptr_node;
	Data_Get_Struct(self, Oni_NodePtr, ptr_node);
	
	double dbl_radians = NUM2DBL(radians);
	Oni_Node_roll(ptr_node, dbl_radians);
	
	return Qnil;
}

// DEPRECIATED
// static VALUE rotateTo(VALUE self, VALUE x, VALUE y, VALUE z){
// 	Oni_NodePtr ptr_node;
// 	Data_Get_Struct(self, Oni_NodePtr, ptr_node);
	
// 	double dbl_x = NUM2DBL(x);
// 	double dbl_y = NUM2DBL(y);
// 	double dbl_z = NUM2DBL(z);
	
// 	Oni_Node_rotateTo(ptr_node, dbl_x,dbl_y,dbl_z);
	
// 	return Qnil;
// }

static VALUE getRotation(VALUE self){
	Oni_NodePtr ptr_node;
	Data_Get_Struct(self, Oni_NodePtr, ptr_node);
		
	double dbl_rotation = Oni_Node_getRotation(ptr_node);
	
	VALUE rotation = rb_float_new(dbl_rotation);
	
	return rotation;
}

static VALUE setRotation(VALUE self, VALUE radians){
	Oni_NodePtr ptr_node;
	Data_Get_Struct(self, Oni_NodePtr, ptr_node);
	
	double dbl_radians = NUM2DBL(radians);
	
	Oni_Node_setRotation(ptr_node, dbl_radians);
	
	return Qnil;
}

static VALUE scale(VALUE self, VALUE x, VALUE y, VALUE z){
	Oni_NodePtr ptr_node;
	Data_Get_Struct(self, Oni_NodePtr, ptr_node);
	
	double dbl_x = NUM2DBL(x);
	double dbl_y = NUM2DBL(y);
	double dbl_z = NUM2DBL(z);
	
	Oni_Node_scale(ptr_node, dbl_x, dbl_y, dbl_z);
	
	return Qnil;
}

static VALUE setScale(VALUE self, VALUE scale){
	Oni_NodePtr ptr_node;
	Data_Get_Struct(self, Oni_NodePtr, ptr_node);
	
	// TODO: Take single argument of one array - interpreted as a vector
	// RARRAY(scale)->ptr[0];
	VALUE x = rb_ary_entry(scale, 0);
	VALUE y = rb_ary_entry(scale, 1);
	VALUE z = rb_ary_entry(scale, 2);
	
	double dbl_x = NUM2DBL(x);
	double dbl_y = NUM2DBL(y);
	double dbl_z = NUM2DBL(z);
	
	Oni_Node_setScale(ptr_node, dbl_x, dbl_y, dbl_z);
	
	return Qnil;
}