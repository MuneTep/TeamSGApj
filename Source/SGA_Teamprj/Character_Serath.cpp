// Fill out your copyright notice in the Description page of Project Settings.


#include "Character_Serath.h"

ACharacter_Serath::ACharacter_Serath()
{
	PrimaryActorTick.bCanEverTick = true;

	SetCamera();
}

void ACharacter_Serath::BeginPlay() { Super::BeginPlay(); }
void ACharacter_Serath::Tick(float DeltaTime) { Super::Tick(DeltaTime); }
void ACharacter_Serath::SetCamera() { Super::SetCamera(); }
void ACharacter_Serath::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) { Super::SetupPlayerInputComponent(PlayerInputComponent); }