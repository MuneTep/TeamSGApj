#pragma once

#include "CoreMinimal.h"
#include "Characters/DefaultCharacter.h"
#include "Character_Revenant.generated.h"

UCLASS()
class TEAMPJ_API ACharacter_Revenant : public ADefaultCharacter
{
	GENERATED_BODY()
	
public:
	ACharacter_Revenant();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;
	virtual void SetCamera(class USpringArmComponent* CameraBoom, class UCameraComponent* ViewCamera, float Length) override;

private:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* Revenant_CameraBoom;
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Revenant_ViewCamera;
};
