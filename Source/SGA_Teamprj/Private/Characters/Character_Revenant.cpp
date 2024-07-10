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
	Gun = GetWorld()->SpawnActor<AGun>(GunClass);
	//GetMesh()->HideBoneByName(TEXT("weapon_l"), EPhysBodyOp::PBO_None);
	Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("weaponSocket"));
	Gun->SetOwner(this);
}
void ACharacter_Revenant::Tick(float DeltaTime) { Super::Tick(DeltaTime); }
void ACharacter_Revenant::SetCamera() { Super::SetCamera(); }



void ACharacter_Revenant::Shoot()
{
	Gun->PullTrigger();
}
void ACharacter_Revenant::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) 
{ 
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction(TEXT("Shoot"), EInputEvent::IE_Pressed, this, &ACharacter_Revenant::Shoot);
}