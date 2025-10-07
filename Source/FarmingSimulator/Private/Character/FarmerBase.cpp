// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/FarmerBase.h"

#include "AIController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Navigation/PathFollowingComponent.h"
#include "Net/UnrealNetwork.h"

// Sets default values
AFarmerBase::AFarmerBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
	ActionsToDo = EActionsToDo::Nothing;
	
}

void AFarmerBase::MoveToLocation(FVector Location)
{
	UAIBlueprintHelperLibrary::SimpleMoveToLocation(GetController(), Location);

}

void AFarmerBase::ServerMoveToLocation_Implementation(FVector Location)
{
	MoveToLocation(Location);
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

void AFarmerBase::MulticastMoveToLocation_Implementation(FVector Direction)
{
	
}

void AFarmerBase::ServerPlayMontage_Implementation(UAnimMontage* Montage)
{
	if (HasAuthority())
	{
		PlayAnimMontage(Montage);
		return;
	}
	MulticastPlayMontage(Montage);
}

void AFarmerBase::MulticastPlayMontage_Implementation(UAnimMontage* Montage)
{
	PlayAnimMontage(Montage);
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
	DOREPLIFETIME(AFarmerBase,ActionsToDo);
	DOREPLIFETIME(AFarmerBase,LocationToMove);
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

