#include "Characters/Character_Phase.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

ACharacter_Phase::ACharacter_Phase()
{
	PrimaryActorTick.bCanEverTick = true;

	SetCamera(Phase_CameraBoom, Phase_ViewCamera, 300.f);
}

void ACharacter_Phase::BeginPlay() { Super::BeginPlay(); }
void ACharacter_Phase::Tick(float DeltaTime) { Super::Tick(DeltaTime); }
void ACharacter_Phase::SetCamera(USpringArmComponent* CameraBoom, UCameraComponent* ViewCamera, float Length) { Super::SetCamera(CameraBoom, ViewCamera, Length); }
void ACharacter_Phase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) { Super::SetupPlayerInputComponent(PlayerInputComponent); }