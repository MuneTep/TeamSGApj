// Fill out your copyright notice in the Description page of Project Settings.


#include "Collision_MoveLevel.h"
#include "Kismet/GameplayStatics.h"

void ACollision_MoveLevel::BeginPlay()
{
	Super::BeginPlay();
}

void ACollision_MoveLevel::CollisionBoxOn(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UGameplayStatics::OpenLevel(this, FName("TestMap"));
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, TEXT("레벨 이동!"));
}

void ACollision_MoveLevel::CollisionBoxOff(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("충돌 해제"));
}
