// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/PlayerPawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
	bReplicates = true;
	USceneComponent* Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;
	PrimaryActorTick.bCanEverTick = false;
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 1200.f;
	SpringArm->bDoCollisionTest = false;
	SpringArm->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	MoveSpeed = 1000.f;
	ZoomStep = 200.f;
	MinZoom = 600.f;
	MaxZoom = 2000.f;
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerPawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerPawn::MoveRight);
	PlayerInputComponent->BindAction("ZoomIn", IE_Pressed, this, &APlayerPawn::ZoomIn);
	PlayerInputComponent->BindAction("ZoomOut", IE_Pressed, this, &APlayerPawn::ZoomOut);

}

void APlayerPawn::MoveForward(float Value)
{
	if (Value != 0.f)
	{
		AddActorWorldOffset(FVector(Value * MoveSpeed * GetWorld()->GetDeltaSeconds(), 0.f, 0.f));
	}
}

void APlayerPawn::MoveRight(float Value)
{
	if (Value != 0.f)
	{
		AddActorWorldOffset(FVector(0.f, Value * MoveSpeed * GetWorld()->GetDeltaSeconds(), 0.f));
	}
}

void APlayerPawn::ZoomIn()
{
	SpringArm->TargetArmLength = FMath::Clamp(SpringArm->TargetArmLength - ZoomStep, MinZoom, MaxZoom);

}

void APlayerPawn::ZoomOut()
{
	SpringArm->TargetArmLength = FMath::Clamp(SpringArm->TargetArmLength + ZoomStep, MinZoom, MaxZoom);

}

