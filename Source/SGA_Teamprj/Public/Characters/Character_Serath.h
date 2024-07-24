#pragma once

#include "CoreMinimal.h"
#include "Characters/DefaultCharacter.h"
#include "Character_Serath.generated.h"

UCLASS()
class SGA_TEAMPRJ_API ACharacter_Serath : public ADefaultCharacter
{
	GENERATED_BODY()
	
public:
	ACharacter_Serath();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;
};
