// Fill out your copyright notice in the Description page of Project Settings.


#include "RevenantAIController.h"
#include "Kismet/GameplayStatics.h"

void ARevenantAIController::BeginPlay()
{
	Super::BeginPlay();

	if (AIBehavior != nullptr)
	{
		RunBehaviorTree(AIBehavior);
	}
}

void ARevenantAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	//BeHavierTree ȭ
	//APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	////PlayerPawn �÷��̾�  , ������� �Ÿ�
	//
	//FVector d = FVector(2300.0, -1880.0, 88.0);
	////IF LIneOfSight
	//	//MoveTo
	//	//SetFocus
	////Else	
	//	//ClearFocus
	//	//StopMovement
	//if (LineOfSightTo(PlayerPawn))
	//{
	//	SetFocus(PlayerPawn);
	//	MoveToActor(PlayerPawn, AcceptanceRadius);
	//}
	//else
	//{
	//	ClearFocus(EAIFocusPriority::Gameplay);
	//	MoveToLocation(d);
	//	//StopMovement();
	//}
}
	
