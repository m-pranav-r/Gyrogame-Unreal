// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/TextBlock.h"
#include "SDL/SDL.h"
#include "GamepadMotionHelpers/GamepadMotion.hpp"
#include "Kismet/GameplayStatics.h"
#include "FinalPlayerController.h"
#include "CrosshairWidget.generated.h"

/**
 * 
 */
UCLASS()
class FINAL_API UCrosshairWidget : public UUserWidget
{
	GENERATED_BODY()

private:

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	UCanvasPanel* CrosshairCanvas;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	UImage* CrosshairImage;

	virtual void NativeConstruct();

	void StopControllerCalib();

	FVector2D RTTemp;

	FVector2D ImageDefPos;

	float TempShear = 0.0f;

	float TempScale;

	SDL_GameController* MainController = nullptr;

	GamepadMotion MainControllerGM;
	
	float Gyro[3], Accel[3], Corrected[3], GyroPitchScale, GyroRollScale;

	FTimerHandle CalibHandle;

public:

	void Move(float Axis1, float Axis2, float Axis3);

	void Set(float Axis1, float Axis2);
	
	FVector2D GetImageCoords();

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
};
