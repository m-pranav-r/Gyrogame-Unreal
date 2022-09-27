// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"
#include "FinalHUD.h"
#include "FinalPlayerController.h"
#include "TestActor.h"
#include "PlayerPawn.generated.h"

UCLASS()
class FINAL_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void SendHitRay();

	UPROPERTY(EditDefaultsOnly, Category = "Controller")
	float Deadzone_Right = 0.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Controller")
	float Deadzone_Left = 0.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Controller")
	float Speed_Left = 1.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Controller")
	float Speed_Right = 1.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Controller")
	float Axis_Offset = 0.5f;

	UPROPERTY(EditDefaultsOnly, Category = "Hitscan")
	float Hit_Dist = 0.0f;

private:

	class AFinalHUD* HUDObj;

	TArray<AActor*> ActorArray;

	int32 ActorDist = 0;
};
