// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RevenantGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class SGA_TEAMPRJ_API ARevenantGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void PawnKilled(APawn* PawnKilled);

};
