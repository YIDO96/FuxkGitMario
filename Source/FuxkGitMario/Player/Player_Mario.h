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

	void Finish();

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	USoundWave* FinishSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	USoundWave* StartSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	class UAudioComponent* Sounds;

	virtual void Jump() override;

	virtual void SetIsDeadCall(bool& value) override;
	virtual bool& GetIsDeadCall() override;
	
	bool FuckGitMario = true;
	bool IsFinsih = false;
private:

	// Ÿ�̸� �ڵ� �߰�
	FTimerHandle GameOverTimerHandle;

	// ���� ���� ȣ�� �Լ�
	void CallGameOver();

	UPROPERTY(VisibleAnywhere);
	bool bIsDead = false;

	UPROPERTY(VisibleAnywhere)
	float DeathAnimationDuration = 0.75f;

	float CurrentTime = 0;
	float CurrentTime2 = 0;

	bool IsStart = false;

	FVector FinishDir;
};
