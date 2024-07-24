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

	//BeHavierTree ȭ
	//APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	////PlayerPawn �÷��̾�  , ������� �Ÿ�
	//
	//IF LIneOfSight
		//MoveTo
		//SetFocus
	//Else	
		//ClearFocus
		//StopMovement
	//�ؿ� �ִ� �κ��� BTService �� ���� �̵���
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
	
