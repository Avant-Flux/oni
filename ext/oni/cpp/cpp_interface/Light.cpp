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
}