// Fill out your copyright notice in the Description page of Project Settings.


#include "Collision_MoveLevel.h"
#include "Kismet/GameplayStatics.h"

void ACollision_MoveLevel::CollisionBoxOn(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UGameplayStatics::OpenLevel(this, FName("TestMap"));
}
