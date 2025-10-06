// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "PlayerStateBase.generated.h"

/**
 * 
 */
UCLASS()
class FARMINGSIMULATOR_API APlayerStateBase : public APlayerState
{
	GENERATED_BODY()
	public:
	APlayerStateBase();
	protected:
	UPROPERTY(Replicated, BlueprintReadOnly)
	int32 Water;
	UPROPERTY(Replicated, BlueprintReadOnly)
	int32 Seeds;
	UPROPERTY(Replicated, BlueprintReadOnly)
	int32 Plants;
	public:
	UFUNCTION(Server, Reliable)
	void Server_AddWater(int32 Amount);
	UFUNCTION(Server, Reliable)
	void Server_AddSeeds(int32 Amount);
	UFUNCTION(Server, Reliable)
	void Server_AddPlants(int32 Amount);
	
	UFUNCTION(BlueprintCallable)
	int32 GetWater() const { return Water; }
	UFUNCTION(BlueprintCallable)
	int32 GetSeeds() const { return Seeds; }
	UFUNCTION(BlueprintCallable)
	int32 GetHarvestedPlants() const { return Plants; }

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
