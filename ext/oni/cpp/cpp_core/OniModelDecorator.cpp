#include "OniModelDecorator.h"

namespace Oni
{
	ModelDecorator::ModelDecorator(Oni::AbstractModel* model)
	{
		mDecoratedModel = model;
	}
	
	ModelDecorator::~ModelDecorator()
	{
		
	}
	
	// All interface methods should be declared virtual,
	// so that decorators can subclass from this class and add functionality
	
	void
	ModelDecorator::initialize(Ogre::SceneManager* sceneMgr, std::string& name, std::string& filename)
	{
		// Chaining the initializer is unnecessary
		// That would make this very similar to inheritance,
		// but in this design the components can be initialized separately
		// 
		// Think of it like the Builder pattern
		
		// mDecoratedModel->initialize(sceneMgr, name, filename);
	}
	
	void
	ModelDecorator::update(Ogre::Real deltaTime)
	{
		// TODO: Check if this necessary
		// Probably should not chain because that would make update order dependent on
		// chaining order.  Update order may or may not be important, but should not
		// decide here.
		
		// mDecoratedModel->update(deltaTime);
	}
	
	Ogre::Entity*
	ModelDecorator::getEntity()
	{
		return mDecoratedModel->getEntity();
	}
	
	// Visibility
	bool
	ModelDecorator::getVisible()
	{
		return mDecoratedModel->getVisible();
	}
	
	void
	ModelDecorator::setVisible(bool visible)
	{
		mDecoratedModel->setVisible(visible);
	}
	
	
	
	// Position
	void
	ModelDecorator::setPosition(Ogre::Real x, Ogre::Real y, Ogre::Real z)
	{
		mDecoratedModel->setPosition(x,y,z);
	}
	
	void
	ModelDecorator::translate(Ogre::Real x, Ogre::Real y, Ogre::Real z, Ogre::Node::TransformSpace relativeTo)
	{
		mDecoratedModel->translate(x,y,z, relativeTo);
	}
	
	void
	ModelDecorator::translate(const Ogre::Matrix3 &axes, const Ogre::Vector3 &move, Ogre::Node::TransformSpace relativeTo)
	{
		mDecoratedModel->translate(axes, move, relativeTo);
	}
	
	void
	ModelDecorator::translate(const Ogre::Matrix3 &axes, Ogre::Real x, Ogre::Real y, Ogre::Real z, Ogre::Node::TransformSpace relativeTo)
	{
		mDecoratedModel->translate(axes, x,y,z, relativeTo);
	}
	
	
	// Rotation
	void
	ModelDecorator::pitch(const Ogre::Radian &angle, Ogre::Node::TransformSpace relativeTo)
	{
		mDecoratedModel->pitch(angle, relativeTo);
	}
	
	void
	ModelDecorator::yaw(const Ogre::Radian &angle, Ogre::Node::TransformSpace relativeTo)
	{
		mDecoratedModel->yaw(angle, relativeTo);
	}
	
	void
	ModelDecorator::roll(const Ogre::Radian &angle, Ogre::Node::TransformSpace relativeTo)
	{
		mDecoratedModel->roll(angle, relativeTo);
	}
	
	
	void
	ModelDecorator::rotateTo(double x, double y, double z)
	{
		mDecoratedModel->rotateTo(x,y,z);
	}
	
	
	// Set rotation in the horizontal plane (ie, around the y axis)
	// Transformation uses quaternions and is always local
	void
	ModelDecorator::setHorizontalPlaneRotation(const Ogre::Radian &angle)
	{
		mDecoratedModel->setHorizontalPlaneRotation(angle);
	}
}

