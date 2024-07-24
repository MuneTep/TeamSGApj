#pragma once

#include "CoreMinimal.h"

#include "Characters/DefaultCharacter.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "../PhaseAnimInstance.h"
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

private:

	void playNiagara();
	bool bIsAttack;

public:
	void MoveForward(float Value);
	void MoveRight(float Value);
	void MouseX(float Value);
	void MouseY(float Value);
	void Attack();
	void ZoomIn();
	void ZoomOut();
	void JumpStart();

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
	

	// CharacterAnimInstance
	UPhaseAnimInstance* AnimInstance;
	// Particle Fx
	UNiagaraSystem* EnergyShockSystem;
	UParticleSystem* HitPrimarySparkleSystem;
};
