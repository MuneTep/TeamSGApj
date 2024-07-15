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
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor *DamageCauser) override;

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

	UPROPERTY(EditAnywhere)
	float RotationRate = 10;

	UPROPERTY(EditDefaultsOnly)
	float MaxHealth = 100;
	UPROPERTY(VisibleAnywhere)
	float Health;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AGun> GunClass;

	UPROPERTY()
	AGun* Gun;

	float FireTimer;
	FTimerHandle Handle;

	UPROPERTY(EditAnywhere)
	bool isShoot;

	UPROPERTY(EditAnywhere)
	bool isAiming;
	bool CanShoot;

	UFUNCTION(BlueprintCallable)
	void Aim();
	void AimRelease();
	void Shoot();
	void ShootRelease();
	void CheckFireRate();
	void ResetFireRate();
};
