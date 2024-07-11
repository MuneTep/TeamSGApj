#include "Characters/Character_Kallari.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

ACharacter_Kallari::ACharacter_Kallari()
{
	PrimaryActorTick.bCanEverTick = true;

	SetCamera(Kallari_CameraBoom, Kallari_ViewCamera, 300.f);
}

void ACharacter_Kallari::BeginPlay() { Super::BeginPlay(); }
void ACharacter_Kallari::Tick(float DeltaTime) { Super::Tick(DeltaTime); }
void ACharacter_Kallari::SetCamera(USpringArmComponent* CameraBoom, UCameraComponent* ViewCamera, float Length) { Super::SetCamera(CameraBoom, ViewCamera, Length); }
void ACharacter_Kallari::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) { Super::SetupPlayerInputComponent(PlayerInputComponent); }