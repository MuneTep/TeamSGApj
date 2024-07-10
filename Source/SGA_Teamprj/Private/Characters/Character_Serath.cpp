#include "Characters/Character_Serath.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

ACharacter_Serath::ACharacter_Serath()
{
	PrimaryActorTick.bCanEverTick = true;

	SetCamera(Serath_CameraBoom, Serath_ViewCamera, 300.f);
}

void ACharacter_Serath::BeginPlay() { Super::BeginPlay(); }
void ACharacter_Serath::Tick(float DeltaTime) { Super::Tick(DeltaTime); }
void ACharacter_Serath::SetCamera(USpringArmComponent* CameraBoom, UCameraComponent* ViewCamera, float Length) { Super::SetCamera(CameraBoom, ViewCamera, Length); }
void ACharacter_Serath::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) { Super::SetupPlayerInputComponent(PlayerInputComponent); }