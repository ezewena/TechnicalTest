// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/FarmerController.h"
#include "AActors/FarmCell.h"
#include "Character/FarmerBase.h"
#include "Kismet/GameplayStatics.h"

AFarmerController::AFarmerController()
{
	FarmerBase = Cast<AFarmerBase>(UGameplayStatics::GetActorOfClass(GetWorld(), AFarmerBase::StaticClass()));
}

void AFarmerController::ShowFarmInfoWidget(int32 WaterLevel, bool bIsPlowed, float TimeToHarvest)
{
	if (!FarmInfoWidgetInstance && FarmInfoWidgetClass)
	{
		FarmInfoWidgetInstance = CreateWidget<UFarmDataWidget>(this, FarmInfoWidgetClass);
		if (FarmInfoWidgetInstance)
			FarmInfoWidgetInstance->AddToViewport();
	}

	if (FarmInfoWidgetInstance)
	{
		FarmInfoWidgetInstance->SetVisibility(ESlateVisibility::Visible);
		FarmInfoWidgetInstance->UpdateFarmData(WaterLevel, bIsPlowed, TimeToHarvest); 
	}
}

void AFarmerController::ShowFarmActionWidget(AFarmerBase* Farmer, AFarmCell* FarmCell)
{
	if (!FarmActionsWidgetInstance && FarmActionsWidgetClass)
	{
		FarmActionsWidgetInstance = CreateWidget<UFarmActionsToDo>(this, FarmActionsWidgetClass);
		if (FarmActionsWidgetInstance)
			FarmActionsWidgetInstance->AddToViewport();
	}

	if (FarmActionsWidgetInstance)
	{
		FarmActionsWidgetInstance->AddToViewport();
		FarmActionsWidgetInstance->SetVisibility(ESlateVisibility::Visible);
		FarmActionsWidgetInstance->AFarmerBaseRef = Farmer;
		FarmActionsWidgetInstance->FarmCellClicked = FarmCell;
	}
}


void AFarmerController::HideFarmInfoWidget()
{
	if (FarmInfoWidgetInstance)
	{
		FarmInfoWidgetInstance->SetVisibility(ESlateVisibility::Hidden);
	}
}

void AFarmerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction("LeftClick", IE_Pressed, this, &AFarmerController::OnLeftClick);
	InputComponent->BindAction("RightClick", IE_Pressed, this, &AFarmerController::OnRightClick);
}

void AFarmerController::BeginPlay()
{
	Super::BeginPlay();
	FarmerBase = Cast<AFarmerBase>(UGameplayStatics::GetActorOfClass(GetWorld(), AFarmerBase::StaticClass()));
	if (FarmInfoWidgetClass)
	{
		FarmInfoWidgetInstance = CreateWidget<UFarmDataWidget>(this, FarmInfoWidgetClass);
		if (FarmInfoWidgetInstance)
		{
			FarmInfoWidgetInstance->AddToViewport();
			FarmInfoWidgetInstance->SetVisibility(ESlateVisibility::Hidden);
		}
	}
}

void AFarmerController::OnLeftClick()
{
	AInteractiveActor*ActorHit=GetInteractiveActor();
	if (ActorHit)
	{
		auto FarmCell = Cast<AFarmCell>(ActorHit);
		if (FarmCell)
		{
		//	GEngine->AddOnScreenDebugMessage(-1,5.0f,FColor::Red,"FarmCell");
			ShowFarmInfoWidget(FarmCell->GetWaterLevel(), FarmCell->IsPlow(), FarmCell->GetTimeToHarvest());
			if (FarmerBase)
			{
				FarmerBase->FarmCell = FarmCell;
				
			}
		}
		
	}
}

void AFarmerController::OnRightClick()
{
	AInteractiveActor*ActorHit=GetInteractiveActor();
	if (ActorHit)
	{
		auto FarmCell = Cast<AFarmCell>(ActorHit);
		if (FarmCell)
		{
			ShowFarmActionWidget(FarmerBase,FarmCell);
			FarmerBase->FarmCell = FarmCell;
			return;
		}
	}
	FarmerBase->ServerMoveToLocation(Location);
}

AInteractiveActor* AFarmerController::GetInteractiveActor() 
{
	FHitResult HitResult;
	GetHitResultUnderCursorByChannel(
		ETraceTypeQuery::TraceTypeQuery1,
		false,
		HitResult
	);
	Location=HitResult.ImpactPoint;
	if (HitResult.bBlockingHit)
	{
		// Debug para ver el raycast
		DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 25.f, 12, FColor::Green, false, 2.0f);
		
		return Cast<AFarmCell>(HitResult.GetActor());
	}

	return nullptr;
}
