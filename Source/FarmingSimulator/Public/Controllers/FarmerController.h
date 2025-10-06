// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AActors/InteractiveActor.h"
#include "GameFramework/PlayerController.h"
#include "UMG/FarmActionsToDo.h"
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
	UFUNCTION(Server, Reliable,BlueprintCallable)
	void ServerMoveToLocation(FVector Direction);
	UFUNCTION(NetMulticast, Reliable,BlueprintCallable)
	void MulticastMoveToLocation(FVector Direction);

	UFUNCTION(NetMulticast, Reliable,BlueprintCallable)
	void ServerPlayMontage(UAnimMontage*Montage);
	UFUNCTION(Server, Reliable,BlueprintCallable)
	void MulticastPlayMontage(UAnimMontage*Montage);
	UFUNCTION(BlueprintCallable, Category="Farm")
	void ShowFarmInfoWidget(int32 WaterLevel, bool bIsPlowed, float TimeToHarvest);
	void ShowFarmActionsWidget(AFarmCell*FarmCell);
	UFUNCTION(BlueprintCallable, Category="Farm")
	void HideFarmInfoWidget();
	UPROPERTY()
	FVector Location;
	protected:
	virtual void SetupInputComponent() override;
	virtual void BeginPlay() override;
	UPROPERTY(EditDefaultsOnly, Category="UI")
	TSubclassOf<UFarmDataWidget> FarmInfoWidgetClass;
	UPROPERTY(EditDefaultsOnly, Category="UI")
	TSubclassOf<UFarmActionsToDo> FarmActionsWidgetClass;
	
	UPROPERTY()
	UFarmActionsToDo* FarmActionsWidgetInstance;
	UPROPERTY()
	UFarmDataWidget* FarmInfoWidgetInstance;
	
	void OnLeftClick();
	void OnRightClick();

	AInteractiveActor*GetInteractiveActor();

	UPROPERTY(EditAnywhere,BlueprintReadWrite ,Category="Farmer")
	AFarmerBase* FarmerBase;
	
};
