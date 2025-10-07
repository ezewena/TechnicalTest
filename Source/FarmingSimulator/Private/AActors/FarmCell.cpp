// Fill out your copyright notice in the Description page of Project Settings.


#include "AActors/FarmCell.h"

#include "Blueprint/UserWidget.h"
#include "GameFramework/GameStateBase.h"
#include "PlayerState/PlayerStateBase.h"

AFarmCell::AFarmCell()
{
	//Set Default Variables
	PrimaryActorTick.bCanEverTick = false;
	CellMesh = CreateDefaultSubobject<UStaticMeshComponent>("FarmCellMesh");
	RootComponent = CellMesh;
	bPlow=false;
	WaterLevel=0;
	FarmCellState = EFarmCellState::Empty;
	TimeToHarvest=0.0f;
}


void AFarmCell::BeginPlay()
{
	Super::BeginPlay();
}

void AFarmCell::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFarmCell, WaterLevel);
	DOREPLIFETIME(AFarmCell, FarmCellState);
	DOREPLIFETIME(AFarmCell, TimeToHarvest);
	DOREPLIFETIME(AFarmCell, bPlow);
}

void AFarmCell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFarmCell::ServerHarvest_Implementation(APlayerStateBase*PlayerStateBase)
{
	if (PlayerStateBase)
	{
		if (FarmCellState==EFarmCellState::ReadyToHarvest)
		{
			FarmCellState=EFarmCellState::Empty;
			bPlow=false;
			WaterLevel=0;
			TimeToHarvest=0;
			PlayerStateBase->Server_AddPlants(1);
			
		}
	}
	
}

void AFarmCell::ServerSow_Implementation(APlayerStateBase*PlayerStateBase)
{
	if (PlayerStateBase)
	{
		if (bPlow && PlayerStateBase->GetSeeds()>0&& FarmCellState==EFarmCellState::Empty )
		{
			FarmCellState = EFarmCellState::Growing;
			PlayerStateBase->Server_AddSeeds(-1);
			TimeToHarvest=10;
		}
	}

}

void AFarmCell::ServerPlow_Implementation(APlayerStateBase*PlayerStateBase)
{
	if (!bPlow&&PlayerStateBase)
	{
		bPlow=true;
	}

}

void AFarmCell::ServerWateringPlants_Implementation(APlayerStateBase*PlayerStateBase)
{
	if (PlayerStateBase)
	{
		if (PlayerStateBase->GetWater()>0)
		{
			WaterLevel++;
			PlayerStateBase->Server_AddWater(-1);
		}
	}
}

