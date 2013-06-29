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
	Light::initialize(Ogre::SceneManager* sceneMgr, std::string& name, Ogre::Node* parentNode)
	{
		mSceneMgr = sceneMgr;
		
		mLight = sceneMgr->createLight(name);
		this->attachToNewSceneNode(parentNode);
	}

	void
	Light::update(Ogre::Real deltaTime)
	{
		
	}
	
	Ogre::Node*
	Light::getParentNode()
	{
		return mLight->getParentNode();
	}
	
	// ===== Private
	Ogre::SceneNode*
	Light::attachToNewSceneNode(Ogre::Node* parentNode){
		Ogre::SceneNode* node = mSceneMgr->createSceneNode();
		
		if(parentNode == NULL)
		{
			parentNode = mSceneMgr->getRootSceneNode();
		}
		
		// NOTE: May have to detach light from previous parent, and destroy old parent node
		parentNode->addChild(node);
		
		node->attachObject(mLight);
		node->setPosition(mLight->getPosition());
		mLight->setPosition(0,0,0);
		
		return node;
	}
}