#include "AnimationTrack.h"

extern "C" {
	Oni_Animation_TrackPtr Oni_Animation_Track_new(){
		Oni::AnimationTrack* track = new Oni::AnimationTrack();
		
		return (Oni_Animation_TrackPtr)track;
	}
	
	void Oni_Animation_Track_delete(Oni_Animation_TrackPtr obj){
		printf("======DELETING AGENT\n");
		Oni::AnimationTrack* track = (Oni::AnimationTrack*)(obj);
		
		delete track;
	}

	void Oni_Animation_Track_markgc(Oni_Animation_TrackPtr obj){
		printf("======MARK FOR COLLECTION\n");
		Oni::AnimationTrack* track = (Oni::AnimationTrack*)(obj);
		
	}

	void Oni_Animation_Track_initialize(Oni_Animation_TrackPtr obj, Ogre_AnimationStatePtr obj2){
		Oni::AnimationTrack* track = (Oni::AnimationTrack*)(obj);
		Ogre::AnimationState* animationState = (Ogre::AnimationState*)(obj2);
		
		track->initialize(animationState);
	}

	void Oni_Animation_Track_update(Oni_Animation_TrackPtr obj, double dt){
		Oni::AnimationTrack* track = (Oni::AnimationTrack*)(obj);
		
		track->update(dt);
	}
}