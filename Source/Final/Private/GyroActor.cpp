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

	PC = Cast<AFinalPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	if (PC == nullptr) return;

	MC = PC->GetSDLController();

	if (MC == nullptr) return;

	UE_LOG(LogTemp, Warning, TEXT("MC caught."));

	HUD = Cast<AFinalHUD>(PC->GetHUD());

	if (HUD == nullptr) UE_LOG(LogTemp, Warning, TEXT("Didnt get hud"));

	SDL_GameControllerUpdate();

	SDL_GameControllerSetSensorEnabled(MC, SDL_SENSOR_GYRO, SDL_TRUE);

	SDL_GameControllerSetSensorEnabled(MC, SDL_SENSOR_ACCEL, SDL_TRUE);

	SDL_GameControllerGetSensorData(MC, SDL_SENSOR_GYRO, Gyro, 3);

	SDL_GameControllerGetSensorData(MC, SDL_SENSOR_ACCEL, Accel, 3);

}

// Called every frame
void AGyroActor::Tick(float DeltaTime)
{
	/*Corrected[0] = (TimeConstant) * (Corrected[0] + ((Gyro[0] - GyroOffset[0]) * DeltaTime * GyroScale)) + (1 - TimeConstant) * (Accel[0] - AccelOffset[0]) * (AccelScale);
	Corrected[1] = (TimeConstant) * (Corrected[1] + ((Gyro[1] - GyroOffset[1]) * DeltaTime * GyroScale)) + (1 - TimeConstant) * (Accel[1] - AccelOffset[1]) * (AccelScale);
	Corrected[2] = (TimeConstant) * (Corrected[2] + ((Gyro[2] - GyroOffset[2]) * DeltaTime * GyroScale)) + (1 - TimeConstant) * (Accel[2] - AccelOffset[2]) * (AccelScale);*/

	Super::Tick(DeltaTime);

	TimeElapsed += DeltaTime;

	if (!calibdone)
	{
		if (TimeElapsed >= 30.0f) {
			calibdone = true;
			GamepadMotionHelpers::CalibrationMode Sen = GamepadMotionHelpers::CalibrationMode::SensorFusion;
			MCGM.SetCalibrationMode(Sen);
			UE_LOG(LogTemp, Warning, TEXT("Calib done."));
		}
	}

	if (!calib)
	{
		SDL_GameControllerGetSensorData(MC, SDL_SENSOR_GYRO, Gyro, 3);

		SDL_GameControllerGetSensorData(MC, SDL_SENSOR_ACCEL, Accel, 3);

		MCGM.ProcessMotion(Gyro[0], Gyro[1], Gyro[2], Accel[0], Accel[1], Accel[2], DeltaTime);

		MCGM.StartContinuousCalibration();

		GamepadMotionHelpers::CalibrationMode Sti = GamepadMotionHelpers::CalibrationMode::Stillness;

		MCGM.SetCalibrationMode(Sti);

		calib = true;
	}

	SDL_GameControllerUpdate();

	SDL_GameControllerGetSensorData(MC, SDL_SENSOR_GYRO, Gyro, 3);

	SDL_GameControllerGetSensorData(MC, SDL_SENSOR_ACCEL, Accel, 3);

	MCGM.ProcessMotion(Gyro[0], Gyro[1], Gyro[2], Accel[0], Accel[1], Accel[2], DeltaTime);

	MCGM.GetCalibratedGyro(Corrected[0], Corrected[1], Corrected[2]);

	CorGyr = { Corrected[0], Corrected[2], Corrected[1] };

	/*GyroEuler.X = Corrected[0] * TotalScale;
	GyroEuler.Y = Corrected[1] * TotalScale;
	GyroEuler.Z = Corrected[2] * TotalScale;*/

	/*HUD->MoveReticleX(-CorGyr.Roll * GyroRollScale);
	HUD->MoveReticleY(-CorGyr.Pitch * GyroPitchScale);*/

	HUD->MoveReticle(-CorGyr.Pitch * GyroPitchScale, -CorGyr.Roll * GyroRollScale);

	/*GyroQuat.W = GyroW;
	GyroQuat.X = GyroX;
	GyroQuat.Y = GyroY;
	GyroQuat.Z = GyroZ;*/



	/*UE_LOG(LogTemp, Warning, TEXT("Corrected: X = %f, Y = %f, Z = %f"), Corrected[0], Corrected[1], Corrected[2]);
	UE_LOG(LogTemp, Warning, TEXT("Gyro: X = %f, Y = %f, Z = %f"), Gyro[0], Gyro[1], Gyro[2]);
	UE_LOG(LogTemp, Warning, TEXT("Accel: X = %f, Y = %f, Z = %f"), Accel[0], Accel[1], Accel[2]);*/

	//this->SetActorRotation(CorGyr, ETeleportType::None);
	//this->SetActorRelativeRotation(GyroQuat, ETeleportType::None);
	//this->SetActorRelativeRotation(CorGyr, false, nullptr, ETeleportType::None);

}