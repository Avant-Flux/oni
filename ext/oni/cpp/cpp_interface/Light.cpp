#include "Light.h"


extern "C" {
	Oni_LightPtr Oni_Light_new(){
		Oni::Light* light = new Oni::Light();
		
		return (Oni_LightPtr)light;
	}

	void Oni_Light_delete(Oni_LightPtr obj){
		printf("======DELETING Light\n");
		Oni::Light* light = (Oni::Light*)(obj);
		
		delete light;
	}

	void Oni_Light_markgc(Oni_LightPtr obj){
		printf("======MARK FOR COLLECTION\n");
		Oni::Light* light = (Oni::Light*)(obj);
		
		// light->setVisible(false);
	}

	void Oni_Light_initialize(Oni_LightPtr obj, Ogre_WindowPtr obj2, char* name){
		Oni::Light* light = (Oni::Light*)(obj);
		GameApplication* game = (GameApplication*)obj2;
		
		std::string cpp_name(name);
		
		light->initialize(game->getSceneMgr(), cpp_name);
	}

	void Oni_Light_update(Oni_LightPtr obj, double dt){
		Oni::Light* light = (Oni::Light*)(obj);
		
		light->update(dt);
	}
	
	int Oni_Light_getVisible(Oni_LightPtr obj){
		Oni::Light* light = (Oni::Light*)(obj);
		
		if(light->getVisible())
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	
	void Oni_Light_setVisible(Oni_LightPtr obj, int visible){
		Oni::Light* light = (Oni::Light*)(obj);
		
		if(visible){
			light->setVisible(true);
		}
		else{
			light->setVisible(false);
		}
	}
	
	void Oni_Light_setType(Oni_LightPtr obj, int light_type){
		Oni::Light* light = (Oni::Light*)(obj);
		
		Ogre::Light::LightTypes type;
		if(light_type == 0){
			type = Ogre::Light::LT_POINT;
		}else if(light_type == 1){
			type = Ogre::Light::LT_DIRECTIONAL;
		}else if(light_type == 2){
			type = Ogre::Light::LT_SPOTLIGHT;
		}
		light->setType(type);
	}
	
	int Oni_Light_getType(Oni_LightPtr obj){
		Oni::Light* light = (Oni::Light*)(obj);
		
		Ogre::Light::LightTypes type = light->getType();
		
		int light_type;
		if(type == Ogre::Light::LT_POINT){
			light_type = 0;
		}else if(type == Ogre::Light::LT_DIRECTIONAL){
			light_type = 1;
		}else if(type == Ogre::Light::LT_SPOTLIGHT){
			light_type = 2;
		}
		
		return light_type;
	}
	
	void Oni_Light_setPosition(Oni_LightPtr obj, double x, double y, double z){
		Oni::Light* light = (Oni::Light*)(obj);
		
		light->setPosition(x,y,z);
	}
	
	void Oni_Light_getPosition(Oni_LightPtr obj, double* position){
		Oni::Light* light = (Oni::Light*)(obj);
		
		Ogre::Vector3 vec_position = light->getPosition();
		
		// Assume array is already allocated
		position[0] = vec_position.x;
		position[1] = vec_position.y;
		position[2] = vec_position.z;
	}
	
	void Oni_Light_setDirection(Oni_LightPtr obj, double x, double y, double z){
		Oni::Light* light = (Oni::Light*)(obj);
		
		light->setDirection(x,y,z);
	}
	
	void Oni_Light_getDirection(Oni_LightPtr obj, double* direction){
		Oni::Light* light = (Oni::Light*)(obj);
		
		Ogre::Vector3 vec_direction = light->getDirection();
		
		// Assume array is already allocated
		direction[0] = vec_direction.x;
		direction[1] = vec_direction.y;
		direction[2] = vec_direction.z;
	}
	
	void Oni_Light_setDiffuseColor(Oni_LightPtr obj, double r, double g, double b){
		Oni::Light* light = (Oni::Light*)(obj);
		
		light->setDiffuseColour(r,g,b);
	}
	
	void Oni_Light_setSpecularColor(Oni_LightPtr obj, double r, double g, double b){
		Oni::Light* light = (Oni::Light*)(obj);
		
		light->setSpecularColour(r,g,b);
	}
	
	void Oni_Light_setAttenuation(Oni_LightPtr obj, double range, double constant, double linear, double quadratic){
		
	}
	
	void Oni_Light_setPowerScale(Oni_LightPtr obj, double power){
		Oni::Light* light = (Oni::Light*)(obj);
		
		light->setPowerScale(power);
	}
	
	void Oni_Light_setShadowFarDistance(Oni_LightPtr obj, double distance){
		Oni::Light* light = (Oni::Light*)(obj);
		
		light->setShadowFarDistance(distance);
	}
	
	void Oni_Light_resetShadowFarDistance(Oni_LightPtr obj){
		Oni::Light* light = (Oni::Light*)(obj);
		
		light->resetShadowFarDistance();
	}
	
	double Oni_Light_getShadowFarDistance(Oni_LightPtr obj){
		Oni::Light* light = (Oni::Light*)(obj);
		
		return light->getShadowFarDistance();
	}
	
	double Oni_Light_getShadowFarDistanceSquared(Oni_LightPtr obj){
		Oni::Light* light = (Oni::Light*)(obj);
		
		return light->getShadowFarDistanceSquared();
	}
	
	void Oni_Light_setShadowNearClipDistance(Oni_LightPtr obj, double nearClip){
		Oni::Light* light = (Oni::Light*)(obj);
		
		light->setShadowNearClipDistance(nearClip);
	}
	
	double Oni_Light_getShadowNearClipDistance(Oni_LightPtr obj){
		Oni::Light* light = (Oni::Light*)(obj);
		
		return light->getShadowNearClipDistance();
	}
	
	void Oni_Light_setShadowFarClipDistance(Oni_LightPtr obj, double farClip){
		Oni::Light* light = (Oni::Light*)(obj);
		
		light->setShadowFarClipDistance(farClip);
	}
	
	double Oni_Light_getShadowFarClipDistance(Oni_LightPtr obj){
		Oni::Light* light = (Oni::Light*)(obj);
		
		return light->getShadowFarClipDistance();
	}
}