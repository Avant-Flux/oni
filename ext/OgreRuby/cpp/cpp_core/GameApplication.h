#ifndef __GameApplication_h_
#define __GameApplication_h_

#include "BaseApplication.h"
#include "Agent.h"
//#include <vector>

extern "C" typedef void (*updateCallback)(double dt, void* data);

class GameApplication : public BaseApplication
{
private:
	Agent* agent;			// store a pointer to the character

public:
    GameApplication(updateCallback callback);
    virtual ~GameApplication(void);
    
    virtual bool setup();
    
	void loadEnv();			// Load the buildings or ground plane, etc.
	void setupEnv();		// Set up the lights, shadows, etc
	void loadObjects();		// Load other props or objects (e.g. furniture)
	void loadCharacters();	// Load actors, agents, characters

	void addTime(Ogre::Real deltaTime);		// update the game state
	
	void setFOV(Ogre::Real x_angle);

protected:
	updateCallback mUpdateCallback;
	
    virtual void createScene(void);
};

#endif // #ifndef __GameApplication_h_
