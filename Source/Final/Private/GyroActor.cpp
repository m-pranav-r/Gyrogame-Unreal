// Fill out your copyright notice in the Description page of Project Settings.


#include "GyroActor.h"

// Sets default values
AGyroActor::AGyroActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Default Mesh"));

	MeshComp->SetupAttachment(RootComponent);

	MeshComp->SetVisibility(true);

}

// Called when the game starts or when spawned
void AGyroActor::BeginPlay()
{
	Super::BeginPlay();

	PC = Cast<AFinalPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	if (PC == nullptr) return;

	MC = PC->GetSDLController();

	if (MC == nullptr) return;

	UE_LOG(LogTemp, Warning, TEXT("MC caught."));

	SDL_GameControllerUpdate();

	SDL_GameControllerSetSensorEnabled(MC, SDL_SENSOR_GYRO, SDL_TRUE);

	SDL_GameControllerSetSensorEnabled(MC, SDL_SENSOR_ACCEL, SDL_TRUE);

	SDL_GameControllerGetSensorData(MC, SDL_SENSOR_GYRO, Gyro, 3);

	SDL_GameControllerGetSensorData(MC, SDL_SENSOR_ACCEL, Accel, 3);

	MCGM.ProcessMotion(Gyro[0], Gyro[1], Gyro[2], Accel[0], Accel[1], Accel[2], 0.01);

	MCGM.StartContinuousCalibration();

	MCGM.SetCalibrationMode(GamepadMotionHelpers::CalibrationMode::Stillness);

	GetWorld()->GetTimerManager().SetTimer(CalibHandle, this, &AGyroActor::StopCalib, 10.0f, false);
	
}

// Called every frame
void AGyroActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SDL_GameControllerUpdate();

	SDL_GameControllerGetSensorData(MC, SDL_SENSOR_GYRO, Gyro, 3);

	SDL_GameControllerGetSensorData(MC, SDL_SENSOR_ACCEL, Accel, 3);

	MCGM.ProcessMotion(Gyro[0] * RadToDeg, Gyro[1] * RadToDeg, Gyro[2] * RadToDeg, Accel[0] / SDL_STANDARD_GRAVITY, Accel[1] / SDL_STANDARD_GRAVITY, Accel[2] / SDL_STANDARD_GRAVITY, DeltaTime);

	MCGM.GetCalibratedGyro(Corrected[0], Corrected[1], Corrected[2]);

	//UE_LOG(LogTemp, Warning, TEXT("X = %f, Y = %f, Z = %f"), Corrected[0], Corrected[1], Corrected[2]);
	//UE_LOG(LogTemp, Warning, TEXT("GX = %f, GY = %f, GZ = %f"), Gyro[0], Gyro[1], Gyro[2]);
	//UE_LOG(LogTemp, Warning, TEXT("AX = %f, AY = %f, AZ = %f"), Accel[0], Accel[1], Accel[2]);

	CorGyr.Pitch += Corrected[0] * PitchScale;

	CorGyr.Yaw += Corrected[2] * YawScale;

	CorGyr.Roll += Corrected[1] * RollScale;

	SetActorRelativeRotation(CorGyr, false, nullptr, ETeleportType::None);

}

void AGyroActor::StopCalib()
{
	MCGM.SetCalibrationMode(GamepadMotionHelpers::CalibrationMode::Stillness | GamepadMotionHelpers::CalibrationMode::SensorFusion);
}

