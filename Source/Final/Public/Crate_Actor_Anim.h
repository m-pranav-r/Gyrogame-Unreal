// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Crate_Actor_Anim.generated.h"

/**
 * 
 */
UCLASS()
class FINAL_API UCrate_Actor_Anim : public UAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool isHiding = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool isEmerging = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool isShooting	 = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool isDone = false;


	UFUNCTION(BlueprintCallable, Category = "State")
		void UpdateCrateState(int state);
	
};
