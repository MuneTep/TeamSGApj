#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DefaultCharacter.generated.h"

UCLASS()
class SGA_TEAMPRJ_API ADefaultCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ADefaultCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;
	void SetCamera();
	void MoveForward(float Value);
	void MoveRight(float Value);
	void CameraX(float Value);
	void CameraY(float Value);
	void SprintStart();
	void SprintEnd();
	void CameraZoom(float Value);

protected:
	float SprintMult;
	float BaseSpeed;
	virtual void Attack1();

private:
	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* ViewCamera;
};