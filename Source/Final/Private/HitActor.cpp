// Fill out your copyright notice in the Description page of Project Settings.


#include "HitActor.h"

// Sets default values
AHitActor::AHitActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(RootComponent);
	Sphere->SetCollisionResponseToAllChannels(ECR_Overlap);
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &HitActor::BeginOverlap);

	PC = Cast<AFinalPlayerController>(UGameplayStatics::GetPlayerController(this, 0));

}

// Called when the game starts or when spawned
void AHitActor::BeginPlay()
{
	Super::BeginPlay();
	Sphere->SetSphereRadius(PC->GetSphereRadius());
	
}

// Called every frame
void AHitActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHitActor::SetLoc(FVector HitLoc)
{
	this->SetActorLocation(HitLoc);


}

