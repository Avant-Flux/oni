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
		Ogre::Real mVerticalVelocity;			// for jumping
		
private:
	Ogre::SceneNode* mBodyNode;
	Ogre::Entity* mBodyEntity;

	// all of the animations our character has, and a null ID
	// some of these affect separate body parts and will be blended together

	// for locomotion
	Ogre::Real mDistance;					// The distance the agent has left to travel
	Ogre::Vector3 mDirection;				// The direction the object is moving
	Ogre::Vector3 mDestination;				// The destination the object is moving towards
	std::deque<Ogre::Vector3> mWalkList;	// The list of points we are walking to
	Ogre::Real mWalkSpeed;					// The speed at which the object is moving
	bool nextLocation();					// Is there another destination?
	void updateLocomote(Ogre::Real deltaTime);			// update the character's walking
	void faceForward();
							
	// bend animation methods return true IFF the animation has completed
	bool bendOver(Ogre::Real deltaTime);	// Bend at the waist. Used to pick up items on the ground.
	bool bendToStand(Ogre::Real deltaTime);	// Return from bent over to the standing position

public:
	Agent(std::string name, std::string filename);
	~Agent();

	void update(Ogre::Real deltaTime);		// update the agent
	
	void setupAnimations();
	void setBaseAnimation(std::string id, bool reset = false);
	void setTopAnimation(std::string id, bool reset = false);
	void fadeAnimations(Ogre::Real deltaTime);
	void updateAnimations(Ogre::Real deltaTime);
	
			
	// Time
	Ogre::Real getAnimationTime();			// Get the current animation timer
	void resetAnimationTime();

	
	void getObjects();						// Move to each object in turn, and pick it up
};
