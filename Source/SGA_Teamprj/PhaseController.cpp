// Fill out your copyright notice in the Description page of Project Settings.

#include "PhaseCharacter.h"
#include "PhaseController.h"

APhaseController::APhaseController()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UInputAction> IA_MoveForward_OBJ(TEXT("/Game/Input/Input_Phase/IA_MoveForward"));
	IA_MoveForward = IA_MoveForward_OBJ.Object;

	static ConstructorHelpers::FObjectFinder<UInputAction> IA_Turn_OBJ(TEXT("/Game/Input/Input_Phase/IA_Turn"));
	IA_Turn = IA_Turn_OBJ.Object;

	static ConstructorHelpers::FObjectFinder<UInputAction> IA_LookUp_OBJ(TEXT("/Game/Input/Input_Phase/IA_LookUp"));
	IA_LookUp = IA_LookUp_OBJ.Object;

	static ConstructorHelpers::FObjectFinder<UInputAction> IA_Jump_OBJ(TEXT("/Game/Input/Input_Phase/IA_Jump"));
	IA_Jump = IA_Jump_OBJ.Object;

	static ConstructorHelpers::FObjectFinder<UInputMappingContext> IA_PhaseMovement_OBJ(TEXT("/Game/Input/Input_Phase/IMC_PhaseMovement"));
	IMC_PhaseMovement = IA_PhaseMovement_OBJ.Object;
}

void APhaseController::BeginPlay()
{
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(IMC_PhaseMovement.Get(), 1);
	}
}

void APhaseController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(IA_MoveForward.Get(), ETriggerEvent::Triggered, this, &APhaseController::MoveForward);
		EnhancedInputComponent->BindAction(IA_Turn.Get(), ETriggerEvent::Triggered, this, &APhaseController::Turn);
		EnhancedInputComponent->BindAction(IA_LookUp.Get(), ETriggerEvent::Triggered, this, &APhaseController::LookUp);
		EnhancedInputComponent->BindAction(IA_Jump.Get(), ETriggerEvent::Started, this, &APhaseController::LookUp);
		EnhancedInputComponent->BindAction(IA_Jump.Get(), ETriggerEvent::Completed, this, &APhaseController::LookUp);
	}
}

void APhaseController::MoveForward(const FInputActionValue& Value)
{
	if (APawn* ControlledPawn = GetPawn())
	{
		if (APhaseCharacter* MyPhase = Cast<APhaseCharacter>(ControlledPawn))
		{
			//MyCharacter->MoveForward(Value);

			MyPhase->MoveForward(Value.GetMagnitude());
		}
	}
}

void APhaseController::Turn(const FInputActionValue& Value)
{
	if (APawn* ControlledPawn = GetPawn())
	{
		if (APhaseCharacter* MyPhase = Cast<APhaseCharacter>(ControlledPawn))
		{
			//MyCharacter->MoveForward(Value);

			MyPhase->Turn(Value.GetMagnitude());
		}
	}
}

void APhaseController::LookUp(const FInputActionValue& Value)
{
	if (APawn* ControlledPawn = GetPawn())
	{
		if (APhaseCharacter* MyPhase = Cast<APhaseCharacter>(ControlledPawn))
		{
			//MyCharacter->MoveForward(Value);

			MyPhase->LookUp(Value.GetMagnitude());
		}
	}
}

void APhaseController::Jump(const FInputActionValue& Value)
{

	if (APawn* ControlledPawn = GetPawn())
	{
		if (APhaseCharacter* MyPhase = Cast<APhaseCharacter>(ControlledPawn))
		{
			MyPhase->JumpStart();
		}
	}
}
