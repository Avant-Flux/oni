#ifndef GRAPHICS_OBJECT_H
#define GRAPHICS_OBJECT_H

#include "BaseApplication.h"

class GraphicsObject
{
public:
	GraphicsObject();
	virtual ~GraphicsObject();
	virtual void initialize(Ogre::SceneManager* sceneMgr, std::string& name, std::string& filename);
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
	
	void rotateTo(const Ogre::Vector3 &vec);
	void rotateTo(double x, double y, double z);
	
	// Set rotation in the horizontal plane (ie, around the y axis)
	// Transformation uses quaternions and is always local
	void setHorizontalPlaneRotation(const Ogre::Radian &angle);

protected:
	Ogre::SceneManager* mSceneMgr; // TODO: Consider optimizing using flyweight pattern
	
	Ogre::SceneNode* mNode;
	Ogre::Entity* mEntity;
};

#endif /* GRAPHICS_OBJECT_H */