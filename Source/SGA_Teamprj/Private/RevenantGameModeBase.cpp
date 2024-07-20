// Fill out your copyright notice in the Description page of Project Settings.


#include "RevenantGameModeBase.h"

ARevenantGameModeBase::ARevenantGameModeBase()
{
	static ConstructorHelpers::FClassFinder<AActor> CharacterBPClassFinder(TEXT("/Script/Engine.Blueprint'/Game/BP_SJW_Revenant/C_Revenant/BP_Character_Revenant.BP_Character_Revenant'"));
	if (CharacterBPClassFinder.Succeeded())
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Cyan, TEXT("ARevenantGameModeBase + ActorBPClassFinder.Succeeded() = Success"));
		CharacterBPClass = CharacterBPClassFinder.Class;
		characterSpawner(CharacterBPClass, myLocation, myRotation);
	}
	else
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, TEXT("ARevenantGameModeBase + ActorBPClassFinder.Succeeded() = Fail"));
		}
	}
}

void ARevenantGameModeBase::BeginPlay()
{
	Super::BeginPlay();
}

void ARevenantGameModeBase::characterSpawner(TSubclassOf<AActor> SpawnActor, FVector Location, FRotator Rotation)
{
	if (SpawnActor)
	{
		UWorld* World = GetWorld();
		if (World)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = GetInstigator();

			AActor* SpwanedActor = World->SpawnActor<AActor>(SpawnActor, Location, Rotation, SpawnParams);
		}
	}
}

void ARevenantGameModeBase::PawnKilled(APawn* PawnKilled)
{
}
