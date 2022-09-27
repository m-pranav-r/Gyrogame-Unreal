// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SkeletalMeshComponent.h"
#include "Animation/AnimSequenceBase.h"
#include "UObject/ConstructorHelpers.h" 
#include "Crate_Actor_Anim.h"
#include "Crate_Actor.generated.h"

UCLASS()
class FINAL_API ACrate_Actor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACrate_Actor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void ShootFunction();

	UFUNCTION(BlueprintCallable)
	void PlayEmergeEvent();

	UFUNCTION(BlueprintCallable)
	void StartActiveAction();


private:
	UPROPERTY(EditAnywhere, Category = "Mesh")
	USkeletalMeshComponent* Main_Mesh;

	UCrate_Actor_Anim* AnimInst;

	float shit = 0, remanim = 0;

	int STATE = 0;

};
