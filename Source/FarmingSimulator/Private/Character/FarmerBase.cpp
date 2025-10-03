// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/FarmerBase.h"

#include "AIController.h"
#include "Net/UnrealNetwork.h"

// Sets default values
AFarmerBase::AFarmerBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AFarmerBase::ServerInteractWithFarm_Implementation()
{
	if (!bIsBusy)
	{
		if (FarmCell)
		{
			
		}
	}
}

// Called when the game starts or when spawned
void AFarmerBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFarmerBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFarmerBase,bIsBusy);
}
// Called every frame
void AFarmerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFarmerBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

