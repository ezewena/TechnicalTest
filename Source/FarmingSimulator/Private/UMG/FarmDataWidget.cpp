// Fill out your copyright notice in the Description page of Project Settings.


#include "UMG/FarmDataWidget.h"

#include "Components/TextBlock.h"

void UFarmDataWidget::UpdateFarmData(int32 WaterLevel, bool bIsPlowed, float TimeToHarvest)
{
	if (WaterText)
	{
		WaterText->SetText(FText::AsNumber(WaterLevel));
	}
	if (PlowedText)
	{
		PlowedText->SetText(bIsPlowed ? FText::FromString(TEXT("Yes")) : FText::FromString(TEXT("No")));
	}
	if (TimeText)
	{
		int32 Seconds = FMath::Max(0, FMath::RoundToInt(TimeToHarvest));
		int32 Minutes = Seconds / 60;
		int32 RemSec = Seconds % 60;
		FString TimeStr = FString::Printf(TEXT("%d:%02d"), Minutes, RemSec);
		TimeText->SetText(FText::FromString(TimeStr));
	}
}

void UFarmDataWidget::NativeConstruct()
{
	Super::NativeConstruct();
}
