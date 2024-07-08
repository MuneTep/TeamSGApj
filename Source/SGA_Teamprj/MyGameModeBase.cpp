// Fill out your copyright notice in the Description page of Project Settings.

#include "PhaseCharacter.h"
#include "PhaseController.h"
#include "MyGameModeBase.h"

AMyGameModeBase::AMyGameModeBase()
{
	DefaultPawnClass = APhaseCharacter::StaticClass();
	PlayerControllerClass = APhaseController::StaticClass();
}