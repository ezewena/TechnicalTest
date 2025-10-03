// Fill out your copyright notice in the Description page of Project Settings.


#include "AActors/FarmGrid.h"

// Sets default values
AFarmGrid::AFarmGrid()
{
	PrimaryActorTick.bCanEverTick = false;
	Rows = 5;
	Columns = 5;
	CellSize = 200.f;
}

// Called when the game starts or when spawned
void AFarmGrid::BeginPlay()
{
	Super::BeginPlay();
	if (FarmGridClass)
	{
		for (int32 i = 0; i < Rows; i++)
		{
			for (int32 j = 0; j < Columns; j++)
			{
				FVector Location = GetActorLocation() + FVector(i*CellSize, j*CellSize, 0.0f);
				AFarmCell* NewCell = GetWorld()->SpawnActor<AFarmCell>(FarmGridClass, Location, FRotator::ZeroRotator);
				if (NewCell)
				{
					FarmCells.Add(NewCell);
				}
			}
		}
			
	}
}

// Called every frame
void AFarmGrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

