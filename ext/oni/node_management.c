#include "node_management.h"

Ogre_NodePtr Oni_getNodePointer(VALUE parent){
	VALUE module_oni = rb_const_get(rb_cObject, rb_intern("Oni"));
	VALUE class_light = rb_const_get(module_oni, rb_intern("Light"));
	VALUE class_model = rb_const_get(module_oni, rb_intern("Model"));
	
	if(rb_obj_is_kind_of(parent, class_light)){
		// Light
		Oni_LightPtr ptr_light;
		Data_Get_Struct(parent, Oni_LightPtr, ptr_light);
		
		return Oni_Light_getParentNode(ptr_light);
	}
	else if(rb_obj_is_kind_of(parent, class_model)){
		// Model
		Oni_ModelPtr ptr_model;
		Data_Get_Struct(parent, Oni_ModelPtr, ptr_model);
		
		return Oni_Model_getParentNode(ptr_model);
	}
}
