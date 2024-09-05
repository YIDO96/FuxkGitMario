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

	void Start();

	virtual void Die() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UCameraComponent* Camera;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class USpringArmComponent* SpringArmComp;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<class UMaterialInstance*> CatMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* CatBody;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	USoundWave* JumpSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	USoundWave* DeadSound;

	virtual void Jump() override;

private:

	// 타이머 핸들 추가
	FTimerHandle GameOverTimerHandle;

	// 게임 오버 호출 함수
	void CallGameOver();

	UPROPERTY(VisibleAnywhere);
	bool bIsDead = false;

	UPROPERTY(VisibleAnywhere)
	float DeathAnimationDuration = 0.75f;

	float CurrentTime = 0;
	float CurrentTime2 = 0;
};
