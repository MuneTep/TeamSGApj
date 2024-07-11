// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DefaultCharacter.h"
#include "Character_Serath.generated.h"

/**
 * 
 */
UCLASS()
class SGA_TEAMPRJ_API ACharacter_Serath : public ADefaultCharacter
{
	GENERATED_BODY()
	
public:
	ACharacter_Serath();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* AttackAction;
	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* SkillAction_01;

	void Attack();
	void Skill_01();

	virtual void BeginPlay() override;
	virtual void SetCamera() override;
};
