#include "Characters/DefaultCharacter.h"
#include "GameFramework/PlayerInput.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

#include "Camera/CameraComponent.h"

ADefaultCharacter::ADefaultCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	bIsZoom = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	
	//GetCharacterMovement()->bOrientRotationToMovement = true;
	//GetCharacterMovement()->RotationRate.Yaw = 720.f;

	const ConstructorHelpers::FObjectFinder<UCurveFloat> Curve(TEXT("/Game/Input/Input_Phase/C_ZoomInOut"));
	
	if (Curve.Succeeded())
	{
		ZoomCurve = Curve.Object;
	}

	if (ZoomCurve != nullptr)
	{
		TimelineCallback.BindUFunction(this, FName("TimelineFloatReturn"));
		SmoothZoomTimelineFinish.BindUFunction(this, FName("SmoothZoomOnFinish"));

		ZoomTimeline.AddInterpFloat(ZoomCurve, TimelineCallback);
		ZoomTimeline.SetTimelineFinishedFunc(SmoothZoomTimelineFinish);

		float Min = 0.0f;
		float Max = 0.25f;
		ZoomCurve->GetTimeRange(Min, Max);
		ZoomTimeline.SetTimelineLength(Max);
		ZoomTimeline.SetLooping(false);
	}
}
	
void ADefaultCharacter::BeginPlay()
{
	Super::BeginPlay();
	ZoomTimeline.Stop();
	
}

void ADefaultCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (ZoomTimeline.IsPlaying())
	{
		ZoomTimeline.TickTimeline(DeltaTime);
	}

}

void ADefaultCharacter::SetCamera()
{
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 300.0f;
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
	FInputAxisKeyMapping KeyMouseX = FInputAxisKeyMapping(FName("CameraX"), EKeys::MouseX, 1.f);
	FInputAxisKeyMapping KeyMouseY = FInputAxisKeyMapping(FName("CameraY"), EKeys::MouseY, -1.f);
	FInputAxisKeyMapping KeyMouseWheel = FInputAxisKeyMapping(FName("CameraZoom"), EKeys::MouseWheelAxis, -1.f);
	FInputActionKeyMapping KeySpacebar(FName("Jump"), EKeys::SpaceBar);
	FInputActionKeyMapping KeyShift(FName("Run"), EKeys::LeftShift);

	UPlayerInput::AddEngineDefinedAxisMapping(KeyW);
	UPlayerInput::AddEngineDefinedAxisMapping(KeyS);
	UPlayerInput::AddEngineDefinedAxisMapping(KeyD);
	UPlayerInput::AddEngineDefinedAxisMapping(KeyA);
	UPlayerInput::AddEngineDefinedAxisMapping(KeyMouseX);
	UPlayerInput::AddEngineDefinedAxisMapping(KeyMouseY);
	UPlayerInput::AddEngineDefinedAxisMapping(KeyMouseWheel);
	UPlayerInput::AddEngineDefinedActionMapping(KeySpacebar);
	UPlayerInput::AddEngineDefinedActionMapping(KeyShift);

	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &ADefaultCharacter::MoveForward);
	PlayerInputComponent->BindAxis(FName("MoveRight"), this, &ADefaultCharacter::MoveRight);
	PlayerInputComponent->BindAxis(FName("MouseX"), this, &ADefaultCharacter::MouseX);
	PlayerInputComponent->BindAxis(FName("MouseY"), this, &ADefaultCharacter::MouseY);
	PlayerInputComponent->BindAction(FName("Jump"), IE_Pressed, this, &ADefaultCharacter::Jump);
	PlayerInputComponent->BindAction(FName("NormalAttack"), IE_Pressed, this, &ADefaultCharacter::Attack);

	PlayerInputComponent->BindAction(FName("AimOn"), IE_Pressed, this, &ADefaultCharacter::CameraZoom);
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

void ADefaultCharacter::JumpStart()
{
	Super::Jump();
}

void ADefaultCharacter::JumpEnd()
{

}

