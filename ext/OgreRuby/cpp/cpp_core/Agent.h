#ifndef AGENT_H
#define AGENT_H

#include "BaseApplication.h"
#include "GraphicsObject.h"

#include <deque>

class Agent :
	public GraphicsObject
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
	Agent();
	virtual ~Agent();
	virtual void initialize(Ogre::SceneManager* sceneMgr, std::string& name, std::string& filename);
	virtual void update(Ogre::Real deltaTime);		// update the agent
	
	bool getVisible();
	void setVisible(bool visible);
	
	void setupAnimations();
	void setBaseAnimation(std::string id, bool reset = false);
	void setTopAnimation(std::string id, bool reset = false);
	void fadeAnimations(Ogre::Real deltaTime);
	void updateAnimations(Ogre::Real deltaTime);
	
	// Time
	Ogre::Real getAnimationTime();			// Get the current animation timer
	void resetAnimationTime();
};

#endif /* AGENT_H */