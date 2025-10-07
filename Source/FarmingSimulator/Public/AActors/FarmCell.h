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
	UPROPERTY(Replicated,BlueprintReadWrite,EditAnywhere)
	bool bPlow;
	UPROPERTY(Replicated,BlueprintReadWrite,EditAnywhere)
	int WaterLevel;
	UPROPERTY(Replicated,BlueprintReadWrite,EditAnywhere)
	float TimeToHarvest;
	UPROPERTY(Replicated,BlueprintReadWrite,EditAnywhere)
	EFarmCellState FarmCellState;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "FarmGrid")
	UStaticMeshComponent* CellMesh;
	virtual void BeginPlay() override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintImplementableEvent)
	void ModifyCell(const FString& Mensaje);
	UFUNCTION(Reliable,Server,BlueprintCallable)
	void ServerWateringPlants(APlayerStateBase*PlayerStateBase);
	UFUNCTION(Reliable,Server,BlueprintCallable)
	void ServerPlow(APlayerStateBase*PlayerStateBase);
	UFUNCTION(Reliable,Server,BlueprintCallable)
	void ServerSow(APlayerStateBase*PlayerStateBase);
	UFUNCTION(Reliable,Server,BlueprintCallable)
	void ServerHarvest(APlayerStateBase*PlayerStateBase);
	bool IsPlow() const { return bPlow; }
	int32 GetWaterLevel() const { return WaterLevel; }
	EFarmCellState GetPlantState() const { return FarmCellState; }
	float GetTimeToHarvest() const { return TimeToHarvest; }
};
