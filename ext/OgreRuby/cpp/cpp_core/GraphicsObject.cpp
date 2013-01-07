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
	mSceneMgr = sceneMgr;
	
	mNode = sceneMgr->getRootSceneNode()->createChildSceneNode();
	mEntity = sceneMgr->createEntity(name, filename);
	mNode->attachObject(mEntity);
	
	mNode->setPosition(0,0,0); // Spawn all objects at the origin
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
	mNode->pitch(angle, relativeTo);
}

void
GraphicsObject::yaw(const Ogre::Radian &angle, Ogre::Node::TransformSpace relativeTo)
{
	mNode->yaw(angle, relativeTo);
}

void
GraphicsObject::roll(const Ogre::Radian &angle, Ogre::Node::TransformSpace relativeTo)
{
	mNode->roll(angle, relativeTo);
}

void
GraphicsObject::rotateTo(const Ogre::Vector3 &vec)
{
	Ogre::Vector3 src = mNode->getOrientation() * Ogre::Vector3::UNIT_X;
	Ogre::Quaternion quat = src.getRotationTo(vec); 
	mNode->rotate(quat);
}

void
GraphicsObject::rotateTo(double x, double y, double z)
{
	Ogre::Vector3 vec = Ogre::Vector3(x,y,z);
	GraphicsObject::rotateTo(vec);
}