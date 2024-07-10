#pragma once

#include "CoreMinimal.h"
#include "Characters/DefaultCharacter.h"
#include "Character_Phase.generated.h"

UCLASS()
class TEAMPJ_API ACharacter_Phase : public ADefaultCharacter
{
	GENERATED_BODY()
	
public:
	ACharacter_Phase();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;
	virtual void SetCamera(class USpringArmComponent* CameraBoom, class UCameraComponent* ViewCamera, float Length) override;

private:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* Phase_CameraBoom;
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Phase_ViewCamera;
};
