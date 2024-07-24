// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/RevenantAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

void ARevenantAIController::BeginPlay()
{
	Super::BeginPlay();

	if (AIBehavior != nullptr)
	{
		RunBehaviorTree(AIBehavior);

		APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
	}
}

void ARevenantAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	//BeHavierTree 화
	//APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	////PlayerPawn 플레이어  , 따라오는 거리
	//
	//IF LIneOfSight
		//MoveTo
		//SetFocus
	//Else	
		//ClearFocus
		//StopMovement
	//밑에 있는 부분을 BTService 로 구현 이동함
	//if (LineOfSightTo(PlayerPawn))
	//{
	//	GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
	//	GetBlackboardComponent()->SetValueAsVector(TEXT("LastKnownPlayerLocation"), PlayerPawn->GetActorLocation());

	//}
	//else
	//{
	//	GetBlackboardComponent()->ClearValue(TEXT("PlayerLocation"));
	//}
}
	
