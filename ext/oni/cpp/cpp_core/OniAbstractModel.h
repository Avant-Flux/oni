#ifndef ONI_ABSTRACT_MODEL_H
#define ONI_ABSTRACT_MODEL_H

#include "BaseApplication.h"

namespace Oni
{
	class AbstractModel
	{
	public:
		AbstractModel();
		virtual ~AbstractModel();
		
		// All interface methods should be declared virtual,
		// so that decorators can subclass from this class and add functionality
		
		virtual void initialize(Ogre::SceneManager* sceneMgr, std::string& name, std::string& filename) = 0;
		virtual void update(Ogre::Real deltaTime) = 0;		// update the game object
		
		// Necessary for extensibility - ie model decorators
		virtual Ogre::Entity* getEntity() = 0;
		
		// Visibility
		virtual bool getVisible() = 0;
		virtual void setVisible(bool visible) = 0;
		
		// Position
		virtual void setPosition(Ogre::Real x, Ogre::Real y, Ogre::Real z) = 0;
		
		virtual void translate(Ogre::Real x, Ogre::Real y, Ogre::Real z, Ogre::Node::TransformSpace relativeTo=Ogre::Node::TS_PARENT) = 0;
		virtual void translate(const Ogre::Matrix3 &axes, const Ogre::Vector3 &move, Ogre::Node::TransformSpace relativeTo=Ogre::Node::TS_PARENT) = 0;
		virtual void translate(const Ogre::Matrix3 &axes, Ogre::Real x, Ogre::Real y, Ogre::Real z, Ogre::Node::TransformSpace relativeTo=Ogre::Node::TS_PARENT) = 0;
		
		// Rotation
		virtual void pitch(const Ogre::Radian &angle, Ogre::Node::TransformSpace relativeTo=Ogre::Node::TS_LOCAL) = 0;
		virtual void yaw(const Ogre::Radian &angle, Ogre::Node::TransformSpace relativeTo=Ogre::Node::TS_LOCAL) = 0;
		virtual void roll(const Ogre::Radian &angle, Ogre::Node::TransformSpace relativeTo=Ogre::Node::TS_LOCAL) = 0;
		
		virtual void rotateTo(double x, double y, double z) = 0;
		
		// Set rotation in the horizontal plane (ie, around the y axis)
		// Transformation uses quaternions and is always local
		virtual void setHorizontalPlaneRotation(const Ogre::Radian &angle) = 0;
	};
}

#endif /* ONI_ABSTRACT_MODEL_H */