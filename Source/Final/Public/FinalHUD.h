// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CrosshairWidget.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "FinalHUD.generated.h"

/**
 * 
 */
UCLASS()
class FINAL_API AFinalHUD : public AHUD
{
	GENERATED_BODY()

private:

	virtual void BeginPlay() override;

	UCrosshairWidget* Crosshair_CPP;

public:

	UPROPERTY(EditDefaultsOnly, Category = "Crosshair Widget")
	TSubclassOf<UCrosshairWidget> Crosshair = nullptr;

	void MoveReticleX(float AxisValue);

	void MoveReticleY(float AxisValue);

	void MoveReticle(float Axis1, float Axis2);

	void SetReticle(float Axis1, float Axis2);

	FVector2D GetImageCoords();
};
