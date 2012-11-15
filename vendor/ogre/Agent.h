#include "BaseApplication.h"
#include <deque>

extern Ogre::SceneManager* sceneMgr;	// Defined in main.cpp

class Agent
{
private:
	Ogre::SceneNode* mBodyNode;
	Ogre::Entity* mBodyEntity;

	// all of the animations our character has, and a null ID
	// some of these affect separate body parts and will be blended together

	enum AnimID
	{
		ANIM_IDLE_BASE,
		ANIM_IDLE_TOP,
		ANIM_RUN_BASE,
		ANIM_RUN_TOP,
		ANIM_HANDS_CLOSED,
		ANIM_HANDS_RELAXED,
		ANIM_DRAW_SWORDS,
		ANIM_SLICE_VERTICAL,
		ANIM_SLICE_HORIZONTAL,
		ANIM_DANCE,
		ANIM_JUMP_START,
		ANIM_JUMP_LOOP,
		ANIM_JUMP_END,
		ANIM_NONE
	};

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

	Ogre::AnimationState* mAnims[13];		// master animation list
	AnimID mBaseAnimID;						// current base (full- or lower-body) animation
	AnimID mTopAnimID;						// current top (upper-body) animation
	bool mFadingIn[13];						// which animations are fading in
	bool mFadingOut[13];					// which animations are fading out
	Ogre::Real mTimer;						// general timer to see how long animations have been playing
	Ogre::Real mVerticalVelocity;			// for jumping

	void setupAnimations();
	void setBaseAnimation(AnimID id, bool reset = false);
	void setTopAnimation(AnimID id, bool reset = false);
	void fadeAnimations(Ogre::Real deltaTime);
	void updateAnimations(Ogre::Real deltaTime);
	
	void getObjects();						// Move to each object in turn, and pick it up
};
