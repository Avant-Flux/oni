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
	}

	void
	Light::update(Ogre::Real deltaTime)
	{
		
	}
}