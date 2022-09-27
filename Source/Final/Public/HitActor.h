// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "FinalPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "HitActor.generated.h"

UCLASS()
class FINAL_API AHitActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHitActor();

	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFronSweep, const SHitResult& SweepResult);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetLoc(FVector HitLoc);

private:

	UPROPERTY(EditAnywhere, Category = "Sphere")
		USphereComponent* Sphere;

	AFinalPlayerController* PC;

	void OnHit();
};
