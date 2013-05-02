#include "AnimationBone.h"
#include "../cpp_core/OniAnimationBone.h"

extern "C" {
	void Oni_Animation_Bone_delete(Oni_Animation_BonePtr obj){
		printf("======DELETING BONE\n");
		Oni::AnimationBone* bone = (Oni::AnimationBone*)(obj);
		
		delete bone;
	}
	
	void Oni_Animation_Bone_markgc(Oni_Animation_BonePtr obj){
		printf("======MARK FOR COLLECTION\n");
		Oni::AnimationBone* bone = (Oni::AnimationBone*)(obj);
	}
	
	void Oni_Animation_Bone_update(Oni_Animation_BonePtr obj, double dt){
		Oni::AnimationBone* bone = (Oni::AnimationBone*)(obj);
		
		bone->update(dt);
	}
}