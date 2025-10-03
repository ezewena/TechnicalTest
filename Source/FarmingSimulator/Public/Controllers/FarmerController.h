// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AActors/InteractiveActor.h"
#include "GameFramework/PlayerController.h"
#include "UMG/FarmDataWidget.h"
#include "FarmerController.generated.h"

/**
 * 
 */
class AFarmerBase;
UCLASS()
class FARMINGSIMULATOR_API AFarmerController : public APlayerController
{
	GENERATED_BODY()
public:
	AFarmerController();
	
	UFUNCTION(BlueprintCallable, Category="Farm")
	void ShowFarmInfoWidget(int32 WaterLevel, bool bIsPlowed, float TimeToHarvest);
	UFUNCTION(BlueprintCallable, Category="Farm")
	void HideFarmInfoWidget();
	UFUNCTION(Server, Reliable)
	void ServerMoveTo(FVector Location);
	protected:
	virtual void SetupInputComponent() override;
	virtual void BeginPlay() override;
	UPROPERTY(EditDefaultsOnly, Category="UI")
	TSubclassOf<UFarmDataWidget> FarmInfoWidgetClass;
	
	UPROPERTY()
	UFarmDataWidget* FarmInfoWidgetInstance;
	
	void OnLeftClick();
	void OnRightClick();

	AInteractiveActor*GetInteractiveActor()const;

	UPROPERTY(EditAnywhere,BlueprintReadWrite ,Category="Farmer")
	AFarmerBase* FarmerBase;
	
};
