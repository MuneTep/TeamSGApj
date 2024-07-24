#include "Characters/Character_Revenant.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

ACharacter_Revenant::ACharacter_Revenant()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACharacter_Revenant::BeginPlay() { Super::BeginPlay(); }
void ACharacter_Revenant::Tick(float DeltaTime) { Super::Tick(DeltaTime); }
void ACharacter_Revenant::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) { Super::SetupPlayerInputComponent(PlayerInputComponent); }