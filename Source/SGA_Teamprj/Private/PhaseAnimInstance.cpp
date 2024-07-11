// Fill out your copyright notice in the Description page of Project Settings.

#include "KismetAnimationLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "PhaseAnimInstance.h"

void UPhaseAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	APawn* Pawn = TryGetPawnOwner();
	if (!::IsValid(Pawn)) return;

	Speed = Pawn->GetVelocity().Size();
	Direction = CalculateDirection(Pawn->GetVelocity(), Pawn->GetActorRotation());

	ActorRotation = Pawn->GetActorRotation();
	ControlRotation = Pawn->GetControlRotation();
	
	tempRotation = UKismetMathLibrary::NormalizedDeltaRotator(ActorRotation, ControlRotation);

	Yaw = FMath::RInterpTo(, tempRotation, DeltaSeconds, 1.0f);
	//UKismetAnimationLibrary::CalculateDirection(ActorRotation, ControlRotation);
}
