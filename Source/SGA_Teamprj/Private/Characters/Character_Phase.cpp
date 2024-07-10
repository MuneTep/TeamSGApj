#include "Characters/Character_Phase.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

ACharacter_Phase::ACharacter_Phase()
{
	PrimaryActorTick.bCanEverTick = true;

	SetCamera();
}

void ACharacter_Phase::BeginPlay() { Super::BeginPlay(); }
void ACharacter_Phase::Tick(float DeltaTime) { Super::Tick(DeltaTime); }
void ACharacter_Phase::SetCamera() {  }
void ACharacter_Phase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) { Super::SetupPlayerInputComponent(PlayerInputComponent); }