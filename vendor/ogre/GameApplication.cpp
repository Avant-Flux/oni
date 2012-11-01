#include "GameApplication.h"

//-------------------------------------------------------------------------------------
GameApplication::GameApplication(void)
{
	agent = NULL;
}
//-------------------------------------------------------------------------------------
GameApplication::~GameApplication(void)
{
	delete agent;
	delete [] items;
}

//-------------------------------------------------------------------------------------
void GameApplication::createScene(void)
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
	items = new Item*[5];
	items[0] = new Item("fish", "fish.mesh", 0.5, true);
	items[0]->translate(-30,0,0);
	
	items[1] = new Item("9mm", "9mm.mesh", 0.1, true);
	items[1]->translate(-25,0,5);
	
	items[2] = new Item("38pistol", "38pistol.mesh", 0.1, true);
	items[2]->translate(0,0,0);
	
	items[3] = new Item("briefcase", "briefcase.mesh", 0.5, true);
	items[3]->translate(25,0,-5);
	
	items[4] = new Item("thermos", "thermos.mesh", 0.1);
	items[4]->translate(40,0,0);
}

void // Load actors, agents, characters
GameApplication::loadCharacters()
{
	agent = new Agent("Sinbad", "Sinbad.mesh", items);
	agent->getObjects();
}

void
GameApplication::addTime(Ogre::Real deltaTime)
{
	if (agent != NULL)
		agent->update(deltaTime);
	//~ for(vector<Item>::iterator item = items.begin(); item != items.end(); item++){
	for(int i=0; i<5; i++){
		Item* item = items[i];
		
		if(item != NULL){
			item->update(deltaTime);
		}
	}
}
