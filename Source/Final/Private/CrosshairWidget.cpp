// Fill out your copyright notice in the Description page of Project Settings.


#include "CrosshairWidget.h"


void UCrosshairWidget::NativeConstruct()
{
	UE_LOG(LogTemp, Warning, TEXT("Widget Created."));

	RTTemp.X = 0.0f;

	RTTemp.Y = 0.0f;

	ImageDefPos = FVector2D(GEngine->GameViewport->Viewport->GetSizeXY());

	ImageDefPos = FVector2D(ImageDefPos.X/2, ImageDefPos.Y/2);
}

void UCrosshairWidget::MoveX(float AxisValue)
{
	RTTemp.X+= AxisValue;

	CrosshairImage->SetRenderTranslation(RTTemp);
}

void UCrosshairWidget::MoveY(float AxisValue)
{
	RTTemp.Y+= AxisValue;

	CrosshairImage->SetRenderTranslation(RTTemp);
}

FVector2D UCrosshairWidget::GetImageCoords()
{
	UE_LOG(LogTemp, Warning, TEXT("X = %f, Y = %f"),ImageDefPos.X + RTTemp.X, ImageDefPos.Y + RTTemp.Y);

	return FVector2D(ImageDefPos.X + RTTemp.X, ImageDefPos.Y + RTTemp.Y);
}

void UCrosshairWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{

}

