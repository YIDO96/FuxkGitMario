#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "../Interface/MarioInterface.h"
#include "Player_Mario.generated.h"

UCLASS()
class FUXKGITMARIO_API APlayer_Mario : public ACharacter, public IMarioInterface
{
	GENERATED_BODY()

public:

	APlayer_Mario();

protected:

	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Horizontal(float AxisValue);

	virtual void Die() override;
	virtual void Jump()	override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class USpringArmComponent* SpringArmComp;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Sound")
	USoundWave* JumpSound;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Sound")
	USoundWave* DeadSound;
private:
	UPROPERTY(VisibleAnywhere);
	bool bIsDead = false;

	UPROPERTY(VisibleAnywhere)
	float DeathAnimationDuration = 1.5f;

	float CurrentTime = 0;
};
