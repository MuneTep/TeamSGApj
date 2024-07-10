#include "Characters/Character_Sparrow.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

ACharacter_Sparrow::ACharacter_Sparrow()
{
	PrimaryActorTick.bCanEverTick = true;

	SetCamera(Sparrow_CameraBoom, Sparrow_ViewCamera, 300.f);
}

void ACharacter_Sparrow::BeginPlay() { Super::BeginPlay(); }
void ACharacter_Sparrow::Tick(float DeltaTime) { Super::Tick(DeltaTime); }
void ACharacter_Sparrow::SetCamera(USpringArmComponent* CameraBoom, UCameraComponent* ViewCamera, float Length) { Super::SetCamera(CameraBoom, ViewCamera, Length); }
void ACharacter_Sparrow::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) { Super::SetupPlayerInputComponent(PlayerInputComponent); }