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
	Light::initialize(Ogre::SceneManager* sceneMgr, std::string& name)
	{
		// add a bright light above the scene
		mLight = sceneMgr->createLight(); // Note: Can specify a name for the light
		
		mLight->setType(Ogre::Light::LT_POINT);
		mLight->setPosition(-10, 40, 20);
		mLight->setSpecularColour(Ogre::ColourValue::White);
	}

	void
	Light::update(Ogre::Real deltaTime)
	{
		
	}
}