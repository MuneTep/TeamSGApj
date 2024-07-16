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
	void Attack();
	//void StartRun();
	//void StopRun();

	void CameraSmooth(float DeltaTime);
	// 공통된 변수 private
private:
	float attack;
	float hp;
	float moveSpeed;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* OriginCameraBoom;
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* OriginViewCamera;


	// getter, setter
public:
	void setAtk(float _atk);
	void setHP(float _hp);
	void setSpeed(float _sp);
	float getAtk();
	float getHP();
	float getSpeed();
};
