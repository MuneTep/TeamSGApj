// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class SGA_TEAMPRJ_API UMyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

	UMyAnimInstance();

public:
	void PlayAttackMontage();
	void PlaySkillMonteage_01();
	void PlaySkillMonteage_02_Start();
	void PlaySkillMonteage_02_Stop();

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	UAnimMontage* AttackMontage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	UAnimMontage* SKillMontage_01;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	UAnimMontage* SKillMontage_02_Start;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	UAnimMontage* SKillMontage_02_Stop;

};
