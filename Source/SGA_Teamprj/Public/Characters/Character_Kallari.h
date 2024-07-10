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
	virtual void SetCamera() override;
	virtual void Attack() override;
	virtual void Skill_1() override;
	virtual void Skill_2() override;
	virtual void Skill_3() override;
	virtual void Skill_4() override;
};
