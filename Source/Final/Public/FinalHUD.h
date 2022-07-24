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

public:

	UPROPERTY(EditDefaultsOnly, Category = "Crosshair Widget")
	TSubclassOf<UCrosshairWidget> Crosshair = nullptr;
};