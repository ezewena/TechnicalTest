// Fill out your copyright notice in the Description page of Project Settings.


#include "AActors/InteractiveActor.h"

// Sets default values
AInteractiveActor::AInteractiveActor()
{
	PrimaryActorTick.bCanEverTick = false;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;
	SetActorEnableCollision(true);
	Mesh->SetGenerateOverlapEvents(true);
	Mesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	Mesh->SetNotifyRigidBodyCollision(true);

}

// Called when the game starts or when spawned
void AInteractiveActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInteractiveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

