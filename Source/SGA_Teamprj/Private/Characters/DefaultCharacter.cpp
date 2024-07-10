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

void ADefaultCharacter::SetCamera(class USpringArmComponent* Default_CameraBoom, class UCameraComponent* Default_ViewCamera, float Default_Length)
{
	Default_CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	Default_CameraBoom->SetupAttachment(GetRootComponent());
	Default_CameraBoom->TargetArmLength = Default_Length;
	Default_CameraBoom->bUsePawnControlRotation = true;

	Default_ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCamera"));
	Default_ViewCamera->SetupAttachment(Default_CameraBoom);
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

	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &ADefaultCharacter::MoveForward);
	PlayerInputComponent->BindAxis(FName("MoveRight"), this, &ADefaultCharacter::MoveRight);
	PlayerInputComponent->BindAxis(FName("MouseX"), this, &ADefaultCharacter::MouseX);
	PlayerInputComponent->BindAxis(FName("MouseY"), this, &ADefaultCharacter::MouseY);
	PlayerInputComponent->BindAction(FName("Jump"), IE_Pressed, this, &ADefaultCharacter::Jump);
	//PlayerInputComponent->BindAction(FName("Run"), IE_Pressed, this, &ADefaultCharacter::StartRun);
	//PlayerInputComponent->BindAction(FName("Run"), IE_Released, this, &ADefaultCharacter::StopRun);
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