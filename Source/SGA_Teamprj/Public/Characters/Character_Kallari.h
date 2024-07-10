#pragma once

#include "CoreMinimal.h"
#include "Characters/DefaultCharacter.h"
#include "Character_Kallari.generated.h"

UCLASS()
class SGA_TEAMPRJ_API ACharacter_Kallari : public ADefaultCharacter
{
	GENERATED_BODY()

public:
	ACharacter_Kallari();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;
	virtual void SetCamera(class USpringArmComponent* Default_CameraBoom, class UCameraComponent* Default_ViewCamera, float Default_Length) override;
	
private:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* ViewCamera;
	float Length;
};
