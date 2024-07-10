#include "Characters/Character_Kallari.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

ACharacter_Kallari::ACharacter_Kallari()
{
	PrimaryActorTick.bCanEverTick = true;

	SetCamera();
}

void ACharacter_Kallari::BeginPlay() { Super::BeginPlay(); }
void ACharacter_Kallari::Tick(float DeltaTime) { Super::Tick(DeltaTime); }
void ACharacter_Kallari::SetCamera() { Super::SetCamera(); }
void ACharacter_Kallari::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) { Super::SetupPlayerInputComponent(PlayerInputComponent); }

void ACharacter_Kallari::Attack()
{
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Cyan, TEXT("Called: ACharacter_Kallari::Attack()"));
}
void ACharacter_Kallari::Skill_1()
{
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Cyan, TEXT("Called: ACharacter_Kallari::Skill_1()"));
}
void ACharacter_Kallari::Skill_2()
{
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Cyan, TEXT("Called: ACharacter_Kallari::Skill_2()"));
}
void ACharacter_Kallari::Skill_3()
{
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Cyan, TEXT("Called: ACharacter_Kallari::Skill_3()"));
}
void ACharacter_Kallari::Skill_4()
{
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Cyan, TEXT("Called: ACharacter_Kallari::Skill_4()"));
}