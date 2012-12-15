#ifndef AGENT_H
#define AGENT_H

#include "BaseApplication.h"
#include <deque>

extern Ogre::SceneManager* sceneMgr;	// Defined in main.cpp

class Agent
{
protected:
		std::map<std::string, Ogre::AnimationState*> mAnims; // master animation list
		std::map<std::string, bool> mFadingIn;	// which animations are fading in
		std::map<std::string, bool> mFadingOut;	// which animations are fading out
		std::string mBaseAnimID;				// current base (full- or lower-body) animation
		std::string mTopAnimID;					// current top (upper-body) animation
		Ogre::Real mTimer;						// general timer to see how long animations have been playing
		
private:
	Ogre::SceneNode* mBodyNode;
	Ogre::Entity* mBodyEntity;

	// all of the animations our character has, and a null ID
	// some of these affect separate body parts and will be blended together

	// for locomotion
	Ogre::Real mDistance;					// The distance the agent has left to travel
	Ogre::Vector3 mDirection;				// The direction the object is moving
	void faceForward();

public:
	Agent(std::string name, std::string filename);
	virtual ~Agent();

	void update(Ogre::Real deltaTime);		// update the agent
	
	void setupAnimations();
	void setBaseAnimation(std::string id, bool reset = false);
	void setTopAnimation(std::string id, bool reset = false);
	void fadeAnimations(Ogre::Real deltaTime);
	void updateAnimations(Ogre::Real deltaTime);
	
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
	
	
			
	// Time
	Ogre::Real getAnimationTime();			// Get the current animation timer
	void resetAnimationTime();
};

#endif /* AGENT_H */