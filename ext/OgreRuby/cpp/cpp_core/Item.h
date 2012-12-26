#ifndef ITEM_H
#define ITEM_H

#include "BaseApplication.h"
#include "OgreTagPoint.h"

class Item
{
	private:
		Ogre::SceneNode* mNode;
		Ogre::Entity* mEntity;
		Ogre::TagPoint* mEquipNode;
	
	public:
		Item(Ogre::SceneManager* sceneMgr, std::string name, std::string filename, Ogre::Real scale, bool originIsOnCenter=false);
		virtual ~Item();
		
		void update(Ogre::Real deltaTime);		// update the Item
		
		void equipTo(Ogre::Entity* agent, std::string attachPoint);
		Ogre::String getName();
		
		// Visibility control
		void hide();
		void show();
		
		// Position modifiers
		void translate(Ogre::Vector3 vec);
		void translate(Ogre::Real x, Ogre::Real y, Ogre::Real z);
		
		void roll(const Ogre::Radian &angle, Ogre::Node::TransformSpace
 relativeTo=Ogre::Node::TS_LOCAL);
		void pitch(const Ogre::Radian &angle, Ogre::Node::TransformSpace
 relativeTo=Ogre::Node::TS_LOCAL);
		void yaw(const Ogre::Radian &angle, Ogre::Node::TransformSpace
 relativeTo=Ogre::Node::TS_LOCAL);
		
		Ogre::Vector3 getPosition();
};

#endif /* ITEM_H */ 
