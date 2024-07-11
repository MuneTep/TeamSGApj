// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"
#include "UObject/ConstructorHelpers.h"

UMyAnimInstance::UMyAnimInstance()
{
	/*static ConstructorHelpers::FObjectFinder<UAnimMontage> ATTACK_MONTAGE(TEXT("/Game/ParagonSerath/Characters/Heroes/Serath/Animations/Primary_Attack_A_Fast"));
	if (ATTACK_MONTAGE.Succeeded())
	{
		AttackMontage = ATTACK_MONTAGE.Object;
	}*/
}

void UMyAnimInstance::PlayAttackMontage()
{
	Montage_Play(AttackMontage, 1.0f);
	
}

void UMyAnimInstance::PlaySkillMonteage_01()
{
	Montage_Play(SKillMontage_01, 1.0f);
}
