#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/TimelineComponent.h"
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
	void MouseX(float Value);
	void MouseY(float Value);
	void JumpStart();
	void JumpEnd();
	void Attack();
	void ZoomIn();
	void ZoomOut();

	UFUNCTION()
	void CameraZoom();
	//void StartRun();
	//void StopRun();
	void CameraSmooth(float DeltaTime);
	// 공통된 변수 private
private:
	float attack;
	float hp;
	bool bIsZoom;

	float SprintMult;
	float BaseSpeed;

	FOnTimelineFloat TimelineCallback;
	FOnTimelineEvent SmoothZoomTimelineFinish;

	UFUNCTION()
	void SmoothZoomOnFinish(); // Curve가 끝났을 때
	
	UFUNCTION()
	void TimelineFloatReturn(float Value);

	UPROPERTY(EditAnywhere, Category = "Timeline")
	FTimeline ZoomTimeline;
	UPROPERTY(EditAnywhere, Category = "Timeline")
	UCurveFloat* ZoomCurve;

	// Camera Components
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* ViewCamera;


	// getter, setter
public:
	void setAtk(float _atk);
	void setHP(float _hp);
	void setSpeed(float _sp);
	float getAtk();
	float getHP();
	float getSpeed();
};
