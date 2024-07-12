#include "Characters/Character_Revenant.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraComponent.h"

ACharacter_Revenant::ACharacter_Revenant()
{
	PrimaryActorTick.bCanEverTick = true;

	SetCamera();
}

void ACharacter_Revenant::BeginPlay() {
	Super::BeginPlay();
	//타이머 적용
	FireTimer = 0;
	isAiming = false;
	GetWorldTimerManager().SetTimer(Handle, this, &ACharacter_Revenant::CheckFireRate, 0.2f, true);

	//건 적요
	Gun = GetWorld()->SpawnActor<AGun>(GunClass);
	GetMesh()->HideBoneByName(TEXT("weapon_l"), EPhysBodyOp::PBO_None);
	Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("gun_real_barrel"));
	Gun->SetOwner(this);
}
void ACharacter_Revenant::Tick(float DeltaTime) { Super::Tick(DeltaTime); }
void ACharacter_Revenant::SetCamera() { Super::SetCamera(); }
void ACharacter_Revenant::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction(TEXT("Shoot"), EInputEvent::IE_Pressed, this, &ACharacter_Revenant::Shoot);
	PlayerInputComponent->BindAction(TEXT("Shoot"), EInputEvent::IE_Released, this, &ACharacter_Revenant::ShootRelease);
	PlayerInputComponent->BindAction(TEXT("Aim"), EInputEvent::IE_Pressed, this, &ACharacter_Revenant::Aim);
	PlayerInputComponent->BindAction(TEXT("Aim"), EInputEvent::IE_Released, this, &ACharacter_Revenant::Aim);
}

bool ACharacter_Revenant::Aiming()
{

	return CanShoot;
}

void ACharacter_Revenant::Aim()
{
	isAiming = true;
}

void ACharacter_Revenant::Shoot()
{
	if (isAiming)
	{
		if (CanShoot)
		{
			isShoot = true;
			Gun->PullTrigger();
			CanShoot = false;
		}
		else
		{
			isShoot = false;
		}
	}
}
void ACharacter_Revenant::ShootRelease()
{
	isShoot = false;
}
void ACharacter_Revenant::CheckFireRate()
{
	isShoot = true;
	FireTimer = FireTimer - 0.2f;
	if (FireTimer <= 0)
	{
		CanShoot=true;
		ResetFireRate();
	}
}
void ACharacter_Revenant::ResetFireRate()
{
	FireTimer = 1.2f;
}
