// Fill out your copyright notice in the Description page of Project Settings.


#include "GyroActor.h"

// Sets default values
AGyroActor::AGyroActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RootComponent"));

	MainMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MainMesh"));
	
	MainMesh->SetupAttachment(RootComponent);

	MainMesh->SetVisibility(true);

}

// Called when the game starts or when spawned
void AGyroActor::BeginPlay()
{
	Super::BeginPlay();

	AFinalPlayerController* PC = Cast<AFinalPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	if (PC == nullptr) return;

	MC = PC->GetSDLController();

	if (MC == nullptr) return;

	UE_LOG(LogTemp, Warning, TEXT("MC caught."));
	
	SDL_GameControllerUpdate();

	SDL_GameControllerSetSensorEnabled(MC, SDL_SENSOR_GYRO, SDL_TRUE);

	SDL_GameControllerSetSensorEnabled(MC, SDL_SENSOR_ACCEL, SDL_TRUE);

	SDL_GameControllerGetSensorData(MC, SDL_SENSOR_GYRO, Corrected, 3);
}

// Called every frame
void AGyroActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SDL_GameControllerUpdate();

	SDL_GameControllerGetSensorData(MC, SDL_SENSOR_GYRO, Gyro, 3);

	SDL_GameControllerGetSensorData(MC, SDL_SENSOR_ACCEL, Accel, 3);

	Corrected[0] = (0.98) * (Corrected[0] + ((Gyro[0] - GyroOffset) * TickRate * GyroScale)) + (0.02) * (Accel[0] - AccelOffset) * (AccelScale);
	Corrected[1] = (0.98) * (Corrected[1] + ((Gyro[1] - GyroOffset) * TickRate * GyroScale)) + (0.02) * (Accel[1] - (9.32f + AccelOffset)) * (AccelScale);
	Corrected[2] = (0.98) * (Corrected[2] + ((Gyro[2] - GyroOffset) * TickRate * GyroScale)) + (0.02) * (Accel[2] - AccelOffset) * (AccelScale);

	GyroEuler.X = Corrected[0];
	GyroEuler.Y = Corrected[1];
	GyroEuler.Z = Corrected[2];

	UE_LOG(LogTemp, Warning, TEXT("Corrected: X = %f, Y = %f, Z = %f"), Corrected[0], Corrected[1], Corrected[2]);
	UE_LOG(LogTemp, Warning, TEXT("Gyro: X = %f, Y = %f, Z = %f"), Gyro[0], Gyro[1], Gyro[2]);
	UE_LOG(LogTemp, Warning, TEXT("Accel: X = %f, Y = %f, Z = %f"), Accel[0], Accel[1], Accel[2]);

	this->SetActorRotation(FQuat::MakeFromEuler(GyroEuler), ETeleportType::None);
}

