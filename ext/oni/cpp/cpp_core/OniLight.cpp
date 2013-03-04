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
		mLight = sceneMgr->createLight(name);
	}

	void
	Light::update(Ogre::Real deltaTime)
	{
		
	}
}