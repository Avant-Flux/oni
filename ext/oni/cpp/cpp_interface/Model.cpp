#include "Model.h"


extern "C" {
	Oni_ModelPtr Oni_Model_new(){
		Oni::Model* model = new Oni::Model();
		
		return (Oni_ModelPtr)model;
	}

	void Oni_Model_delete(Oni_ModelPtr obj){
		printf("======DELETING AGENT\n");
		Oni::Model* model = (Oni::Model*)(obj);
		
		delete model;
	}

	void Oni_Model_markgc(Oni_ModelPtr obj){
		printf("======MARK FOR COLLECTION\n");
		Oni::Model* model = (Oni::Model*)(obj);
		
		model->setVisible(false);
	}

	void Oni_Model_initialize(Oni_ModelPtr obj, Ogre_WindowPtr obj2, char* name, char* filename){
		Oni::Model* model = (Oni::Model*)(obj);
		GameApplication* game = (GameApplication*)obj2;
		
		std::string cpp_name(name);
		std::string cpp_filename(filename);
		
		model->initialize(game->getSceneMgr(), cpp_name, cpp_filename);
	}

	void Oni_Model_update(Oni_ModelPtr obj, double dt){
		Oni::Model* model = (Oni::Model*)(obj);
		
		model->update(dt);
	}

	int Oni_Model_getVisible(Oni_ModelPtr obj){
		Oni::Model* model = (Oni::Model*)(obj);
		
		if(model->getVisible())
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	
	void Oni_Model_setVisible(Oni_ModelPtr obj, int visible){
		Oni::Model* model = (Oni::Model*)(obj);
		
		if(visible)
		{
			model->setVisible(true);
		}
		else
		{
			model->setVisible(false);
		}
	}
	
	
	void Oni_Model_setPosition(Oni_ModelPtr obj, double x, double y, double z){
		Oni::Model* model = (Oni::Model*)(obj);
		
		model->setPosition(x,y,z);
	}
	
	void Oni_Model_translate(Oni_ModelPtr obj, double x, double y, double z){
		// void translate(Ogre::Real x, Ogre::Real y, Ogre::Real z, Ogre::Node::TransformSpace relativeTo=Ogre::Node::TS_PARENT);
		Oni::Model* model = (Oni::Model*)(obj);
		
		model->translate(x,y,z);
	}
	
	void Oni_Model_scale(Oni_ModelPtr obj, double x, double y, double z){
		Oni::Model* model = (Oni::Model*)(obj);
		
		model->scale(x,y,z);
	}
	
	void Oni_Model_setScale(Oni_ModelPtr obj, double x, double y, double z){
		Oni::Model* model = (Oni::Model*)(obj);
		
		model->setScale(x,y,z);
	}
	
	void Oni_Model_resetOrientation(Oni_ModelPtr obj)
	{
		Oni::Model* model = (Oni::Model*)(obj);
		
		model->resetOrientation();
	}
	
	void Oni_Model_rotate(Oni_ModelPtr obj, double w, double x, double y, double z)
	{
		Oni::Model* model = (Oni::Model*)(obj);
		
		Ogre::Quaternion quat = Ogre::Quaternion(w,x,y,z);
		model->rotate(quat);
	}
	
	void Oni_Model_pitch(Oni_ModelPtr obj, double radians){
		Oni::Model* model = (Oni::Model*)(obj);
		
		model->pitch(Ogre::Radian(radians));
	}
	
	void Oni_Model_yaw(Oni_ModelPtr obj, double radians){
		Oni::Model* model = (Oni::Model*)(obj);
		
		model->yaw(Ogre::Radian(radians));
	}
	
	void Oni_Model_roll(Oni_ModelPtr obj, double radians){
		Oni::Model* model = (Oni::Model*)(obj);
		
		model->roll(Ogre::Radian(radians));
	}
	
	
	// Rotate to face the given vector - DEPRECIATED
	void Oni_Model_rotateTo(Oni_ModelPtr obj, double x, double y, double z){
		Oni::Model* model = (Oni::Model*)(obj);
		
		model->rotateTo(x,y,z);
	}
	
	
	// Set rotation in horizontal plane
	void Oni_Model_setRotation(Oni_ModelPtr obj, double radians){
		Oni::Model* model = (Oni::Model*)(obj);
		
		model->setHorizontalPlaneRotation(Ogre::Radian(radians));
	}
	
}