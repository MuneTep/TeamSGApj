// Fill out your copyright notice in the Description page of Project Settings.


#include "RevenantPlayerController.h"
#include "TimerManager.h"

void ARevenantPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);

	UE_LOG(LogTemp, Warning, TEXT("Charcter Dead Game Finish"));

	GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}
