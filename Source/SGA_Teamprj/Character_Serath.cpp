// Fill out your copyright notice in the Description page of Project Settings.


#include "Character_Serath.h"
#include "MyAnimInstance.h"

#include "Components/InputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"

ACharacter_Serath::ACharacter_Serath()
{
	PrimaryActorTick.bCanEverTick = true;

	SetCamera();
}

void ACharacter_Serath::Attack()
{
	auto AnimInstance = Cast<UMyAnimInstance>(GetMesh()->GetAnimInstance());
	// 실패시 리턴
	if (nullptr == AnimInstance)
		return;

	AnimInstance->PlayAttackMontage();
}

void ACharacter_Serath::Skill_01()
{
	auto AnimInstance = Cast<UMyAnimInstance>(GetMesh()->GetAnimInstance());
	// 실패시 리턴
	if (nullptr == AnimInstance)
		return;

	AnimInstance->PlaySkillMonteage_01();
}

void ACharacter_Serath::Skill_02_Start()
{
	auto AnimInstance = Cast<UMyAnimInstance>(GetMesh()->GetAnimInstance());
	// 실패시 리턴
	if (nullptr == AnimInstance)
		return;

	AnimInstance->PlaySkillMonteage_02_Start();
}

void ACharacter_Serath::Skill_02_Stop()
{
	auto AnimInstance = Cast<UMyAnimInstance>(GetMesh()->GetAnimInstance());
	// 실패시 리턴
	if (nullptr == AnimInstance)
		return;

	AnimInstance->PlaySkillMonteage_02_Stop();
}

void ACharacter_Serath::BeginPlay() { Super::BeginPlay(); }
void ACharacter_Serath::Tick(float DeltaTime) { Super::Tick(DeltaTime); }
void ACharacter_Serath::SetCamera() { Super::SetCamera(); }

void ACharacter_Serath::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent); 

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Triggered, this, &ACharacter_Serath::Attack);
		EnhancedInputComponent->BindAction(SkillAction_01, ETriggerEvent::Triggered, this, &ACharacter_Serath::Skill_01);
		EnhancedInputComponent->BindAction(SkillAction_02, ETriggerEvent::Triggered, this, &ACharacter_Serath::Skill_02_Start);
		EnhancedInputComponent->BindAction(SkillAction_02, ETriggerEvent::Completed, this, &ACharacter_Serath::Skill_02_Stop);
	}
}