#ifndef GRAPHICS_OBJECT_H
#define GRAPHICS_OBJECT_H

#include "BaseApplication.h"

class GraphicsObject
{
public:
	GraphicsObject(Ogre::SceneManager* sceneMgr, std::string name, std::string filename);
	virtual ~GraphicsObject();
	
	virtual void update(Ogre::Real deltaTime);		// update the game object
	
	// Position
	void setPosition(const Ogre::Vector3 &pos);
	void setPosition(Ogre::Real x, Ogre::Real y, Ogre::Real z);
	
	void translate(const Ogre::Vector3 &d, Ogre::Node::TransformSpace relativeTo=Ogre::Node::TS_PARENT);
	void translate(Ogre::Real x, Ogre::Real y, Ogre::Real z, Ogre::Node::TransformSpace relativeTo=Ogre::Node::TS_PARENT);
	void translate(const Ogre::Matrix3 &axes, const Ogre::Vector3 &move, Ogre::Node::TransformSpace relativeTo=Ogre::Node::TS_PARENT);
	void translate(const Ogre::Matrix3 &axes, Ogre::Real x, Ogre::Real y, Ogre::Real z, Ogre::Node::TransformSpace relativeTo=Ogre::Node::TS_PARENT);
	
	// Rotation
	void pitch(const Ogre::Radian &angle, Ogre::Node::TransformSpace relativeTo=Ogre::Node::TS_LOCAL);
	void yaw(const Ogre::Radian &angle, Ogre::Node::TransformSpace relativeTo=Ogre::Node::TS_LOCAL);
	void roll(const Ogre::Radian &angle, Ogre::Node::TransformSpace relativeTo=Ogre::Node::TS_LOCAL);

protected:
	Ogre::SceneNode* mNode;
	Ogre::Entity* mEntity;
};

#endif /* GRAPHICS_OBJECT_H */