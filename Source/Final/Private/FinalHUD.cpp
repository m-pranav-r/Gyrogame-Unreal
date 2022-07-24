// Fill out your copyright notice in the Description page of Project Settings.


#include "FinalHUD.h"

void AFinalHUD::BeginPlay()
{
	Super::BeginPlay();

	if (Crosshair == nullptr) return;

	UCrosshairWidget* Temp = Cast<UCrosshairWidget>(Crosshair);

	Temp = CreateWidget<UCrosshairWidget>(UGameplayStatics::GetPlayerController(GetWorld(), 0), Crosshair);

	if (Temp == nullptr) return;

	Temp->AddToViewport(0);

	Temp->UCrosshairWidget::DebugTest();

	UE_LOG(LogTemp, Warning, TEXT("Widget Instanced."));
}


