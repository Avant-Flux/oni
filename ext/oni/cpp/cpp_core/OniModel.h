#ifndef ONI_MODEL_H
#define ONI_MODEL_H

#include "BaseApplication.h"

namespace Oni
{
	class Model
	{
	public:
		Model();
		virtual ~Model();
		
		// All interface methods should be declared virtual,
		// so that decorators can subclass from this class and add functionality
		
		void initialize(Ogre::SceneManager* sceneMgr, std::string& name, std::string& filename);
		void update(Ogre::Real deltaTime);		// update the game object
		
		// Necessary for extensibility
		// May want to use Friend classes instead
		Ogre::Entity* getEntity();
		
		// Visibility
		bool getVisible();
		void setVisible(bool visible);
		
		// Position
		void setPosition(Ogre::Real x, Ogre::Real y, Ogre::Real z);
		
		void translate(Ogre::Real x, Ogre::Real y, Ogre::Real z, Ogre::Node::TransformSpace relativeTo=Ogre::Node::TS_PARENT);
		void translate(const Ogre::Matrix3 &axes, Ogre::Real x, Ogre::Real y, Ogre::Real z, Ogre::Node::TransformSpace relativeTo=Ogre::Node::TS_PARENT);
		
		// Rotation
		void pitch(const Ogre::Radian &angle, Ogre::Node::TransformSpace relativeTo=Ogre::Node::TS_LOCAL);
		void yaw(const Ogre::Radian &angle, Ogre::Node::TransformSpace relativeTo=Ogre::Node::TS_LOCAL);
		void roll(const Ogre::Radian &angle, Ogre::Node::TransformSpace relativeTo=Ogre::Node::TS_LOCAL);
		
		void rotateTo(double x, double y, double z);
		
		// Set rotation in the horizontal plane (ie, around the y axis)
		// Transformation uses quaternions and is always local
		void setHorizontalPlaneRotation(const Ogre::Radian &angle);

	protected:
		Ogre::SceneManager* mSceneMgr; // TODO: Consider optimizing using flyweight pattern
		
		Ogre::SceneNode* mNode;
		Ogre::Entity* mEntity;
	};
}

#endif /* ONI_MODEL_H */