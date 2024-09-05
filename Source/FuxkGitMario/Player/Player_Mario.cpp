#include "Player_Mario.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Interface/GameModeInterface.h"
#include "GameFramework/GameModeBase.h"

APlayer_Mario::APlayer_Mario()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->TargetArmLength = 1000.0f;
	SpringArmComp->bUsePawnControlRotation = false;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;
	// 임시용으로 카메라 Orthographic로 변경하고 시야 4000으로 변경 -> 이후 카메라를 분리된 객체로 관리 예정
	Camera->ProjectionMode = ECameraProjectionMode::Orthographic;
	Camera->OrthoWidth = 4000.0f;

	bUseControllerRotationYaw = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
}

void APlayer_Mario::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayer_Mario::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if(bIsDead) //뒈짖 확인
	{
		CurrentTime += DeltaTime;
		if (CurrentTime < DeathAnimationDuration)//0.75초 동안 가만히
		{
			GetWorld()->GetFirstPlayerController()->SetIgnoreMoveInput(true); //플레이어 입력 무시
			GetCharacterMovement()->Velocity = FVector(0.0f); //움직임(속력) 0으로 고정(애니메이션 좌우 움직임 없도록)

		}
		else if (CurrentTime < DeathAnimationDuration * 3) // 1.5초 동안 사망애니메이션
		{
			GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECR_Ignore); //Collision 끔
			FVector newLocation = GetActorLocation() + GetActorUpVector() * DeltaTime * GetCharacterMovement()->JumpZVelocity;
			SetActorLocation(newLocation);
		}
		else // 2.25초지나면 Gameover호출
		{
			CallGameOver();
			bIsDead = false;

			// 딜레이를 준 후에 게임 오버 호출
			//if (!GetWorld()) return;

			// 타이머 설정 (2초 지연)
			//GetWorld()->GetTimerManager().SetTimer(GameOverTimerHandle, this, &APlayer_Mario::CallGameOver, 0.0f, false,2);
			
		}
	}
}

void APlayer_Mario::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("Horizontal"), this, &APlayer_Mario::Horizontal);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &APlayer_Mario::Jump);	
}

void APlayer_Mario::Horizontal(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

void APlayer_Mario::Die()
{
	UE_LOG(LogTemp, Warning, TEXT("Call Player_Mario Die Function"));
	//GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeUIOnly());
	
	bIsDead = true; // 뒈짖
}

void APlayer_Mario::CallGameOver()
{
	UE_LOG(LogTemp, Warning, TEXT("GameOver called"));
	if (AGameModeBase* GameModeBase = GetWorld()->GetAuthGameMode())
	{
		UE_LOG(LogTemp, Warning, TEXT("GameModeBase GameOver called from Player_Mario."));
		if (IGameModeInterface* GameMode = Cast<IGameModeInterface>(GameModeBase))
		{
			GameMode->GameOver();
			UE_LOG(LogTemp, Warning, TEXT("GameOver called from Player_Mario."));
		}
	}
}