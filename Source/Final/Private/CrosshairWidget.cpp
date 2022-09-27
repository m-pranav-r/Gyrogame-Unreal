// Fill out your copyright notice in the Description page of Project Settings.


#include "CrosshairWidget.h"


void UCrosshairWidget::NativeConstruct()
{
	Super::NativeConstruct();

	UE_LOG(LogTemp, Warning, TEXT("Widget Created."));

	RTTemp.X = 0.0f;

	RTTemp.Y = 0.0f;

	ImageDefPos = FVector2D(GEngine->GameViewport->Viewport->GetSizeXY());

	ImageDefPos = FVector2D(ImageDefPos.X/2, ImageDefPos.Y/2);

	AFinalPlayerController* PC = Cast<AFinalPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	if (PC == nullptr) return;

	MainController = PC->GetSDLController();

	GyroPitchScale = PC->GetPitchScale();

	GyroRollScale = PC->GetRollScale();

	TempScale = PC->GetTempScale();

	float TempGyro[3], TempAccel[3];

	SDL_GameControllerGetSensorData(MainController, SDL_SENSOR_GYRO, TempGyro, 3);

	SDL_GameControllerGetSensorData(MainController, SDL_SENSOR_ACCEL, TempAccel, 3);

	MainControllerGM.ProcessMotion(TempGyro[0], TempGyro[1], TempGyro[2], TempAccel[0], TempAccel[1], TempAccel[2], 0);

	MainControllerGM.StartContinuousCalibration();

	GamepadMotionHelpers::CalibrationMode Sti = GamepadMotionHelpers::CalibrationMode::Stillness;

	MainControllerGM.SetCalibrationMode(Sti);

	GetWorld()->GetTimerManager().SetTimer(CalibHandle, this, &UCrosshairWidget::StopControllerCalib, 10.0f, false);

	UE_LOG(LogTemp, Warning, TEXT("Native Construct complete."));
}

void UCrosshairWidget::Move(float Axis1, float Axis2, float Axis3)
{
	RTTemp.X += Axis1;
	
	RTTemp.Y += Axis2;

	TempShear += Axis3;

	CrosshairImage->SetRenderTranslation(RTTemp);

	CrosshairImage->SetRenderTransformAngle(TempShear);
}

void UCrosshairWidget::Set(float Axis1, float Axis2)
{
	CrosshairImage->SetRenderTranslation({Axis1, Axis2});
}

void UCrosshairWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	/*Super::NativeTick(MyGeometry, InDeltaTime);

	SDL_GameControllerUpdate();

	SDL_GameControllerGetSensorData(MainController, SDL_SENSOR_GYRO, Gyro, 3);

	SDL_GameControllerGetSensorData(MainController, SDL_SENSOR_ACCEL, Accel, 3);

	MainControllerGM.ProcessMotion(Gyro[0], Gyro[1], Gyro[2], Accel[0], Accel[1], Accel[2], InDeltaTime);

	MainControllerGM.GetCalibratedGyro(Corrected[0], Corrected[1], Corrected[2]);

	Move(Corrected[0] * GyroPitchScale, Corrected[1] * GyroRollScale, Corrected[2] * TempScale);*/
}

FVector2D UCrosshairWidget::GetImageCoords()
{
	//UE_LOG(LogTemp, Warning, TEXT("X = %f, Y = %f"),ImageDefPos.X + RTTemp.X, ImageDefPos.Y + RTTemp.Y);

	return FVector2D(ImageDefPos.X + RTTemp.X, ImageDefPos.Y + RTTemp.Y);
}

void UCrosshairWidget::StopControllerCalib()
{
	GamepadMotionHelpers::CalibrationMode Sen = GamepadMotionHelpers::CalibrationMode::SensorFusion;

	GamepadMotionHelpers::CalibrationMode Sti = GamepadMotionHelpers::CalibrationMode::Stillness;

	MainControllerGM.SetCalibrationMode(Sen | Sti);

	UE_LOG(LogTemp, Warning, TEXT("Calib done."));
}