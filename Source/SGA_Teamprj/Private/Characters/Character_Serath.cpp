#include "Characters/Character_Serath.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

ACharacter_Serath::ACharacter_Serath()
{
	PrimaryActorTick.bCanEverTick = true;

	SetCamera();
}

void ACharacter_Serath::BeginPlay() { Super::BeginPlay(); }
void ACharacter_Serath::Tick(float DeltaTime) { Super::Tick(DeltaTime); }
void ACharacter_Serath::SetCamera() {  }
void ACharacter_Serath::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) { Super::SetupPlayerInputComponent(PlayerInputComponent); }