// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Kismet/GameplayStatics.h"
#include "FinalPlayerController.h"
#include "SDL/SDL.h"
#include "GamepadMotionHelpers/GamepadMotion.hpp"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"

#include "GyroActor.generated.h"

UCLASS()
class FINAL_API AGyroActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGyroActor();

	void StopCalib();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	AFinalPlayerController* PC = nullptr;

	SDL_GameController* MC = nullptr;

	GamepadMotion MCGM;

	float Gyro[3], Accel[3], Corrected[3], RadToDeg = 180.0f / M_PI;

	FRotator CorGyr;

	FTimerHandle CalibHandle;

	UPROPERTY(EditAnywhere, Category = "Mesh")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere, Category = "Gyro Settings")
	float PitchScale = 1.0f;

	UPROPERTY(EditAnywhere, Category = "Gyro Settings")
	float YawScale = 1.0f;

	UPROPERTY(EditAnywhere, Category = "Gyro Settings")
	float RollScale = 1.0f;
};
