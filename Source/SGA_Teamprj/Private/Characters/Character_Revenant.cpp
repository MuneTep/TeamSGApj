#include "Characters/Character_Revenant.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

ACharacter_Revenant::ACharacter_Revenant()
{
	PrimaryActorTick.bCanEverTick = true;

	SetCamera(Revenant_CameraBoom, Revenant_ViewCamera, 300.f);
}

void ACharacter_Revenant::BeginPlay() {
	Super::BeginPlay();
	Gun = GetWorld()->SpawnActor<AGun>(GunClass);
	GetMesh()->HideBoneByName(TEXT("weapon_l"), EPhysBodyOp::PBO_None);
	Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("weaponSocket"));
	Gun->SetOwner(this);
}
void ACharacter_Revenant::Tick(float DeltaTime) { Super::Tick(DeltaTime); }
void ACharacter_Revenant::SetCamera(USpringArmComponent* CameraBoom, UCameraComponent* ViewCamera, float Length) { Super::SetCamera(CameraBoom, ViewCamera, Length); }
void ACharacter_Revenant::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) { Super::SetupPlayerInputComponent(PlayerInputComponent); }