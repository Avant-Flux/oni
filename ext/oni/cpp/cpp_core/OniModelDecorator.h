#ifndef ONI_MODEL_DECORATOR_H
#define ONI_MODEL_DECORATOR_H

#include "OniAbstractModel.h"

namespace Oni
{
	class ModelDecorator :
		AbstractModel
	{
		public:
			ModelDecorator(Oni::AbstractModel* model);
			virtual ~ModelDecorator();
			
			virtual void initialize(Ogre::SceneManager* sceneMgr, std::string& name, std::string& filename) = 0;
			virtual void update(Ogre::Real deltaTime) = 0;		// update the game object
			
			// Necessary for extensibility - ie model decorators
			virtual Ogre::Entity* getEntity();
			
			// Visibility
			virtual bool getVisible();
			virtual void setVisible(bool visible);
			
			// Position
			virtual void setPosition(Ogre::Real x, Ogre::Real y, Ogre::Real z);
			
			virtual void translate(Ogre::Real x, Ogre::Real y, Ogre::Real z, Ogre::Node::TransformSpace relativeTo=Ogre::Node::TS_PARENT);
			virtual void translate(const Ogre::Matrix3 &axes, const Ogre::Vector3 &move, Ogre::Node::TransformSpace relativeTo=Ogre::Node::TS_PARENT);
			virtual void translate(const Ogre::Matrix3 &axes, Ogre::Real x, Ogre::Real y, Ogre::Real z, Ogre::Node::TransformSpace relativeTo=Ogre::Node::TS_PARENT);
			
			// Rotation
			virtual void pitch(const Ogre::Radian &angle, Ogre::Node::TransformSpace relativeTo=Ogre::Node::TS_LOCAL);
			virtual void yaw(const Ogre::Radian &angle, Ogre::Node::TransformSpace relativeTo=Ogre::Node::TS_LOCAL);
			virtual void roll(const Ogre::Radian &angle, Ogre::Node::TransformSpace relativeTo=Ogre::Node::TS_LOCAL);
			
			virtual void rotateTo(double x, double y, double z);
			
			// Set rotation in the horizontal plane (ie, around the y axis)
			// Transformation uses quaternions and is always local
			virtual void setHorizontalPlaneRotation(const Ogre::Radian &angle);
		
		protected:
			Oni::AbstractModel* mDecoratedModel;
	};
}

#endif /* ONI_MODEL_DECORATOR_H */