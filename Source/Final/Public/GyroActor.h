// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "FinalPlayerController.h"
#include "FinalHUD.h"
#include "PlayerPawn.h"
#include "SDL/SDL.h"
#include "GamepadMotionHelpers/GamepadMotion.hpp"

#include "TimerManager.h"
#include "Components/StaticMeshComponent.h"

#include "GyroActor.generated.h"

UCLASS()
class FINAL_API AGyroActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGyroActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditAnywhere, Category = "Gyro")
	float GyroRollScale = 1.0f;

	UPROPERTY(EditAnywhere, Category = "Gyro")
	float GyroPitchScale = 1.0f;

	float TimeElapsed = 0.0f;

	bool calib = false;

	bool calibdone = false;

	SDL_GameController* MC = nullptr;

	GamepadMotion MCGM;

	float Gyro[3] = {0,0,0};

	float Accel[3] = {0,0,0};

	float Corrected[3] = {0,0,0};

	UPROPERTY(EditAnywhere, Category = "Gyro")
	float GyroOffset[3] = { -0.002756f, 0.001150f, 0.003473f};

	UPROPERTY(EditAnywhere, Category = "Gyro")
	float AccelOffset[3] = { 0.355932f, 9.224708f, 1.960240f};

	FRotator CorGyr = {0,0,0};

	FVector GyroEuler;

	UPROPERTY(EditDefaultsOnly, Category = "Player Pawn Instance")
	TSubclassOf<APlayerPawn> PP;

	UPROPERTY(EditAnywhere, Category = "Mesh")
	UStaticMeshComponent* MainMesh;

	USceneComponent* RootComponent;

	AFinalPlayerController* PC;

	AFinalHUD* HUD;
};
