// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/TextBlock.h"
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

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	UTextBlock* CrosshairText;

	virtual void NativeConstruct();

	FVector2D RTTemp;

	FVector2D ImageDefPos;

public:

	void MoveX(float AxisValue);

	void MoveY(float AxisValue);
	
	FVector2D GetImageCoords();
};
