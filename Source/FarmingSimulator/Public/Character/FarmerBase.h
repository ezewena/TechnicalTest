// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AActors/FarmCell.h"
#include "GameFramework/Character.h"
#include "FarmerBase.generated.h"
UENUM(BlueprintType)
enum class EActionsToDo : uint8
{
	Plowing,
	Harvesting,
	Watering,
	Sowing,
	Nothing,
};
UCLASS()
class FARMINGSIMULATOR_API AFarmerBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFarmerBase();
	UFUNCTION()
	void MoveToLocation(FVector Location);
	UPROPERTY(Replicated,BlueprintReadWrite)
	EActionsToDo ActionsToDo;
	UPROPERTY(Replicated,Blueprintable)
	bool bIsBusy;
	UFUNCTION(Server, Reliable)
	void ServerInteractWithFarm();
	UPROPERTY(Replicated,BlueprintReadWrite,Category="Farmer")
	FVector LocationToMove;
	UPROPERTY(BlueprintReadWrite, Replicated)
	AFarmCell * FarmCell = nullptr;
	UFUNCTION(Server, Reliable,BlueprintCallable)
	void ServerMoveToLocation(FVector Direction);
	UFUNCTION(NetMulticast, Reliable,BlueprintCallable)
	void MulticastMoveToLocation(FVector Direction);
	UFUNCTION(Server, Reliable,BlueprintCallable)
	void ServerPlayMontage(UAnimMontage*Montage);
	UFUNCTION(NetMulticast, Reliable,BlueprintCallable)
	void MulticastPlayMontage(UAnimMontage*Montage);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