void ADefaultCharacter::Attack()
{
	// RayCast
	FVector Start = GetActorLocation(); // 레이캐스트의 시작 지점
	FVector ForwardVector = GetActorForwardVector(); // 캐릭터의 앞 방향 벡터
	FVector End = Start + (ForwardVector * 1000.0f); // 레이캐스트의 끝 지점 (1000.0f는 거리)

	FHitResult HitResult;
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this); // 자신을 무시하도록 설정 (옵션)

	// 레이캐스트 실행
	bool bHit = GetWorld()->LineTraceSingleByChannel(
		HitResult,
		Start,
		End,
		ECC_Visibility,
		QueryParams
	);

	if (bHit)
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit Actor: %s"), *HitResult.GetActor()->GetName());
	}
}

void ADefaultCharacter::ZoomIn()
{
	float currentCameraBoom = CameraBoom->TargetArmLength;
	CameraBoom->TargetArmLength = FMath::Clamp(currentCameraBoom + 50.0f, 50, 300);
}

void ADefaultCharacter::ZoomOut()
{
	float currentCameraBoom = CameraBoom->TargetArmLength;
	CameraBoom->TargetArmLength = FMath::Clamp(currentCameraBoom - 50.0f, 50, 300);

	//UE_LOG(LogTemp, Warning, TEXT("CameraSmooth %d"), currentCameraBoom)
}

//void ADefaultCharacter::AimOn()
//{
//	CameraBoom->TargetArmLength = 200.0f;
//}
//
//void ADefaultCharacter::AimOut()
//{
//	CameraBoom->TargetArmLength = 300.0f;
//}

void ADefaultCharacter::CameraZoom()
{
	if (bIsZoom == true)
	{
		// ZoomOut (멀리)
		bIsZoom = false;
		ZoomTimeline.ReverseFromEnd();
		//UE_LOG(LogTemp, Warning, TEXT("CameraZoom TRUE"))
		return;
	}
	else
	{
		// ZoomIn (가까이)
		bIsZoom = true;

		ZoomTimeline.PlayFromStart(); return;
		//UE_LOG(LogTemp, Warning, TEXT("CameraZoom FALSE"))
		
	}
}



void ADefaultCharacter::CameraSmooth(float DeltaTime)
{
	float MaxCameraArmLength = 400.0f;
	float CameraArmLength = MaxCameraArmLength;

	if (CameraBoom != nullptr)
	{
		//UE_LOG(LogTemp, Warning, TEXT("CameraSmooth"))

		FVector Start = CameraBoom->GetComponentLocation();
		FVector End = UKismetMathLibrary::GetDirectionUnitVector(Start, ViewCamera->GetComponentLocation()) * MaxCameraArmLength + Start;
		TArray<AActor*> ToIgnore;
		FHitResult OutCameraHit;
		bool IsCameraHit = UKismetSystemLibrary::SphereTraceSingle(
			GetWorld(), Start, End,
			CameraBoom->ProbeSize,
			ETraceTypeQuery::TraceTypeQuery1, true,
			ToIgnore,
			EDrawDebugTrace::None, OutCameraHit, true);

		if (IsCameraHit)
		{
			CameraArmLength = UKismetMathLibrary::Clamp(OutCameraHit.Distance - CameraBoom->ProbeSize, 30, MaxCameraArmLength);
		}

		CameraBoom->TargetArmLength = UKismetMathLibrary::FInterpTo(CameraBoom->TargetArmLength, CameraArmLength, DeltaTime, 10);
	}

}

void ADefaultCharacter::SmoothZoomOnFinish()
{
	ZoomTimeline.Stop();
}

void ADefaultCharacter::TimelineFloatReturn(float Value)
{
	float NewFOV = FMath::Lerp(90.f, 60.f, Value); // Example: Zoom from 90 to 60 degrees FOV
	ViewCamera->SetFieldOfView(NewFOV);
}

void ADefaultCharacter::setAtk(float _atk){	attack = _atk;}
void ADefaultCharacter::setHP(float _hp){hp = _hp;}
void ADefaultCharacter::setSpeed(float _sp){ BaseSpeed = _sp;}
float ADefaultCharacter::getAtk(){return attack;}
float ADefaultCharacter::getHP(){return hp;}
float ADefaultCharacter::getSpeed(){return BaseSpeed;}
