// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CollisionBox.h"
#include "Collision_MoveLevel.generated.h"

/**
 * 
 */
UCLASS()
class SGA_TEAMPRJ_API ACollision_MoveLevel : public ACollisionBox
{
	GENERATED_BODY()
public:
	UFUNCTION()
	virtual void CollisionBoxOn(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	
};
