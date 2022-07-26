// Fill out your copyright notice in the Description page of Project Settings.


#include "FinalPlayerController.h"

void AFinalPlayerController::BeginPlay()
{
	SDL_Init(SDL_INIT_GAMECONTROLLER | SDL_INIT_SENSOR);

	SDL_SetHint(SDL_HINT_JOYSTICK_HIDAPI_PS4_RUMBLE, "1");

	SDL_SetHint(SDL_HINT_JOYSTICK_HIDAPI_PS5_RUMBLE, "1");

	MainController = SDL_GameControllerOpen(0);

	if (MainController == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Controller not found, exiting."));

		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("Controller found."));

	if (SDL_GameControllerSetSensorEnabled(MainController, SDL_SENSOR_GYRO, SDL_TRUE) < 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Controller sensors not found, exiting."));

		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("Controller sensors found."));

	SDL_GameControllerUpdate();

	SDL_GameControllerSetSensorEnabled(MainController, SDL_SENSOR_GYRO, SDL_TRUE);

	SDL_GameControllerSetSensorEnabled(MainController, SDL_SENSOR_ACCEL, SDL_TRUE);
}

SDL_GameController* AFinalPlayerController::GetSDLController()
{
	return MainController;
}


float AFinalPlayerController::GetRollScale()
{
	return GyroRollScale;
}

float AFinalPlayerController::GetPitchScale()
{
	return GyroPitchScale;
}

float AFinalPlayerController::GetTempScale()
{
	return TempScale;
}

float AFinalPlayerController::GetSphereRadius()
{
	return Radius;
}
