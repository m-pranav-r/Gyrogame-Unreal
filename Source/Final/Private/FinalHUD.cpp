// Fill out your copyright notice in the Description page of Project Settings.


#include "FinalHUD.h"

void AFinalHUD::BeginPlay()
{
	Super::BeginPlay();

	if (Crosshair == nullptr) return;

	Crosshair_CPP = Cast<UCrosshairWidget>(Crosshair);

	Crosshair_CPP = CreateWidget<UCrosshairWidget>(UGameplayStatics::GetPlayerController(GetWorld(), 0), Crosshair);

	if (Crosshair_CPP == nullptr) return;

	Crosshair_CPP->AddToViewport(0);

	UE_LOG(LogTemp, Warning, TEXT("Widget Instanced."));
}

void AFinalHUD::MoveReticleX(float AxisValue)
{
	Crosshair_CPP->MoveX(AxisValue);
}

void AFinalHUD::MoveReticleY(float AxisValue)
{
	Crosshair_CPP->MoveY(AxisValue);
}

void AFinalHUD::MoveReticle(float Axis1, float Axis2)
{
	Crosshair_CPP->Move(Axis1, Axis2);
}

FVector2D AFinalHUD::GetImageCoords()
{
	return Crosshair_CPP->GetImageCoords();
}


