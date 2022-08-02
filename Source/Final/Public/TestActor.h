// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "TestActor.generated.h"

UCLASS()
class FINAL_API ATestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Register_Hit();

	UPROPERTY(EditAnywhere, Category = "Mesh")
	USceneComponent* Normal_Mesh;

	UPROPERTY(EditAnywhere, Category = "Mesh")
	USceneComponent* OnHit_Mesh;
	
};
