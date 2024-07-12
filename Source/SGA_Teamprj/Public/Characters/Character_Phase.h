#pragma once

#include "CoreMinimal.h"

#include "Characters/DefaultCharacter.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"

#include "Character_Phase.generated.h"

UCLASS()
class SGA_TEAMPRJ_API ACharacter_Phase : public ADefaultCharacter
{
	GENERATED_BODY()
	
public:
	ACharacter_Phase();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;
	virtual void SetCamera(class USpringArmComponent* CameraBoom, class UCameraComponent* ViewCamera, float Length) override;


	// 애니메이션 관련 함수, 변수
	//UAnimMontage* PhaseMontage;
	//UAnimSequence* Anim;
	//void PlayAnim();
	//void UpdateAnim();

private:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* Phase_CameraBoom;
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Phase_ViewCamera;

	void playNiagara();
public:
	void MoveForward(float Value);
	void MoveRight(float Value);
	void MouseX(float Value);
	void MouseY(float Value);
	void JumpStart(float Value);
	void JumpEnd(float Value);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FCharacterHitSignature,
		UPrimitiveComponent*, HitComponent,
		AActor*, OtherActor,
		UPrimitiveComponent*, OtherComponent,
		FVector, NormalImpulse,
		const FHitResult&, Hit);

	// 이벤트 브로드캐스트
	UPROPERTY(BlueprintAssignable, Category = "Character")
		FCharacterHitSignature OnCharacterHit;

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character")
	class UCapsuleComponent* MyCapsuleComponent;

	// Called when the character hits something
	UFUNCTION()
		void HandleCharacterHit(
			UPrimitiveComponent* HitComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComponent,
			FVector NormalImpulse,
			const FHitResult& Hit
		);

private:
	// 애니메이션 모음
	//UAnimSequence* Anim_Idle;
	//UAnimSequence* Anim_JogFwd;
};
