// Fill out your copyright notice in the Description page of Project Settings.


#include "Crate_Actor.h"

// Sets default values
ACrate_Actor::ACrate_Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Main_Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkelMesh"));
	Main_Mesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ACrate_Actor::BeginPlay()
{
	Super::BeginPlay();
	AnimInst = Cast<UCrate_Actor_Anim>(Main_Mesh->GetAnimInstance());
	if (AnimInst) UE_LOG(LogTemp, Warning, TEXT("AnimInst found."));
	
}

// Called every frame
void ACrate_Actor::Tick(float DeltaTime)
{
	
}

void ACrate_Actor::ShootFunction()
{
	UE_LOG(LogTemp, Warning, TEXT("ShootFunction() called."));
}

void ACrate_Actor::PlayEmergeEvent()
{
	UE_LOG(LogTemp, Warning, TEXT("PlayEmergeEvent() called."));
	STATE = 1;
	AnimInst->UpdateCrateState(STATE);

}

void ACrate_Actor::StartActiveAction()
{
	UE_LOG(LogTemp, Warning, TEXT("StartActiveAction() called."));
	STATE = 2;
	AnimInst->UpdateCrateState(STATE);
}


