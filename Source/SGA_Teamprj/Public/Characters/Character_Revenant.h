#pragma once

#include "CoreMinimal.h"
#include "Characters/DefaultCharacter.h"
#include "Gun.h"
#include "Character_Revenant.generated.h"


UCLASS(Blueprintable,BlueprintType)
class SGA_TEAMPRJ_API ACharacter_Revenant : public ADefaultCharacter
{
	GENERATED_BODY()
	
public:
	ACharacter_Revenant();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;
	virtual void SetCamera() override;

private:
	UPROPERTY(EditDefaultsOnly)
	USpringArmComponent* Revenant_CameraBoom;
	UPROPERTY(EditDefaultsOnly)
	UCameraComponent* Revenant_ViewCamera;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AGun> GunClass;

	UPROPERTY()
	AGun* Gun;


	void Shoot();
};
