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
	
	UPROPERTY(Replicated, BlueprintReadOnly)
	int32 Water;

	UPROPERTY(Replicated, BlueprintReadOnly)
	int32 Seeds;

	UPROPERTY(Replicated, BlueprintReadOnly)
	int32 Harvested;
	
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
