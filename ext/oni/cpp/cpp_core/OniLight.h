#ifndef ONI_LIGHT_H
#define ONI_LIGHT_H

#include "BaseApplication.h"

namespace Oni
{
	class Light
	{
	public:
		Light();
		virtual ~Light();
		
		virtual void initialize(Ogre::SceneManager* sceneMgr);
		virtual void update(Ogre::Real deltaTime);
	
	private:
		Ogre::Light* mLight;
	};
}

#endif