// Fill out your copyright notice in the Description page of Project Settings.


#include "Collision_AddHP.h"
#include "Characters/Character_Revenant.h"
#include "Kismet/GameplayStatics.h"

void ACollision_AddHP::CollisionBoxOn(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ACharacter_Revenant* myCharacter = Cast<ACharacter_Revenant>(UGameplayStatics::GetPlayerPawn(this, 0));
	if (myCharacter)
	{
		myCharacter->AddHealth(20.f);
	}
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, TEXT("체력 20 회복!"));
}

void ACollision_AddHP::CollisionBoxOff(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("충돌 해제"));
}
