#include "OniLight.h"

namespace Oni
{
	Light::Light()
	{
		// mLight = NULL;
	}
	
	Light::~Light()
	{
		mSceneMgr->destroyLight(mLight);
	}
	
	void
	Light::initialize(Ogre::SceneManager* sceneMgr, std::string& name)
	{
		mSceneMgr = sceneMgr;
		
		mLight = sceneMgr->createLight(name);
	}

	void
	Light::update(Ogre::Real deltaTime)
	{
		
	}
}