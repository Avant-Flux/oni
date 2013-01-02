#include "GraphicsObject.h"

GraphicsObject::GraphicsObject()
{
}

GraphicsObject::~GraphicsObject()
{
	
}

void
GraphicsObject::initialize(Ogre::SceneManager* sceneMgr, std::string& name, std::string& filename)
{
	using namespace Ogre;
	
	mSceneMgr = sceneMgr;
	
	mNode = sceneMgr->getRootSceneNode()->createChildSceneNode();
	mEntity = sceneMgr->createEntity(name, filename);
	mNode->attachObject(mEntity);
	
	mNode->setPosition(0,0,0); // make the Ogre stand on the plane
}

void
GraphicsObject::update(Ogre::Real deltaTime)
{
	
}

// Position
void
GraphicsObject::setPosition(const Ogre::Vector3 &pos)
{
	mNode->setPosition(pos);
}

void
GraphicsObject::setPosition(Ogre::Real x, Ogre::Real y, Ogre::Real z)
{
	mNode->setPosition(x,y,z);
}


void
GraphicsObject::translate(const Ogre::Vector3 &d, Ogre::Node::TransformSpace relativeTo)
{
	// Moves the node along the Cartesian axes. 
	mNode->translate(d, relativeTo);
}

void
GraphicsObject::translate(Ogre::Real x, Ogre::Real y, Ogre::Real z, Ogre::Node::TransformSpace relativeTo)
{
	// Moves the node along the Cartesian axes. 
	mNode->translate(x,y,z, relativeTo);
}

void
GraphicsObject::translate(const Ogre::Matrix3 &axes, const Ogre::Vector3 &move, Ogre::Node::TransformSpace relativeTo)
{
	// Moves the node along arbitrary axes. 
	mNode->translate(axes, move, relativeTo);
}

void
GraphicsObject::translate(const Ogre::Matrix3 &axes, Ogre::Real x, Ogre::Real y, Ogre::Real z, Ogre::Node::TransformSpace relativeTo)
{
	// Moves the node along arbitrary axes. 
	mNode->translate(axes, x,y,z, relativeTo);
}
	


// Rotation
void
GraphicsObject::pitch(const Ogre::Radian &angle, Ogre::Node::TransformSpace relativeTo)
{
	
}

void
GraphicsObject::yaw(const Ogre::Radian &angle, Ogre::Node::TransformSpace relativeTo)
{
	
}

void
GraphicsObject::roll(const Ogre::Radian &angle, Ogre::Node::TransformSpace relativeTo)
{
	
}
