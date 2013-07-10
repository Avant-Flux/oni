#include "OniNode.h"

namespace Oni
{
	Node::Node()
	{
		
	}

	Node::~Node()
	{
		
		
		
		// Detach all objects attached to this one, so they don't freak out when this is gone.
		// Iterate over all objects attached to bones
			// detach them from bones, and re-attach them to scene nodes
			// make those scene nodes direct children of the root node
		
		// Below code in from Oni::Model, but a similar process must be taken for nodes.  If it is not, there will be issues with
		// Ogre::Entity::ChildObjectListIterator iter = mEntity->getAttachedObjectIterator();
		// while(iter.hasMoreElements())
		// {
		// 	Ogre::MovableObject* child = iter.getNext();
			
		// 	mEntity->detachObjectFromBone(child);
			
		// 	Ogre::SceneNode* node;
		// 	node = mSceneMgr->getRootSceneNode()->createChildSceneNode();
		// 	node->attachObject(child);
		// }
		
		mSceneMgr->destroySceneNode(mNode);
	}

	void
	Node::initialize(Ogre::SceneManager* sceneMgr, std::string& name, Ogre::Node* parentNode)
	{
		mSceneMgr = sceneMgr;
		
		this->attachToNewSceneNode(parentNode);
	}
	
	void
	Node::update(Ogre::Real deltaTime)
	{
		
	}
		
	// Position
	void
	Node::setPosition(Ogre::Real x, Ogre::Real y, Ogre::Real z)
	{
		mNode->setPosition(x,y,z);
	}
	
	
	void
	Node::translate(Ogre::Real x, Ogre::Real y, Ogre::Real z, Ogre::Node::TransformSpace relativeTo)
	{
		// Moves the node along the Cartesian axes.
		mNode->translate(x,y,z, relativeTo);
	}
	
	void
	Node::translate(const Ogre::Matrix3 &axes, Ogre::Real x, Ogre::Real y, Ogre::Real z, Ogre::Node::TransformSpace relativeTo)
	{
		// Moves the node along arbitrary axes.
		mNode->translate(axes, x,y,z, relativeTo);
	}
	
	// Rotation
	void
	Node::resetOrientation()
	{
		mNode->resetOrientation();
	}
	
	void
	Node::setOrientation(Ogre::Real w, Ogre::Real x, Ogre::Real y, Ogre::Real z)
	{
		mNode->setOrientation(w,x,y,z);
	}
	
	void
	Node::rotate(const Ogre::Quaternion &q, Ogre::Node::TransformSpace relativeTo)
	{
		mNode->rotate(q, relativeTo);
	}
	
	void
	Node::pitch(const Ogre::Radian &angle, Ogre::Node::TransformSpace relativeTo)
	{
		mNode->pitch(angle, relativeTo);
	}

	void
	Node::yaw(const Ogre::Radian &angle, Ogre::Node::TransformSpace relativeTo)
	{
		mNode->yaw(angle, relativeTo);
	}

	void
	Node::roll(const Ogre::Radian &angle, Ogre::Node::TransformSpace relativeTo)
	{
		mNode->roll(angle, relativeTo);
	}
	
	void
	Node::rotateTo(double x, double y, double z)
	{
		Ogre::Vector3 vec = Ogre::Vector3(x,y,z);
		
		// Ogre::Vector3 src = mNode->getOrientation() * Ogre::Vector3::UNIT_X;
		mNode->resetOrientation();
		
		Ogre::Quaternion quat = Ogre::Vector3::UNIT_X.getRotationTo(vec);
		mNode->setOrientation(quat);
	}

	void
	Node::setHorizontalPlaneRotation(const Ogre::Radian &angle)
	{
		// Reset orientation, and set again
		mNode->resetOrientation();
		
		Ogre::Quaternion quat = Ogre::Quaternion(angle, Ogre::Vector3::UNIT_Y);
		mNode->setOrientation(quat);
		
		// mNode->getOrientation().getYaw(); // get rotation around Y axis
	}
	
	Ogre::Radian
	Node::getHorizontalPlaneRotation()
	{
		return mNode->getOrientation().getYaw();
	}
	
	// Scale
	void
	Node::scale(double x, double y, double z)
	{
		// Adjust scale
		mNode->scale(x,y,z);
	}
	
	void
	Node::setScale(double x, double y, double z)
	{
		// Set scale to specified value
		mNode->setScale(x,y,z);
	}
	
	
	// ===== Private
	Ogre::SceneNode*
	Node::attachToNewSceneNode(Ogre::Node* parentNode){
		Ogre::SceneNode* mNode = mSceneMgr->createSceneNode();
		
		if(parentNode == NULL)
		{
			parentNode = mSceneMgr->getRootSceneNode();
		}
		
		parentNode->addChild(mNode);
		
		mNode->setPosition(0,0,0); // Spawn all objects at the origin
		
		return mNode;
	}
}