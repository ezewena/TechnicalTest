// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AActors/FarmCell.h"
#include "Character/FarmerBase.h"
#include "FarmActionsToDo.generated.h"

/**
 * 
 */
UCLASS()
class FARMINGSIMULATOR_API UFarmActionsToDo : public UUserWidget
{
	GENERATED_BODY()
	public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	AFarmerBase* AFarmerBaseRef;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	AFarmCell* FarmCellClicked;
protected:
	virtual void NativeConstruct() override;
	
};
