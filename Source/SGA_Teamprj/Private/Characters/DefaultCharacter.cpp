#include "Characters/DefaultCharacter.h"
#include "GameFramework/PlayerInput.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

ADefaultCharacter::ADefaultCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void ADefaultCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ADefaultCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
void ADefaultCharacter::SetCamera(USpringArmComponent* CameraBoom, UCameraComponent* ViewCamera, float Length)
{
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = Length;
	CameraBoom->bUsePawnControlRotation = true;

	ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCamera"));
	ViewCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	ViewCamera->bUsePawnControlRotation = false;
}

void ADefaultCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	FInputAxisKeyMapping KeyW = FInputAxisKeyMapping(FName("MoveForward"), EKeys::W, 1.f);
	FInputAxisKeyMapping KeyS = FInputAxisKeyMapping(FName("MoveForward"), EKeys::S, -1.f);
	FInputAxisKeyMapping KeyD = FInputAxisKeyMapping(FName("MoveRight"), EKeys::D, 1.f);
	FInputAxisKeyMapping KeyA = FInputAxisKeyMapping(FName("MoveRight"), EKeys::A, -1.f);
	FInputAxisKeyMapping KeyMouseX = FInputAxisKeyMapping(FName("MouseX"), EKeys::MouseX, 1.f);
	FInputAxisKeyMapping KeyMouseY = FInputAxisKeyMapping(FName("MouseY"), EKeys::MouseY, -1.f);
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

void ADefaultCharacter::MouseX(float Value)
{
	AddControllerYawInput(Value);
}

void ADefaultCharacter::MouseY(float Value)
{
	AddControllerPitchInput(Value);
}