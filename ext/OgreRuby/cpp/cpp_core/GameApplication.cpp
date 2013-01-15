#include "GameApplication.h"

#include <cmath>

//-------------------------------------------------------------------------------------
GameApplication::GameApplication(updateCallback update_callback,
								keyDownCallback down_callback, keyUpCallback up_callback)
{
	mUpdateCallback = update_callback;
	mKeyDownCallback = down_callback;
	mKeyUpCallback = up_callback;
	
	agent = NULL;
}
//-------------------------------------------------------------------------------------
GameApplication::~GameApplication(void)
{
	delete agent;
}

bool
GameApplication::setup()
{
	if(!BaseApplication::setup())
	{
		return false;
	}
	
	setFOV(110);
	
	return true;
}

//-------------------------------------------------------------------------------------
void
GameApplication::createScene(void)
{
    loadEnv();
	setupEnv();
	loadObjects();
	loadCharacters();
}

void // Load the buildings or ground plane, etc
GameApplication::loadEnv()
{
	using namespace Ogre;

	//create a floor mesh resource
	MeshManager::getSingleton().createPlane("floor", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, 
		Plane(Vector3::UNIT_Y, 0), 100, 100, 10, 10, true, 1, 10, 10, Vector3::UNIT_Z);

	//create a floor entity, give it material, and place it at the origin
	Entity* floor = mSceneMgr->createEntity("Floor", "floor");
	floor->setMaterialName("Examples/Rockwall");
	floor->setCastShadows(false);
	mSceneMgr->getRootSceneNode()->attachObject(floor);
}

void // Set up lights, shadows, etc
GameApplication::setupEnv()
{
	using namespace Ogre;

	// set shadow properties
	mSceneMgr->setShadowTechnique(SHADOWTYPE_TEXTURE_MODULATIVE);
	mSceneMgr->setShadowColour(ColourValue(0.5, 0.5, 0.5));
	mSceneMgr->setShadowTextureSize(1024);
	mSceneMgr->setShadowTextureCount(1);

	// use small amount of ambient lighting
	mSceneMgr->setAmbientLight(ColourValue(0.3f, 0.3f, 0.3f));

	// add a bright light above the scene
	Light* light = mSceneMgr->createLight();
	light->setType(Light::LT_POINT);
	light->setPosition(-10, 40, 20);
	light->setSpecularColour(ColourValue::White);
}

void // Load other props or objects
GameApplication::loadObjects()
{
	
}

void // Load actors, agents, characters
GameApplication::loadCharacters()
{
	
}

void
GameApplication::addTime(Ogre::Real deltaTime)
{
	mUpdateCallback(deltaTime, NULL);
}

void
GameApplication::setFOV(Ogre::Real x_angle)
{
	// Assume given measure is in degrees, must convert to radians first
	mCamera->setFOVy(Ogre::Degree(x_angle)/mCamera->getAspectRatio());
}

// TODO: Separate input handler from window and move into separate class and file
bool
GameApplication::keyPressed( const OIS::KeyEvent &arg )
{
    BaseApplication::keyPressed(arg);
    mKeyDownCallback(arg.key, NULL);
    
    return true;
}

bool
GameApplication::keyReleased( const OIS::KeyEvent &arg )
{
    BaseApplication::keyReleased(arg);
    mKeyUpCallback(arg.key, NULL);
    
    return true;
}

bool
GameApplication::mouseMoved( const OIS::MouseEvent &arg )
{
    BaseApplication::mouseMoved(arg);
    
    return true;
}

bool
GameApplication::mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
{
    BaseApplication::mousePressed(arg, id);
    
    return true;
}

bool
GameApplication::mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
{
    BaseApplication::mouseReleased(arg, id);
    
    return true;
}