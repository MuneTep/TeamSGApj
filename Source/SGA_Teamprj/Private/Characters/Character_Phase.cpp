#include "Characters/Character_Phase.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Camera/CameraComponent.h"
#include "PhaseAnimInstance.h"

ACharacter_Phase::ACharacter_Phase()
{
	PrimaryActorTick.bCanEverTick = true;
	setSpeed(100.f);

	//CapsuleComponentName
	MyCapsuleComponent = GetCapsuleComponent();

	// Anim Instance
	static ConstructorHelpers::FClassFinder<UAnimInstance> ABP_Phase(TEXT("/Game/Character_Phase/AB_Phase"));
	if (ABP_Phase.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(ABP_Phase.Class);
		AnimInstance = Cast<UPhaseAnimInstance>(GetMesh()->GetAnimInstance());
	}

	// Particle
	EnergyShockSystem = LoadObject<UNiagaraSystem>(nullptr, TEXT("/Game/ParagonPhase/FX/Particles/Abilities/Flash/FX/P_PhaseFlash"));
	HitPrimarySparkleSystem = LoadObject<UParticleSystem>(nullptr, TEXT("/Game/ParagonPhase/FX/Particles/Abilities/Primary/FX/P_PhasePrimaryHitWorld"));
}

void ACharacter_Phase::BeginPlay() 
{ 
	Super::BeginPlay(); 
}

void ACharacter_Phase::Tick(float DeltaTime) { 
	Super::Tick(DeltaTime); 
}



void ACharacter_Phase::playNiagara()
{
	USkeletalMeshComponent* skeletalMeshComponent = this->GetMesh();
	

	if(skeletalMeshComponent && EnergyShockSystem)
	{
		FTransform SocketTransform = skeletalMeshComponent->GetSocketTransform(TEXT("Toe_L"));

		UNiagaraFunctionLibrary::SpawnSystemAttached(EnergyShockSystem,
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

void ACharacter_Phase::Attack()
{
	//bIsAttack = true;
	playNiagara();
	Super::Attack();
}

void ACharacter_Phase::ZoomIn( )
{
	Super::ZoomIn();
}

void ACharacter_Phase::ZoomOut( )
{
	Super::ZoomOut();
}

void ACharacter_Phase::JumpStart()
{
	AnimInstance->bIsJump = true;
	Super::JumpStart();
}


void ACharacter_Phase::HandleCharacterHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	OnCharacterHit.Broadcast(HitComponent, OtherActor, OtherComponent, NormalImpulse, Hit);
}


void ACharacter_Phase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) { Super::SetupPlayerInputComponent(PlayerInputComponent); }

