// Fill out your copyright notice in the Description page of Project Settings.


#include "CrosshairWidget.h"


void UCrosshairWidget::NativeConstruct()
{
	UE_LOG(LogTemp, Warning, TEXT("Widget Created."));
}

void UCrosshairWidget::DebugTest()
{
	if (CrosshairText == nullptr) return;

	CrosshairText->SetText(FText::AsNumber(456));
}

