#include "Item.h"

extern Ogre::SceneManager* sceneMgr;

Item::Item(std::string name, std::string filename, Ogre::Real scale, bool originIsOnCenter)
{
	using namespace Ogre;
	
	mEquipNode = NULL;	// Should I be freeing this?
	
	mNode = sceneMgr->getRootSceneNode()->createChildSceneNode();
	mEntity = sceneMgr->createEntity(name, filename);
	mNode->attachObject(mEntity);
	
	mNode->setScale(scale, scale, scale);
	
	if(originIsOnCenter){
		Ogre::AxisAlignedBox aab = mEntity->getBoundingBox();
		Ogre::Real height = aab.getSize().y * (1.0f - Ogre::MeshManager::getSingleton().getBoundsPaddingFactor());
		
		Ogre::Real scale = mNode->getScale().y;
		mNode->translate(0, height/2*scale, 0);
	}
}

Item::~Item()
{
}

void
Item::equipTo(Ogre::Entity* agent, std::string attachPoint)
{
	// NOTE: Will have problems attempting to re-equip on a different point
	// Unlink the item from it's current parent.
	mEntity->detachFromParent();
	
	// Link with new parent
	//~ attachPoint->addChild(mNode);
	Ogre::Quaternion orientation;
	Ogre::Vector3 position;
	mEquipNode = agent->attachObjectToBone(attachPoint, mEntity);
	
	// Copy over the scale factor from the old node.
	mEquipNode->setScale(mNode->getScale());
	
	// Set position relative to the parent
	mEquipNode->setPosition(0,0,0);
	
	// Delete old node? IDK RAII?
}

Ogre::String
Item::getName()
{
	return mEntity->getName();
}

void
Item::hide()
{
	if(mEntity != NULL){
		// TODO: Fix the segfault caused by this line
		mEntity->setVisible(false);
	}
}

void
Item::show()
{
	//~ mEntity->setVisible(true);
}

void
Item::update(Ogre::Real deltaTime){
	
}

void
Item::translate(Ogre::Vector3 vec){
	if(mEquipNode != NULL){
		mEquipNode->translate(vec);
	}
	else
	{
		mNode->translate(vec);
	}
}

void
Item::translate(Ogre::Real x, Ogre::Real y, Ogre::Real z){
	if(mEquipNode != NULL){
		mEquipNode->translate(x,y,z);
	}
	else
	{
		mNode->translate(x,y,z);
	}
}

void
Item::roll(const Ogre::Radian &angle, Ogre::Node::TransformSpace
 relativeTo)
{
	if(mEquipNode != NULL){
		mEquipNode->roll(angle, relativeTo);
	}
	else
	{
		mNode->roll(angle, relativeTo);
	}
}

void
Item::pitch(const Ogre::Radian &angle, Ogre::Node::TransformSpace
 relativeTo)
{
	if(mEquipNode != NULL){
		mEquipNode->pitch(angle, relativeTo);
	}
	else
	{
		mNode->pitch(angle, relativeTo);
	}
}

void
Item::yaw(const Ogre::Radian &angle, Ogre::Node::TransformSpace
 relativeTo)
{
	if(mEquipNode != NULL){
		mEquipNode->yaw(angle, relativeTo);
	}
	else
	{
		mNode->yaw(angle, relativeTo);
	}
}

Ogre::Vector3
Item::getPosition()
{
	if(mEquipNode != NULL){
		return mEquipNode->getPosition();
	}
	else
	{
		return mNode->getPosition();
	}
}
