// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "FinalPlayerController.h"
#include "PlayerPawn.h"
#include "SDL/SDL.h"

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
	float TickRate = 0.01f;

	UPROPERTY(EditAnywhere, Category = "Gyro")
	float AccelScale = 1.0f;

	UPROPERTY(EditAnywhere, Category = "Gyro")
	float GyroScale = 1.0f;

	UPROPERTY(EditAnywhere, Category = "Gyro")
	float AccelOffset = 0.0f;

	UPROPERTY(EditAnywhere, Category = "Gyro")
	float GyroOffset = 0.0f;

	FVector GyroEuler;

	SDL_GameController* MC = nullptr;

	float Gyro[3];

	float Accel[3];

	float Corrected[3] = {0,0,0};

	UPROPERTY(EditDefaultsOnly, Category = "Player Pawn Instance")
	TSubclassOf<APlayerPawn> PP;

	UPROPERTY(EditAnywhere, Category = "Mesh")
	UStaticMeshComponent* MainMesh;

	USceneComponent* RootComponent;
};
