#pragma once

#include "CoreMinimal.h"
#include "Characters/DefaultCharacter.h"
#include "Gun.h"
#include "Character_Revenant.generated.h"


UCLASS()
class SGA_TEAMPRJ_API ACharacter_Revenant : public ADefaultCharacter
{
	GENERATED_BODY()
	
public:
	ACharacter_Revenant();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	//캐릭터 공격 
	UFUNCTION(BlueprintPure)
	bool IsShoot() const;
	void AIShoot();
	void Shoot();
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor *DamageCauser) override;
	//캐릭터 죽음
	UFUNCTION(BlueprintPure)
	bool IsDead() const;

protected:
	virtual void BeginPlay() override;
	virtual void SetCamera() override;

private:
	UPROPERTY(EditDefaultsOnly)
	USpringArmComponent* Revenant_CameraBoom;
	UPROPERTY(EditDefaultsOnly)
	UCameraComponent* Revenant_ViewCamera;

	//체력
	UPROPERTY(EditDefaultsOnly)
	float MaxHealth = 100;
	UPROPERTY(VisibleAnywhere)
	float Health;

	//몽타주 함수
	UFUNCTION()
	void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted);
	class UAnimInstance* MyAnim;

	//총 딜레이 타이머
	float FireTimer;
	FTimerHandle Handle;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AGun> GunClass;
	UPROPERTY()
	AGun* Gun;

	//총 내부 함수
	bool isShoot;
	bool CanShoot;

	UFUNCTION(BlueprintCallable)
	void Aim();
	void AimRelease();

	void CheckFireRate();
	void ShootRelease();
	void ResetFireRate();
};
