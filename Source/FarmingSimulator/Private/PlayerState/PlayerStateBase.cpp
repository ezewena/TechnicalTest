// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerState/PlayerStateBase.h"

#include "Net/UnrealNetwork.h"

APlayerStateBase::APlayerStateBase()
{
	
}

void APlayerStateBase::Server_AddSeeds_Implementation(int32 Amount)
{
	Seeds += Amount;
}

void APlayerStateBase::Server_AddWater_Implementation(int32 Amount)
{
	Water += Amount;
}

void APlayerStateBase::Server_AddPlants_Implementation(int32 Amount)
{
	Plants += Amount;
}

void APlayerStateBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(APlayerStateBase, Plants);
	DOREPLIFETIME(APlayerStateBase, Water);
	DOREPLIFETIME(APlayerStateBase, Seeds);
}
