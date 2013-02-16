#include "AnimationTrack.h"

extern "C" {
	void Oni_Animation_Track_update(Oni_Animation_TrackPtr obj, double dt){
		Oni::AnimationTrack* track = (Oni::AnimationTrack*)(obj);
		
		track->update(dt);
	}
}