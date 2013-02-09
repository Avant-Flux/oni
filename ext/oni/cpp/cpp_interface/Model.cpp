#include "Model.h"


extern "C" {
	Oni_ModelPtr Oni_Model_new(Oni_ModelPtr model){
		Agent* agent = new Agent();
		
		return (Ogre_AgentPtr)agent;
	}

	void Oni_Model_delete(Oni_ModelPtr agent){
		printf("======DELETING AGENT\n");
		Agent* agent = (Agent*)(obj);
		
		delete agent;
	}

	void Oni_Model_markgc(Oni_ModelPtr obj){
		printf("======MARK FOR COLLECTION\n");
		Agent* agent = (Agent*)(obj);
		
		agent->setVisible(false);
	}

	void Oni_Model_initialize(Oni_ModelPtr obj, Ogre_WindowPtr obj2, char* name, char* filename);{
		Agent* agent = (Agent*)(obj);
		GameApplication* game = (GameApplication*)obj2;
		
		std::string cpp_name(name);
		std::string cpp_filename(filename);
		
		agent->initialize(game->getSceneMgr(), cpp_name, cpp_filename);
	}

	void Oni_Model_update(Oni_ModelPtr obj, double dt){
		Agent* agent = (Agent*)(obj);
		
		agent->update(dt);
	}

	int Oni_Model_getVisible(Oni_ModelPtr obj){
		Agent* agent = (Agent*)(obj);
		
		if(agent->getVisible())
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	
	void Oni_Model_setVisible(Oni_ModelPtr obj, int visible){
		Agent* agent = (Agent*)(obj);
		
		if(visible)
		{
			agent->setVisible(true);
		}
		else
		{
			agent->setVisible(false);
		}
	}
	
	
	void Oni_Model_setPosition(Oni_ModelPtr obj, double x, double y, double z){
		Agent* agent = (Agent*)(obj);
		
		agent->setPosition(x,y,z);
	}
	
	void Oni_Model_translate(Oni_ModelPtr obj, double x, double y, double z){
		// void translate(Ogre::Real x, Ogre::Real y, Ogre::Real z, Ogre::Node::TransformSpace relativeTo=Ogre::Node::TS_PARENT);
		Agent* agent = (Agent*)(obj);
		
		agent->translate(x,y,z);
	}
	
	
	void Oni_Model_pitch(Oni_ModelPtr obj, double radians){
		Agent* agent = (Agent*)(obj);
		
		agent->pitch(Ogre::Radian(radians));
	}
	
	void Oni_Model_yaw(Oni_ModelPtr obj, double radians){
		Agent* agent = (Agent*)(obj);
		
		agent->yaw(Ogre::Radian(radians));
	}
	
	void Oni_Model_roll(Oni_ModelPtr obj, double radians){
		Agent* agent = (Agent*)(obj);
		
		agent->roll(Ogre::Radian(radians));
	}
	
	
	// Rotate to face the given vector - DEPRECIATED
	void Oni_Model_rotateTo(Oni_ModelPtr obj, double x, double y, double z){
		Agent* agent = (Agent*)(obj);
		
		agent->rotateTo(x,y,z);
	}
	
	
	// Set rotation in horizontal plane
	void Oni_Model_setRotation(Oni_ModelPtr obj, double radians){
		Agent* agent = (Agent*)(obj);
		
		agent->setHorizontalPlaneRotation(Ogre::Radian(radians));
	}
	
}