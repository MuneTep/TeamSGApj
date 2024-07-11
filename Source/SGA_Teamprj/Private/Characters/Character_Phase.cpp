#include "Characters/Character_Phase.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"

ACharacter_Phase::ACharacter_Phase()
{
	PrimaryActorTick.bCanEverTick = true;

	SetCamera(Phase_CameraBoom, Phase_ViewCamera, 300.f);
	setSpeed(100.f);

	BoxMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BoxMesh"));
	RootComponent = BoxMesh;

	static ConstructorHelpers::FClassFinder<UAnimInstance> ABP_Phase(TEXT("/Game/Character_Phase/AB_Phase"));
	if (ABP_Phase.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(ABP_Phase.Class);
	}

	// 애니메이션 초기화
	//static ConstructorHelpers::FObjectFinder<UAnimSequence> anim_Idle(TEXT("/Game/ParagonPhase/Characters/Heroes/Phase/Animations/Idle"));
	//static ConstructorHelpers::FObjectFinder<UAnimSequence> anim_JogFwd(TEXT("/Game/ParagonPhase/Characters/Heroes/Phase/Animations/Jog_Fwd"));
	//Anim_Idle = anim_Idle.Object;
	//Anim_JogFwd = anim_JogFwd.Object;
	//Anim = Anim_Idle;
}

void ACharacter_Phase::BeginPlay() 
{ 
	Super::BeginPlay(); 

}
void ACharacter_Phase::Tick(float DeltaTime) { Super::Tick(DeltaTime); 
	// UpdateAnim(); 
}
void ACharacter_Phase::SetCamera(USpringArmComponent* CameraBoom, UCameraComponent* ViewCamera, float Length) { ADefaultCharacter::SetCamera(CameraBoom, ViewCamera, Length); }

// 선택된 애니메이션 플레이, Sequence버전 레거시 코드
//void ACharacter_Phase::PlayAnim()
//{
//	bool bLoop = true;
//	GetMesh()->PlayAnimation(Anim, bLoop);
//}
//
//void ACharacter_Phase::UpdateAnim()
//{
//	FVector velocity = GetVelocity();
//
//	if (!velocity.IsZero())
//	{
//		//Anim = Anim_JogFwd;
//	}
//	else
//	{
//		//Anim = Anim_Idle;
//	}
//
//	//if(Anim.is)
//	//PlayAnim();
//}


void ACharacter_Phase::playNiagara()
{
	USkeletalMeshComponent* skeletalMeshComponent = this->GetMesh();
	UNiagaraSystem* sparkleSystem = LoadObject<UNiagaraSystem>(nullptr, TEXT("/Game/FxTutorial/NS_ShockwaveTutorial_FX"));

	if(skeletalMeshComponent && sparkleSystem)
	{
		FTransform SocketTransform = skeletalMeshComponent->GetSocketTransform(TEXT("Toe_L"));

		UNiagaraFunctionLibrary::SpawnSystemAttached(sparkleSystem,
			skeletalMeshComponent, L"Toe_L", SocketTransform.GetLocation(), SocketTransform.Rotator(),FVector(1.0f), EAttachLocation::KeepRelativeOffset,true,
			ENCPoolMethod::None, false, true);
	}
}

void ACharacter_Phase::MoveForward(float Value)
{
	//playNiagara();
	//Anim = Anim_JogFwd;
	//PlayAnim();
	Super::MoveForward(Value);
}

void ACharacter_Phase::MoveRight(float Value)
{
	Super::MoveRight(Value);
}

void ACharacter_Phase::MouseX(float Value)
{
	Super::MouseX(Value);
}

void ACharacter_Phase::MouseY(float Value)
{
	Super::MouseY(Value);
}

void ACharacter_Phase::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Log, TEXT("NotifyHit"));
}




void ACharacter_Phase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) { Super::SetupPlayerInputComponent(PlayerInputComponent); }

