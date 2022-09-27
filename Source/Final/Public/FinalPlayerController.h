// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SDL/SDL.h"
#include "GamepadMotionHelpers/GamepadMotion.hpp"
#include "TimerManager.h"
#include "GameFramework/PlayerController.h"
#include "FinalPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class FINAL_API AFinalPlayerController : public APlayerController
{
	GENERATED_BODY()

private:

	SDL_GameController* MainController = nullptr;

	GamepadMotion MainControllerGM;

	FTimerHandle CalibHandle;

	UPROPERTY(EditAnywhere, Category = "Gyro Settings")
	float GyroRollScale = 1.0f;

	UPROPERTY(EditAnywhere, Category = "Gyro Settings")
	float GyroPitchScale= 1.0f;

	UPROPERTY(EditAnywhere, Category = "Gyro Settings")
	float TempScale = 1.0f;

	UPROPERTY(EditAnywhere, Category = "Hitscan Settings")
		float Radius = 1.0f;

public:

	virtual void BeginPlay() override;

	SDL_GameController* GetSDLController();

	float GetRollScale();

	float GetPitchScale();

	float GetTempScale();

	float GetSphereRadius();
};
