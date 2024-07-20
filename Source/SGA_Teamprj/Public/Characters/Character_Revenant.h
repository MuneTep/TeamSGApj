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
	//ĳ���� ���� 
	UFUNCTION(BlueprintPure)
	bool IsShoot() const;
	void AIShoot();
	void Shoot();
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor *DamageCauser) override;
	//ĳ���� ����
	UFUNCTION(BlueprintPure)
	bool IsDead() const;

protected:
	virtual void BeginPlay() override;

private:
	//ü��
	UPROPERTY(EditDefaultsOnly)
	float MaxHealth = 100;
	UPROPERTY(VisibleAnywhere)
	float Health;

	//��Ÿ�� �Լ�
	UFUNCTION()
	void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted);
	class UAnimInstance* MyAnim;

	//�� ����� Ÿ�̸�
	float FireTimer;
	FTimerHandle Handle;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AGun> GunClass;
	UPROPERTY()
	AGun* Gun;

	//�� ���� �Լ�
	bool isShoot;
	bool CanShoot;

	UFUNCTION(BlueprintCallable)
	void Aim();
	void AimRelease();

	void CheckFireRate();
	void ShootRelease();
	void ResetFireRate();
};
