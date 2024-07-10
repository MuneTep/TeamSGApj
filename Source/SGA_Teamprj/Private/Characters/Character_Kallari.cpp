#include "Characters/Character_Kallari.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

ACharacter_Kallari::ACharacter_Kallari() :Length(300.f)
{
	PrimaryActorTick.bCanEverTick = true;

	SetCamera(CameraBoom, ViewCamera, Length);
}

void ACharacter_Kallari::BeginPlay() { Super::BeginPlay(); }
void ACharacter_Kallari::Tick(float DeltaTime) { Super::Tick(DeltaTime); }
void ACharacter_Kallari::SetCamera(class USpringArmComponent* Default_CameraBoom, class UCameraComponent* Default_ViewCamera, float Default_Length) { Super::SetCamera(CameraBoom, ViewCamera, Length); }
void ACharacter_Kallari::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) { Super::SetupPlayerInputComponent(PlayerInputComponent); }