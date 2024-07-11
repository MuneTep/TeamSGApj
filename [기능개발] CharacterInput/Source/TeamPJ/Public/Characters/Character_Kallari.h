#pragma once

#include "CoreMinimal.h"
#include "Characters/DefaultCharacter.h"
#include "Character_Kallari.generated.h"

UCLASS()
class TEAMPJ_API ACharacter_Kallari : public ADefaultCharacter
{
	GENERATED_BODY()

public:
	ACharacter_Kallari();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;
	virtual void SetCamera(class USpringArmComponent* CameraBoom, class UCameraComponent* ViewCamera, float Length) override;
	
private:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* Kallari_CameraBoom;
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Kallari_ViewCamera;
};
