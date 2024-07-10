#include "Characters/DefaultCharacter.h"
#include "GameFramework/PlayerInput.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
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

void ADefaultCharacter::KeyAxis(UInputComponent* PlayerInputComponent, ADefaultCharacter* Object, 
	FInputAxisKeyMapping& KeyMapping, FName KeyName, FKey Key, float Scale, void(ADefaultCharacter::* Func)(float))
{
	KeyMapping = FInputAxisKeyMapping(KeyName, Key, Scale);
	UPlayerInput::AddEngineDefinedAxisMapping(KeyMapping);
	PlayerInputComponent->BindAxis(KeyName, Object, Func);
}

void ADefaultCharacter::KeyAxis(UInputComponent* PlayerInputComponent, ADefaultCharacter* Object, 
	FInputAxisKeyMapping& KeyMapping1, FName KeyName1, FKey Key1, float Scale1, void(ADefaultCharacter::* Func1)(float), 
	FInputAxisKeyMapping& KeyMapping2, FName KeyName2, FKey Key2, float Scale2, void(ADefaultCharacter::* Func2)(float))
{
	KeyMapping1 = FInputAxisKeyMapping(KeyName1, Key1, Scale1);
	KeyMapping2 = FInputAxisKeyMapping(KeyName2, Key2, Scale2);
	UPlayerInput::AddEngineDefinedAxisMapping(KeyMapping1);
	UPlayerInput::AddEngineDefinedAxisMapping(KeyMapping2);
	if (KeyName1 == KeyName2 && Func1 == Func2)
	{
		PlayerInputComponent->BindAxis(KeyName1, Object, Func1);
	}
	else
	{
		PlayerInputComponent->BindAxis(KeyName1, Object, Func1);
		PlayerInputComponent->BindAxis(KeyName2, Object, Func2);
	}
}

void ADefaultCharacter::KeyAction(UInputComponent* PlayerInputComponent, ADefaultCharacter* Object, 
	FInputActionKeyMapping& KeyMapping, FName KeyName, FKey Key, EInputEvent KeyEvent, void(ADefaultCharacter::* Func)())
{
	KeyMapping = FInputActionKeyMapping(KeyName, Key);
	UPlayerInput::AddEngineDefinedActionMapping(KeyMapping);
	PlayerInputComponent->BindAction(KeyName, KeyEvent, Object, Func);
}

void ADefaultCharacter::KeyAction(UInputComponent* PlayerInputComponent, ADefaultCharacter* Object, 
	FInputActionKeyMapping& KeyMapping, FName KeyName, FKey Key, 
	EInputEvent KeyEvent1, void(ADefaultCharacter::* Func1)(), 
	EInputEvent KeyEvent2, void(ADefaultCharacter::* Func2)())
{
	KeyMapping = FInputActionKeyMapping(KeyName, Key);
	UPlayerInput::AddEngineDefinedActionMapping(KeyMapping);
	PlayerInputComponent->BindAction(KeyName, KeyEvent1, Object, Func1);
	PlayerInputComponent->BindAction(KeyName, KeyEvent2, Object, Func2);
}

void ADefaultCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	FInputAxisKeyMapping KeyW, KeyS, KeyD, KeyA, MouseX, MouseY, MouseWheel;
	KeyAxis(PlayerInputComponent, this, KeyW, "MoveForward", EKeys::W, 1.f, &ADefaultCharacter::MoveForward, KeyS, "MoveForward", EKeys::S, -1.f, &ADefaultCharacter::MoveForward);
	KeyAxis(PlayerInputComponent, this, KeyD, "MoveRight", EKeys::D, 1.f, &ADefaultCharacter::MoveRight, KeyA, "MoveRight", EKeys::A, -1.f, &ADefaultCharacter::MoveRight);
	KeyAxis(PlayerInputComponent, this, MouseX, "CameraX", EKeys::MouseX, 1.f, &ADefaultCharacter::CameraX, MouseY, "CameraY", EKeys::MouseY, -1.f, &ADefaultCharacter::CameraY);
	KeyAxis(PlayerInputComponent, this, MouseWheel, "CameraLength", EKeys::MouseWheelAxis, -1.f, &ADefaultCharacter::CameraLength);

	FInputActionKeyMapping KeySpacebar, KeyLeftShift, MouseLeftButton, KeyOne, KeyTwo, KeyThree, KeyFour, KeyLeftAlt;
	KeyAction(PlayerInputComponent, this, KeySpacebar, "Jump", EKeys::SpaceBar, IE_Pressed, &ADefaultCharacter::Jump);
	KeyAction(PlayerInputComponent, this, KeyLeftShift, "Run", EKeys::LeftShift, IE_Pressed, &ADefaultCharacter::StartSprint, IE_Released, &ADefaultCharacter::EndSprint);
	KeyAction(PlayerInputComponent, this, MouseLeftButton, "Attack", EKeys::LeftMouseButton, IE_Pressed, &ADefaultCharacter::Attack);
	KeyAction(PlayerInputComponent, this, KeyOne, "Skill_1", EKeys::One, IE_Pressed, &ADefaultCharacter::Skill_1);
	KeyAction(PlayerInputComponent, this, KeyTwo, "Skill_2", EKeys::Two, IE_Pressed, &ADefaultCharacter::Skill_2);
	KeyAction(PlayerInputComponent, this, KeyThree, "Skill_3", EKeys::Three, IE_Pressed, &ADefaultCharacter::Skill_3);
	KeyAction(PlayerInputComponent, this, KeyFour, "Skill_4", EKeys::Four, IE_Pressed, &ADefaultCharacter::Skill_4);
	KeyAction(PlayerInputComponent, this, KeyLeftAlt, "TogglefollowMouse", EKeys::LeftAlt, IE_Pressed, &ADefaultCharacter::ToggleFollowMouseControl);
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

void ADefaultCharacter::CameraLength(float Value)
{
	if (CameraBoom)
	{
		if (Value > 0 && CameraBoom->TargetArmLength < 600.f)
		{
			float ZoomFactor = Value * 50.f;
			CameraBoom->TargetArmLength += ZoomFactor;
		}
		else if (Value < 0 && CameraBoom->TargetArmLength >200.f)
		{
			float ZoomFactor = Value * 50.f;
			CameraBoom->TargetArmLength += ZoomFactor;
		}
	}
	else { if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("ERROR: ADefaultCharacter::CameraLength(float Value)")); }
}

void ADefaultCharacter::StartSprint()
{
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, TEXT("Called: SprintStart()"));
	GetCharacterMovement()->MaxWalkSpeed = BaseSpeed * SprintMult;
}

void ADefaultCharacter::EndSprint()
{
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Black, TEXT("Called: SprintEnd()"));
	GetCharacterMovement()->MaxWalkSpeed = BaseSpeed;
}

void ADefaultCharacter::ToggleFollowMouseControl()
{
	bUseControllerRotationPitch = ~bUseControllerRotationPitch;
	bUseControllerRotationRoll = ~bUseControllerRotationRoll;
	bUseControllerRotationYaw = ~bUseControllerRotationYaw;
}

void ADefaultCharacter::Attack() { if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("Called: ADefaultCharacter::Attack()")); }
void ADefaultCharacter::Skill_1() { if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("Called: ADefaultCharacter::Skill_1()")); }
void ADefaultCharacter::Skill_2() { if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("Called: ADefaultCharacter::Skill_2()")); }
void ADefaultCharacter::Skill_3() { if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("Called: ADefaultCharacter::Skill_3()")); }
void ADefaultCharacter::Skill_4() { if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("Called: ADefaultCharacter::Skill_4()")); }