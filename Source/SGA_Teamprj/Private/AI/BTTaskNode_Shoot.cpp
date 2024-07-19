// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTTaskNode_Shoot.h"
#include "AIController.h"
#include "Characters/Character_Revenant.h"

UBTTaskNode_Shoot::UBTTaskNode_Shoot()
{
	NodeName = TEXT("Shoot");
}

EBTNodeResult::Type UBTTaskNode_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (OwnerComp.GetAIOwner() == nullptr)
	{
		return EBTNodeResult::Failed;
	}
	ACharacter_Revenant* Character= Cast<ACharacter_Revenant>(OwnerComp.GetAIOwner()->GetPawn());
	if (Character == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	Character->AIShoot();
	return EBTNodeResult::Succeeded;
}
