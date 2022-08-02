// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActor.h"

// Sets default values
ATestActor::ATestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	Normal_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DefaultMesh"));

	Normal_Mesh->SetupAttachment(RootComponent);

	OnHit_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HitMesh"));

	OnHit_Mesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	Super::BeginPlay();

	Normal_Mesh->SetVisibility(true);

	OnHit_Mesh->SetVisibility(false);
}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATestActor::Register_Hit()
{
	Normal_Mesh->SetVisibility(false);

	OnHit_Mesh->SetVisibility(true);

	UE_LOG(LogTemp, Warning, TEXT("ATestActor::Register_Hit()"));
}





