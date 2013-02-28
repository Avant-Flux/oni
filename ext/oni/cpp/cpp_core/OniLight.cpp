#include "OniLight.h"

namespace Oni
{
	Light::Light()
	{
		// mLight = NULL;
	}
	
	Light::~Light()
	{
		
	}
	
	void
	Light::initialize(Ogre::SceneManager* sceneMgr)
	{
		// add a bright light above the scene
		mLight = sceneMgr->createLight();
		
		mLight->setType(Ogre::Light::LT_POINT);
		mLight->setPosition(-10, 40, 20);
		mLight->setSpecularColour(Ogre::ColourValue::White);
	}

	void
	Light::update(Ogre::Real deltaTime)
	{
		
	}
}