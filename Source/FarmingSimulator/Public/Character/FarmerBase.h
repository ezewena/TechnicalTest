// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AActors/FarmCell.h"
#include "GameFramework/Character.h"
#include "FarmerBase.generated.h"

UCLASS()
class FARMINGSIMULATOR_API AFarmerBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFarmerBase();
	UFUNCTION(BlueprintImplementableEvent)
	void MoveToLocation(FVector Location);
	UPROPERTY(Replicated)
	bool bIsBusy;
	UFUNCTION(Server, Reliable)
	void ServerInteractWithFarm();
	AFarmCell * FarmCell;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
