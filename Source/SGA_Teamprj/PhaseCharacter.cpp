// Fill out your copyright notice in the Description page of Project Settings.

#include "EnhancedInputComponent.h"

#include "PhaseCharacter.h"

// Sets default values
APhaseCharacter::APhaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	// SpringArm
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 500.0f;
	SpringArm->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
	//SpringArm->SetWorldRotation(FRotator(0.0f, 0.0f, -90.0f));
	SpringArm->bDoCollisionTest = false;
	//SpringArm->bUsePawnControlRotation = false;
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritYaw = false;
	SpringArm->bInheritRoll = false;

	// Camera Component
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
}

// Called when the game starts or when spawned
void APhaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APhaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APhaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &APhaseCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Turn", this, &APhaseCharacter::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &APhaseCharacter::LookUp);
}

void APhaseCharacter::MoveForward(float Value)
{
	if (Controller != nullptr && Value != 0.0f)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}

	//FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Z);
	//AddMovementInput(Direction, Value);
	
	//AddMovementInput(FVector(Value), 2.0f);

	/*FVector MovementVector = Value.Get<FVector>();

	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(Direction, MovementVector.X);*/

}

void APhaseCharacter::Turn(float AxisValue)
{
	//SpringArm->AddLocalRotation();
	AddControllerYawInput(AxisValue);
}

void APhaseCharacter::LookUp(float AxisValue)
{
	AddControllerPitchInput(AxisValue);
}

void APhaseCharacter::JumpStart()
{
	bPressedJump = true;
	Jump();
}

void APhaseCharacter::JumpStop()
{
	bPressedJump = false;
	StopJumping();
}



