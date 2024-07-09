#include "Characters/Character_Revenant.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

ACharacter_Revenant::ACharacter_Revenant()
{
	PrimaryActorTick.bCanEverTick = true;

	SetCamera(Revenant_CameraBoom, Revenant_ViewCamera, 300.f);
}

void ACharacter_Revenant::BeginPlay() { Super::BeginPlay(); }
void ACharacter_Revenant::Tick(float DeltaTime) { Super::Tick(DeltaTime); }
void ACharacter_Revenant::SetCamera(USpringArmComponent* CameraBoom, UCameraComponent* ViewCamera, float Length) { Super::SetCamera(CameraBoom, ViewCamera, Length); }
void ACharacter_Revenant::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) { Super::SetupPlayerInputComponent(PlayerInputComponent); }