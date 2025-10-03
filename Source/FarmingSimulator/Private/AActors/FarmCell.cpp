// Fill out your copyright notice in the Description page of Project Settings.


#include "AActors/FarmCell.h"

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

void AFarmCell::OnRep_UpdateFarm()
{
	
}

void AFarmCell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFarmCell::ServerHarvest_Implementation()
{
	bPlow=true;
}

void AFarmCell::ServerSow_Implementation()
{
	if (bPlow && FarmCellState==EFarmCellState::Empty )
	{
		FarmCellState = EFarmCellState::Growing;
		TimeToHarvest=10;
	}
}

void AFarmCell::ServerPlow_Implementation()
{
	if (FarmCellState==EFarmCellState::ReadyToHarvest)
	{
		FarmCellState=EFarmCellState::Empty;
		bPlow=false;
		WaterLevel=0;
		TimeToHarvest=0;
	}
}

void AFarmCell::ServerWateringPlants_Implementation()
{
	WaterLevel++;
}

