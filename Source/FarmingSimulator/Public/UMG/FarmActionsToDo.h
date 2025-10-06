// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AActors/FarmCell.h"
#include "Blueprint/UserWidget.h"
#include "FarmActionsToDo.generated.h"

/**
 * 
 */
class UTextBlock;
UCLASS()
class FARMINGSIMULATOR_API UFarmActionsToDo : public UUserWidget
{
	GENERATED_BODY()
	public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	AFarmCell* FarmCellRef;
protected:
	virtual void NativeConstruct() override;
	
};
