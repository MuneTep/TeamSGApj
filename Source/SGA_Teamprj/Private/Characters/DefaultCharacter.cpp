#include "Characters/DefaultCharacter.h"
#include "GameFramework/PlayerInput.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"

ADefaultCharacter::ADefaultCharacter() : BaseSpeed(600.f), SprintMult(1.8f)
{
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate.Yaw = 720.f;
}

void ADefaultCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ADefaultCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADefaultCharacter::SetCamera()
{
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 300.f;
	CameraBoom->bUsePawnControlRotation = true;

	ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCamera"));
	ViewCamera->SetupAttachment(CameraBoom);
}

void ADefaultCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	FInputAxisKeyMapping KeyW = FInputAxisKeyMapping(FName("MoveForward"), EKeys::W, 1.f);
	FInputAxisKeyMapping KeyS = FInputAxisKeyMapping(FName("MoveForward"), EKeys::S, -1.f);
	FInputAxisKeyMapping KeyD = FInputAxisKeyMapping(FName("MoveRight"), EKeys::D, 1.f);
	FInputAxisKeyMapping KeyA = FInputAxisKeyMapping(FName("MoveRight"), EKeys::A, -1.f);
	FInputAxisKeyMapping KeyMouseX = FInputAxisKeyMapping(FName("CameraX"), EKeys::MouseX, 1.f);
	FInputAxisKeyMapping KeyMouseY = FInputAxisKeyMapping(FName("CameraY"), EKeys::MouseY, -1.f);
	FInputActionKeyMapping KeySpacebar(FName("Jump"), EKeys::SpaceBar);
	FInputActionKeyMapping KeyShift(FName("Run"), EKeys::LeftShift);

	UPlayerInput::AddEngineDefinedAxisMapping(KeyW);
	UPlayerInput::AddEngineDefinedAxisMapping(KeyS);
	UPlayerInput::AddEngineDefinedAxisMapping(KeyD);
	UPlayerInput::AddEngineDefinedAxisMapping(KeyA);
	UPlayerInput::AddEngineDefinedAxisMapping(KeyMouseX);
	UPlayerInput::AddEngineDefinedAxisMapping(KeyMouseY);
	UPlayerInput::AddEngineDefinedActionMapping(KeySpacebar);
	UPlayerInput::AddEngineDefinedActionMapping(KeyShift);

	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &ADefaultCharacter::MoveForward);
	PlayerInputComponent->BindAxis(FName("MoveRight"), this, &ADefaultCharacter::MoveRight);
	PlayerInputComponent->BindAxis(FName("CameraX"), this, &ADefaultCharacter::CameraX);
	PlayerInputComponent->BindAxis(FName("CameraY"), this, &ADefaultCharacter::CameraY);
	PlayerInputComponent->BindAction(FName("Jump"), IE_Pressed, this, &ADefaultCharacter::Jump);
	PlayerInputComponent->BindAction(FName("Run"), IE_Pressed, this, &ADefaultCharacter::SprintStart);
	PlayerInputComponent->BindAction(FName("Run"), IE_Released, this, &ADefaultCharacter::SprintEnd);
}

void ADefaultCharacter::MoveForward(float Value)
{
	if (Controller && (Value != 0.f))
	{
		const FRotator ControlRotation = GetControlRotation();
		const FRotator YawRotation(0.f, ControlRotation.Yaw, 0.f);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ADefaultCharacter::MoveRight(float Value)
{
	if (Controller && (Value != 0.f))
	{
		const FRotator ControlRotation = GetControlRotation();
		const FRotator YawRotation(0.f, ControlRotation.Yaw, 0.f);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}

void ADefaultCharacter::CameraX(float Value)
{
	AddControllerYawInput(Value);
}

void ADefaultCharacter::CameraY(float Value)
{
	AddControllerPitchInput(Value);
}

void ADefaultCharacter::SprintStart()
{
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, TEXT("Called: SprintStart()"));
	GetCharacterMovement()->MaxWalkSpeed = BaseSpeed * SprintMult;
}

void ADefaultCharacter::SprintEnd()
{
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Black, TEXT("Called: SprintEnd()"));
	GetCharacterMovement()->MaxWalkSpeed = BaseSpeed;
}

void ADefaultCharacter::Attack1()
{
}
