#include "Characters/Character_Sparrow.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

ACharacter_Sparrow::ACharacter_Sparrow()
{
	PrimaryActorTick.bCanEverTick = true;

	SetCamera();
}

void ACharacter_Sparrow::BeginPlay() { Super::BeginPlay(); }
void ACharacter_Sparrow::Tick(float DeltaTime) { Super::Tick(DeltaTime); }
void ACharacter_Sparrow::SetCamera() { Super::SetCamera(); }
void ACharacter_Sparrow::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) { Super::SetupPlayerInputComponent(PlayerInputComponent); }