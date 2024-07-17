#include "Characters/DefaultCharacter.h"
#include "GameFramework/PlayerInput.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

#include "Camera/CameraComponent.h"

ADefaultCharacter::ADefaultCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ADefaultCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (ZoomCurve)
	{
		FOnTimelineFloat TimelineCallback;
		TimelineCallback.BindUFunction(this, FName("TimelineFloatReturn"));
		ZoomTimeline.AddInterpFloat(ZoomCurve, TimelineCallback);

		ZoomTimeline.SetLooping(false);
		ZoomTimeline.SetTimelineLength(2.0f); // Example: 2 seconds timeline

		
	}
}

void ADefaultCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//CameraSmooth(DeltaTime);

	ZoomTimeline.TickTimeline(DeltaTime);
}

void ADefaultCharacter::SetCamera(USpringArmComponent* CameraBoom, UCameraComponent* ViewCamera, float Length)
{
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = Length;
	CameraBoom->bUsePawnControlRotation = true;

	OriginCameraBoom = CameraBoom;

	ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCamera"));
	ViewCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	ViewCamera->bUsePawnControlRotation = false;
	OriginViewCamera = ViewCamera;
}

void ADefaultCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &ADefaultCharacter::MoveForward);
	PlayerInputComponent->BindAxis(FName("MoveRight"), this, &ADefaultCharacter::MoveRight);
	PlayerInputComponent->BindAxis(FName("MouseX"), this, &ADefaultCharacter::MouseX);
	PlayerInputComponent->BindAxis(FName("MouseY"), this, &ADefaultCharacter::MouseY);
	PlayerInputComponent->BindAction(FName("Jump"), IE_Pressed, this, &ADefaultCharacter::Jump);
	PlayerInputComponent->BindAction(FName("Attack"), IE_Pressed, this, &ADefaultCharacter::Attack);
	PlayerInputComponent->BindAction(FName("ZoomIn"), IE_Pressed, this, &ADefaultCharacter::ZoomIn);
	PlayerInputComponent->BindAction(FName("ZoomOut"), IE_Pressed, this, &ADefaultCharacter::ZoomOut);
	//PlayerInputComponent->BindAction(FName("AimOn"), IE_Pressed, this, &ADefaultCharacter::AimOn);
	//PlayerInputComponent->BindAction(FName("AimOn"), IE_Released, this, &ADefaultCharacter::AimOut);
	PlayerInputComponent->BindAxis(FName("AimOn"), this, &ADefaultCharacter::CameraZoom);
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
	//CameraSmooth(GetWorld()->DeltaTimeSeconds);
}

void ADefaultCharacter::MouseY(float Value)
{
	AddControllerPitchInput(Value);
}

void ADefaultCharacter::Jump()
{
	Super::Jump();
}

void ADefaultCharacter::Attack()
{

}

void ADefaultCharacter::ZoomIn()
{
	float currentCameraBoom = OriginCameraBoom->TargetArmLength;
	OriginCameraBoom->TargetArmLength = FMath::Clamp(currentCameraBoom + 50.0f, 50, 300);
}

void ADefaultCharacter::ZoomOut()
{
	float currentCameraBoom = OriginCameraBoom->TargetArmLength;
	OriginCameraBoom->TargetArmLength = FMath::Clamp(currentCameraBoom - 50.0f, 50, 300);

	//UE_LOG(LogTemp, Warning, TEXT("CameraSmooth %d"), currentCameraBoom)
}

//void ADefaultCharacter::AimOn()
//{
//	OriginCameraBoom->TargetArmLength = 200.0f;
//}
//
//void ADefaultCharacter::AimOut()
//{
//	OriginCameraBoom->TargetArmLength = 300.0f;
//}

void ADefaultCharacter::CameraZoom(float Value)
{
	if (bIsZoom)
	{
		// ZoomOut (멀리)
		bIsZoom = false;
		ZoomTimeline.PlayFromStart();

		//float NewFOV = FMath::Lerp(120.0f, 300.f, Value); // Example: Zoom from 90 to 60 degrees FOV
		//OriginViewCamera->SetFieldOfView(NewFOV);
	}
	else
	{
		// ZoomIn (가까이)
		bIsZoom = true;

		ZoomTimeline.PlayFromStart();

		//float NewFOV = FMath::Lerp(300.f, 120.0f, Value); // Example: Zoom from 90 to 60 degrees FOV
		//OriginViewCamera->SetFieldOfView(NewFOV);
	}
}



void ADefaultCharacter::CameraSmooth(float DeltaTime)
{
	float MaxCameraArmLength = 400.0f;
	float CameraArmLength = MaxCameraArmLength;

	if (OriginCameraBoom != nullptr)
	{
		//UE_LOG(LogTemp, Warning, TEXT("CameraSmooth"))

		FVector Start = OriginCameraBoom->GetComponentLocation();
		FVector End = UKismetMathLibrary::GetDirectionUnitVector(Start, OriginViewCamera->GetComponentLocation()) * MaxCameraArmLength + Start;
		TArray<AActor*> ToIgnore;
		FHitResult OutCameraHit;
		bool IsCameraHit = UKismetSystemLibrary::SphereTraceSingle(
			GetWorld(), Start, End,
			OriginCameraBoom->ProbeSize,
			ETraceTypeQuery::TraceTypeQuery1, true,
			ToIgnore,
			EDrawDebugTrace::None, OutCameraHit, true);

		if (IsCameraHit)
		{
			CameraArmLength = UKismetMathLibrary::Clamp(OutCameraHit.Distance - OriginCameraBoom->ProbeSize, 30, MaxCameraArmLength);
		}

		OriginCameraBoom->TargetArmLength = UKismetMathLibrary::FInterpTo(OriginCameraBoom->TargetArmLength, CameraArmLength, DeltaTime, 10);
	}

}

void ADefaultCharacter::TimelineFloatReturn(float Value)
{
	float NewFOV = FMath::Lerp(300.f, 120.f, Value); // Example: Zoom from 90 to 60 degrees FOV
	OriginViewCamera->SetFieldOfView(NewFOV);
}

void ADefaultCharacter::setAtk(float _atk){	attack = _atk;}
void ADefaultCharacter::setHP(float _hp){hp = _hp;}
void ADefaultCharacter::setSpeed(float _sp){moveSpeed = _sp;}
float ADefaultCharacter::getAtk(){return attack;}
float ADefaultCharacter::getHP(){return hp;}
float ADefaultCharacter::getSpeed(){return moveSpeed;}
