#include "AnimationTrack.h"

extern "C" {
	Oni_AnimationTrackPtr Oni_AnimationTrack_new(){
		Oni::AnimationTrack* track = new Oni::AnimationTrack();
		
		return (Oni_AnimationTrackPtr)track;
	}
	
	void Oni_AnimationTrack_delete(Oni_AnimationTrackPtr obj){
		printf("======DELETING AGENT\n");
		Oni::AnimationTrack* track = (Oni::AnimationTrack*)(obj);
		
		delete track;
	}

	void Oni_AnimationTrack_markgc(Oni_AnimationTrackPtr obj){
		printf("======MARK FOR COLLECTION\n");
		Oni::AnimationTrack* track = (Oni::AnimationTrack*)(obj);
		
	}

	void Oni_AnimationTrack_initialize(Oni_AnimationTrackPtr obj, Ogre_AnimationStatePtr obj2){
		Oni::AnimationTrack* track = (Oni::AnimationTrack*)(obj);
		Ogre::AnimationState* animationState = (Ogre::AnimationState*)(obj2);
		
		track->initialize(animationState);
	}

	void Oni_AnimationTrack_update(Oni_AnimationTrackPtr obj, double dt){
		Oni::AnimationTrack* track = (Oni::AnimationTrack*)(obj);
		
		track->update(dt);
	}
}