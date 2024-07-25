#pragma once

#include "CoreMinimal.h"
#include "Characters/DefaultCharacter.h"
#include "Character_Sparrow.generated.h"

UCLASS()
class SGA_TEAMPRJ_API ACharacter_Sparrow : public ADefaultCharacter
{
	GENERATED_BODY()
	
public:
	ACharacter_Sparrow();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;
};