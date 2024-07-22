#include "Characters/Character_Revenant.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "RevenantGameModeBase.h"

ACharacter_Revenant::ACharacter_Revenant()
{
	PrimaryActorTick.bCanEverTick = true;

	SetCamera();
}

void ACharacter_Revenant::BeginPlay() {
	Super::BeginPlay();
	//isShoot = true;
	FireTimer = 0;
	Health = MaxHealth;
	MyAnim = Cast<UAnimInstance>(GetMesh()->GetAnimInstance());
	check(nullptr != MyAnim);
	MyAnim->OnMontageEnded.AddDynamic(this, &ACharacter_Revenant::OnAttackMontageEnded);

	GetWorldTimerManager().SetTimer(Handle, this, &ACharacter_Revenant::CheckFireRate, 0.2f, true);

	//°Ç Àû¿ä
	Gun = GetWorld()->SpawnActor<AGun>(GunClass);
	//GetMesh()->HideBoneByName(TEXT("weapon_l"), EPhysBodyOp::PBO_None);
	Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("hand_lSocket"));
	Gun->SetOwner(this);
}
void ACharacter_Revenant::Tick(float DeltaTime)
{ 
	Super::Tick(DeltaTime);

}
void ACharacter_Revenant::SetCamera() { Super::SetCamera(); }
void ACharacter_Revenant::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction(TEXT("Shoot"), EInputEvent::IE_Pressed, this, &ACharacter_Revenant::Shoot);
	PlayerInputComponent->BindAction(TEXT("Shoot"), EInputEvent::IE_Released, this, &ACharacter_Revenant::ShootRelease);
	PlayerInputComponent->BindAction(TEXT("Aim"), EInputEvent::IE_Pressed, this, &ACharacter_Revenant::Aim);
	PlayerInputComponent->BindAction(TEXT("Aim"), EInputEvent::IE_Released, this, &ACharacter_Revenant::AimRelease);

}

float ACharacter_Revenant::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float DamageToApply = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	DamageToApply = FMath::Min(Health, DamageToApply);
	Health -= DamageToApply;
	UE_LOG(LogTemp, Warning, TEXT("Health left %f"), Health);
	if (IsDead())
	{
		ARevenantGameModeBase* GameMode = GetWorld()->GetAuthGameMode<ARevenantGameModeBase>();
		if (GameMode != nullptr)
		{
			GameMode->PawnKilled(this);
		}
		DetachFromControllerPendingDestroy();
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	}
	return DamageToApply;
}

bool ACharacter_Revenant::IsDead() const
{
	return Health <= 0;
}

bool ACharacter_Revenant::IsShoot() const
{
	return CanShoot;
}

void ACharacter_Revenant::AIShoot()
{
	Gun->PullTrigger();
}


void ACharacter_Revenant::Aim()
{
	isShoot = false;
}

void ACharacter_Revenant::AimRelease()
{

}

void ACharacter_Revenant::CheckFireRate()
{
	FireTimer = FireTimer - 0.2f;
	if (FireTimer <= 0)
	{
		ResetFireRate();
		CanShoot = true;
	}
}


void ACharacter_Revenant::Shoot()
{
	if (CanShoot) {
		Gun->PullTrigger();
		CanShoot = false;
	}
}
void ACharacter_Revenant::OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
}
void ACharacter_Revenant::ShootRelease()
{
	//CanShoot = true;
}

void ACharacter_Revenant::ResetFireRate()
{
	FireTimer = 1.2f;
}
