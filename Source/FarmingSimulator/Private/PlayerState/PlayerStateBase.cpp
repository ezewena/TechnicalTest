// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerState/PlayerStateBase.h"

#include "Net/UnrealNetwork.h"

APlayerStateBase::APlayerStateBase()
{
}

void APlayerStateBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(APlayerStateBase, Harvested);
	DOREPLIFETIME(APlayerStateBase, Water);
	DOREPLIFETIME(APlayerStateBase, Seeds);
}
