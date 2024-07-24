#include "Characters/Character_Kallari.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

ACharacter_Kallari::ACharacter_Kallari()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACharacter_Kallari::BeginPlay() { Super::BeginPlay(); }
void ACharacter_Kallari::Tick(float DeltaTime) { Super::Tick(DeltaTime); }
void ACharacter_Kallari::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) { Super::SetupPlayerInputComponent(PlayerInputComponent); }