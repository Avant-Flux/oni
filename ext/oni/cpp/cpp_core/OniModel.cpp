#include "OniModel.h"

namespace Oni
{
	Model::Model()
	{
		
	}

	Model::~Model()
	{
		mNode->detachObject(mEntity);
		mSceneMgr->destroyEntity(mEntity);
		mSceneMgr->destroySceneNode(mNode);
	}

	void
	Model::initialize(Ogre::SceneManager* sceneMgr, std::string& name, std::string& filename)
	{
		mSceneMgr = sceneMgr;
		
		mNode = sceneMgr->getRootSceneNode()->createChildSceneNode();
		mEntity = sceneMgr->createEntity(name, filename);
		mNode->attachObject(mEntity);
		
		mNode->setPosition(0,0,0); // Spawn all objects at the origin
	}

	void
	Model::update(Ogre::Real deltaTime)
	{
		
	}
	
	Ogre::Entity*
	Model::getEntity()
	{
		return mEntity;
	}
	
	// Visibility
	bool
	Model::getVisible()
	{
		return mEntity->getVisible();
	}

	void
	Model::setVisible(bool visible)
	{
		mEntity->setVisible(visible);
	}

	// Position
	void
	Model::setPosition(Ogre::Real x, Ogre::Real y, Ogre::Real z)
	{
		mNode->setPosition(x,y,z);
	}


	void
	Model::translate(Ogre::Real x, Ogre::Real y, Ogre::Real z, Ogre::Node::TransformSpace relativeTo)
	{
		// Moves the node along the Cartesian axes. 
		mNode->translate(x,y,z, relativeTo);
	}
	
	void
	Model::translate(const Ogre::Matrix3 &axes, Ogre::Real x, Ogre::Real y, Ogre::Real z, Ogre::Node::TransformSpace relativeTo)
	{
		// Moves the node along arbitrary axes. 
		mNode->translate(axes, x,y,z, relativeTo);
	}
		


	// Rotation
	void Model::resetOrientation()
	{
		mNode->resetOrientation();
	}
	
	void
	Model::pitch(const Ogre::Radian &angle, Ogre::Node::TransformSpace relativeTo)
	{
		mNode->pitch(angle, relativeTo);
	}

	void
	Model::yaw(const Ogre::Radian &angle, Ogre::Node::TransformSpace relativeTo)
	{
		mNode->yaw(angle, relativeTo);
	}

	void
	Model::roll(const Ogre::Radian &angle, Ogre::Node::TransformSpace relativeTo)
	{
		mNode->roll(angle, relativeTo);
	}
	
	void
	Model::rotateTo(double x, double y, double z)
	{
		Ogre::Vector3 vec = Ogre::Vector3(x,y,z);
		
		// Ogre::Vector3 src = mNode->getOrientation() * Ogre::Vector3::UNIT_X;
		mNode->resetOrientation();
		
		Ogre::Quaternion quat = Ogre::Vector3::UNIT_X.getRotationTo(vec); 
		mNode->setOrientation(quat);
	}

	void
	Model::setHorizontalPlaneRotation(const Ogre::Radian &angle)
	{
		// Reset orientation, and set again
		mNode->resetOrientation();
		
		Ogre::Quaternion quat = Ogre::Quaternion(angle, Ogre::Vector3::UNIT_Y);
		mNode->setOrientation(quat);
		
		// mNode->getOrientation().getYaw(); // get rotation around Y axis
	}
	
	// Scale
	void
	Model::scale(double x, double y, double z)
	{
		// Adjust scale
		mNode->scale(x,y,z);
	}
	
	void
	Model::setScale(double x, double y, double z)
	{
		// Set scale to specified value
		mNode->setScale(x,y,z);
	}
}