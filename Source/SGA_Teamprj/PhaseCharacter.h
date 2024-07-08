// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "InputActionValue.h"
#include "InputMappingContext.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

#include "PhaseCharacter.generated.h"

UCLASS()
class TEAM_PROJECTA_API APhaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APhaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	void MoveForward(float Value);		// 오류 발생, 이유 모르겠음..
	void Turn(float AxisValue);
	void LookUp(float AxisValue);
	void JumpStart();
	void JumpStop();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category ="Input", meta = (AllowPrivate = "true"))
	TObjectPtr<class UInputAction> IA_MoveForward;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input", meta = (AllowPrivate = "true"))
	TObjectPtr<class UInputAction> IA_Turn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input", meta = (AllowPrivate = "true"))
	TObjectPtr<class UInputAction> IA_LookUp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input", meta = (AllowPrivate = "true"))
	TObjectPtr<class UInputAction> IA_Jump;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivate = "true"))
	TObjectPtr<class USpringArmComponent> SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivate = "true"))
	TObjectPtr<class UCameraComponent> Camera;
};
