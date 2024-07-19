// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"

#include "PhaseAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class SGA_TEAMPRJ_API UPhaseAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float Speed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float Direction;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float Yaw;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float Pitch;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bIsAttack;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bIsJump;

	FRotator ActorRotation, ControlRotation, tempRotation;

};
