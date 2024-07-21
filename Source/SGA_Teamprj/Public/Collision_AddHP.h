// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CollisionBox.h"
#include "Collision_AddHP.generated.h"

/**
 * 
 */
UCLASS()
class SGA_TEAMPRJ_API ACollision_AddHP : public ACollisionBox
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	UFUNCTION()
	virtual void CollisionBoxOn(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	UFUNCTION()
	virtual void CollisionBoxOff(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;
};
