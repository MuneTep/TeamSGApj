// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "InputMappingContext.h"
#include "PhaseController.generated.h"

/**
 * 
 */
UCLASS()
class TEAM_PROJECTA_API APhaseController : public APlayerController
{
	GENERATED_BODY()
	

public:
	APhaseController();

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

public:
	void MoveForward(const FInputActionValue& Value);
	void Turn(const FInputActionValue& Value);
	void LookUp(const FInputActionValue& Value);
	void Jump(const FInputActionValue& Value);

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> IA_MoveForward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> IA_Turn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> IA_LookUp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> IA_Jump;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputMappingContext> IMC_PhaseMovement;
};
