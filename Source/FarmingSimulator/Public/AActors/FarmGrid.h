// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FarmCell.h"
#include "GameFramework/Actor.h"
#include "FarmGrid.generated.h"

UCLASS()
class FARMINGSIMULATOR_API AFarmGrid : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFarmGrid();

protected:
	UPROPERTY(EditAnywhere, Category = "FarmGrid")
	int32 Rows;
	UPROPERTY(EditAnywhere, Category = "FarmGrid")
	int32 Columns;
	UPROPERTY(EditAnywhere, Category = "FarmGrid")
	float CellSize;
	UPROPERTY(EditAnywhere, Category = "FarmGrid")
	TSubclassOf<AFarmCell> FarmGridClass;
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, Category = "FarmGrid")
	TArray<AFarmCell*>FarmCells;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
