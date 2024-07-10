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
	virtual void SetCamera(class USpringArmComponent* CameraBoom, class UCameraComponent* ViewCamera, float Length);
	void MoveForward(float Value);
	void MoveRight(float Value);
	void MouseX(float Value);
	void MouseY(float Value);
	void Jump();
	//void StartRun();
	//void StopRun();


	// 공통된 변수 private
private:
	float attack;
	float hp;
	float moveSpeed;

	// getter, setter
public:
	void setAtk(float _atk);
	void setHP(float _hp);
	void setSpeed(float _sp);
	float getAtk();
	float getHP();
	float getSpeed();
};
