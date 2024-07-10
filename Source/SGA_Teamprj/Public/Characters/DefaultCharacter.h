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
	void KeyAxis(UInputComponent* PlayerInputComponent, ADefaultCharacter* Object, 
		struct FInputAxisKeyMapping& KeyMapping, FName KeyName, FKey Key, float Scale, void(ADefaultCharacter::* Func)(float));
	void KeyAxis(UInputComponent* PlayerInputComponent, ADefaultCharacter* Object, 
		struct FInputAxisKeyMapping& KeyMapping1, FName KeyName1, FKey Key1, float Scale1, void(ADefaultCharacter::* Func1)(float), 
		struct FInputAxisKeyMapping& KeyMapping2, FName KeyName2, FKey Key2, float Scale2, void(ADefaultCharacter::* Func2)(float));
	void KeyAction(UInputComponent* PlayerInputComponent, ADefaultCharacter* Object,
		struct FInputActionKeyMapping& KeyMapping, FName KeyName, FKey Key, EInputEvent KeyEvent, void(ADefaultCharacter::* Func)());
	void KeyAction(UInputComponent* PlayerInputComponent, ADefaultCharacter* Object,
		struct FInputActionKeyMapping& KeyMapping, FName KeyName, FKey Key, 
		EInputEvent KeyEvent1, void(ADefaultCharacter::* Func1)(),
		EInputEvent KeyEvent2, void(ADefaultCharacter::* Func2)());

	void MoveForward(float Value);
	void MoveRight(float Value);
	void CameraX(float Value);
	void CameraY(float Value);
	void CameraLength(float Value);
	void StartSprint();
	void EndSprint();
	void ToggleFollowMouseControl();

protected:
	float BaseSpeed;
	float SprintMult;

	virtual void BeginPlay() override;
	virtual void SetCamera();
	virtual void Attack();
	virtual void Skill_1();
	virtual void Skill_2();
	virtual void Skill_3();
	virtual void Skill_4();

private:
	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* ViewCamera;
};
