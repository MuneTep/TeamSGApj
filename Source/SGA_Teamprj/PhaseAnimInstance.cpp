// Fill out your copyright notice in the Description page of Project Settings.

#include "PhaseAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"

void UPhaseAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	
	Phase = Cast<APhaseCharacter>(TryGetPawnOwner());
}

void UPhaseAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	if (Phase == nullptr) return;

	

	FVector Velocity = Phase->GetVelocity();
	Velocity.Z = 0.f;
	Speed = Velocity.Size();


	
	bIsInAir = Phase->GetCharacterMovement() ->IsFalling();

	bIsInputAccelerating = Phase->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f ? true : false;
}
