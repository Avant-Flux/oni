#include "GameApplication.h"

#include <cmath>

//-------------------------------------------------------------------------------------
GameApplication::GameApplication(updateCallback callback)
{
	mUpdateCallback = callback;
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

	// disable default camera control so the character can do its own 
	mCameraMan->setStyle(OgreBites::CS_FREELOOK); // CS_FREELOOK, CS_ORBIT, CS_MANUAL

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
	using namespace Ogre;
	//~ items = new std::vector<Item>();
	//~ vector<Item> items(5);
	//~ Item items[5];
}

void // Load actors, agents, characters
GameApplication::loadCharacters()
{
	agent = new Agent();
	std::string agent_name = "Cube";
	std::string agent_mesh = "Cube.mesh";
	agent->initialize(mSceneMgr, agent_name, agent_mesh);
}

void
GameApplication::addTime(Ogre::Real deltaTime)
{
	mUpdateCallback(deltaTime, NULL);
	
	
	if (agent != NULL)
		agent->update(deltaTime);
}

void
GameApplication::setFOV(Ogre::Real x_angle)
{
	// Assume given measure is in degrees, must convert to radians first
	mCamera->setFOVy(Ogre::Degree(x_angle)/mCamera->getAspectRatio());
}
