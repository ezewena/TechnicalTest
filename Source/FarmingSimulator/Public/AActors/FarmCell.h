// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractiveActor.h"
#include "GameFramework/Actor.h"
#include "Net/UnrealNetwork.h" 
#include "FarmCell.generated.h"

UENUM(BlueprintType)
enum class EFarmCellState : uint8
{
	Empty,
	Growing,
	ReadyToHarvest
};

UCLASS()
class FARMINGSIMULATOR_API AFarmCell : public AInteractiveActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFarmCell();

protected:
	//Variables
	UPROPERTY(ReplicatedUsing=OnRep_UpdateFarm,BlueprintReadWrite,EditAnywhere)
	bool bPlow;
	UPROPERTY(ReplicatedUsing=OnRep_UpdateFarm,BlueprintReadWrite,EditAnywhere)
	int WaterLevel;
	UPROPERTY(ReplicatedUsing=OnRep_UpdateFarm,BlueprintReadWrite,EditAnywhere)
	float TimeToHarvest;
	UPROPERTY(ReplicatedUsing=OnRep_UpdateFarm,BlueprintReadWrite,EditAnywhere)
	EFarmCellState FarmCellState;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "FarmGrid")
	UStaticMeshComponent* CellMesh;
	
	virtual void BeginPlay() override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	UFUNCTION()
	void OnRep_UpdateFarm();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(Reliable,Server)
	void ServerWateringPlants();
	UFUNCTION(Reliable,Server)
	void ServerPlow();
	UFUNCTION(Reliable,Server)
	void ServerSow();
	UFUNCTION(Reliable,Server)
	void ServerHarvest();
	bool IsPlow() const { return bPlow; }
	int32 GetWaterLevel() const { return WaterLevel; }
	EFarmCellState GetPlantState() const { return FarmCellState; }
	float GetTimeToHarvest() const { return TimeToHarvest; }
};
