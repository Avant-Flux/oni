#include "Camera.h"

extern "C" {
	Ogre_CameraPtr Ogre_Camera_new(Ogre_WindowPtr window, char* name){
		BaseApplication* game = (BaseApplication*)window; //TODO: Use proper C++ static cast
		
		std::string cpp_name(name);
		
		Ogre::Camera* camera = game->getSceneMgr()->createCamera(cpp_name);

		camera->setPosition(Ogre::Vector3(0,20,50));
		// Look back along -Z
		camera->lookAt(Ogre::Vector3(0,0,0));
		camera->setNearClipDistance(5);
		
		return (Ogre_CameraPtr)camera;
	}
	
	void Ogre_Camera_delete(Ogre_CameraPtr obj){
		Ogre::Camera* camera = (Ogre::Camera*)obj;
		
		delete camera;
	}
	
	void Ogre_Camera_initialize(Ogre_CameraPtr obj, Ogre_WindowPtr obj2){
		Ogre::Camera* camera = (Ogre::Camera*)obj;
		BaseApplication* game = (BaseApplication*)obj2;
		
		// ===== Create viewport
		// Create one viewport, entire window
	    Ogre::Viewport* vp = game->getWindow()->addViewport(camera);
	    vp->setBackgroundColour(Ogre::ColourValue(0,0,0));

	    // Alter the camera aspect ratio to match the viewport
	    camera->setAspectRatio(
	        Ogre::Real(vp->getActualWidth()) / Ogre::Real(vp->getActualHeight()));
	}
}