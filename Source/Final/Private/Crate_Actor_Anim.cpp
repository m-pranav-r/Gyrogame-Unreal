// Fill out your copyright notice in the Description page of Project Settings.


#include "Crate_Actor_Anim.h"

void UCrate_Actor_Anim::UpdateCrateState(int state)
{
	if (state == 1) {
		isEmerging = true;
	}

	else if (state == 2) {
		isShooting = true;
	}

	else if (state == 3) {
		isDone = true;
	}
}
