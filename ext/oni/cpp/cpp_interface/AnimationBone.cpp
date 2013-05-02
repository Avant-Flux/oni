#include "AnimationBone.h"
#include "../cpp_core/OniAnimationBone.h"

extern "C" {
	void Oni_Animation_Bone_delete(Oni_BonePtr obj){
		printf("======DELETING BONE\n");
		Oni::Bone* bone = (Oni::Bone*)(obj);
		
		delete bone;
	}
	
	void Oni_Animation_Bone_markgc(Oni_BonePtr obj){
		printf("======MARK FOR COLLECTION\n");
		Oni::Bone* bone = (Oni::Bone*)(obj);
	}
	
	void Oni_Animation_Bone_update(Oni_BonePtr obj, double dt){
		Oni::Bone* bone = (Oni::Bone*)(obj);
		
		bone->update(dt);
	}
}