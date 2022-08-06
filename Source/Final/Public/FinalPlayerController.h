// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FinalHUD.h"
#include "SDL/SDL.h"
#include "Kismet/GameplayStatics.h"
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

	void InitControllerCalib();

	SDL_GameController* MainController = nullptr;

	float Gyro[3];

	float Accel[3];

	float AccelOffset[3];

public:

	virtual void BeginPlay() override;

	SDL_GameController* GetSDLController();
};
