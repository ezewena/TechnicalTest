// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FarmDataWidget.generated.h"

/**
 * 
 */
class UTextBlock;
UCLASS()
class FARMINGSIMULATOR_API UFarmDataWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "FarmUI")
	void UpdateFarmData(int32 WaterLevel, bool bIsPlowed, float TimeToHarvest);

protected:
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* WaterText;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* PlowedText;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* TimeText;
};
