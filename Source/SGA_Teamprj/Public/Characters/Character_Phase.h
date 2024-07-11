#pragma once

#include "CoreMinimal.h"

#include "Characters/DefaultCharacter.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
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


	// �ִϸ��̼� ���� �Լ�, ����
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
	void CollisionCheck();


	UFUNCTION()
	virtual void NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;	

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* BoxMesh;

private:
	// �ִϸ��̼� ����
	//UAnimSequence* Anim_Idle;
	//UAnimSequence* Anim_JogFwd;
};
