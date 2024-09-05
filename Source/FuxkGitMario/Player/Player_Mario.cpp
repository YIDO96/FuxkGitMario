#include "Player_Mario.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Interface/GameModeInterface.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/GameModeBase.h"
#include "Components/AudioComponent.h"


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

	CatBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CatBody"));
	CatBody->SetupAttachment(GetRootComponent());
	ConstructorHelpers::FObjectFinder<UStaticMesh>InitMesh(TEXT("/Script/Engine.StaticMesh'/Game/Meshes/Cat.Cat'"));
	CatBody->SetStaticMesh(InitMesh.Object);
	CatBody->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.7f));

	Sounds = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComp"));
	Sounds->bAutoActivate = false;

}

void APlayer_Mario::BeginPlay()
{
	Super::BeginPlay();

	if (Sounds && StartSound) 
	{
		Sounds->SetSound(StartSound); // 사운드 큐 설정
		if (!Sounds->IsPlaying()) // 이미 재생 중이 아니라면
		{
			Sounds->Play(); // 사운드 재생
		}
	}
}

void APlayer_Mario::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//UE_LOG(LogTemp, Warning, TEXT("IsDeadCall : %d"), FuckGitMario);
	if (IsFinsih)
	{

		if (GetActorLocation().Z < 100)
		{
			FinishDir = GetActorRightVector();
		}
		else
		{
			FinishDir = FVector::DownVector;
		}
		FVector newLocation = GetActorLocation() + FinishDir * DeltaTime * 100;
		SetActorLocation(newLocation);
	}


	if(bIsDead) //뒈짖 확인
	{
		CurrentTime += DeltaTime;
		if (CurrentTime < DeathAnimationDuration)//0.75초 동안 가만히
		{
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
			bIsDead = false;
			CurrentTime = 0;
			CallGameOver();
			//FuckGitMario = false;
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
	PlayerInputComponent->BindAction(TEXT("Start"), IE_Pressed, this, &APlayer_Mario::Start);
}

void APlayer_Mario::Horizontal(float AxisValue)
{

	//UE_LOG(LogTemp, Warning, TEXT("Horizontal"));
	//UE_LOG(LogTemp, Warning, TEXT("AxisValue : %.2f"), AxisValue);
	if ((not CanJump() || AxisValue != 0) && not bIsDead)
	{
		CatBody->SetMaterial(0, CatMaterial[1]);
	}
	else if (not bIsDead)
	{
		CatBody->SetMaterial(0, CatMaterial[0]);
	}


	AddMovementInput(GetActorRightVector() * AxisValue);
}

void APlayer_Mario::Start()
{
	UE_LOG(LogTemp, Warning, TEXT("Enter"));
	IGameModeInterface* GameMode = Cast<IGameModeInterface>(UGameplayStatics::GetGameMode(GetWorld()));
	if (GameMode)
	{
		UE_LOG(LogTemp, Warning, TEXT("Start Input"));
		IsStart = true;
		GameMode->StartGame();
	}
	//Sounds->Play();
	//UGameplayStatics::PlaySound2D(this, StartSound);
}

void APlayer_Mario::Finish()
{
	IsFinsih = true;
	GetCharacterMovement()->Velocity = FVector(0.0f);
	GetWorld()->GetFirstPlayerController()->SetIgnoreMoveInput(true); //플레이어 입력 무시
	//Sounds->Stop();
	if (Sounds && Sounds->IsPlaying())
	{
		Sounds->Stop(); // 사운드 정지
	}
	UGameplayStatics::PlaySound2D(this, FinishSound);
	auto movementComp = Cast<UCharacterMovementComponent>(GetMovementComponent());
	if (movementComp)
	{
		movementComp->GravityScale = 0;
	}

	//GetMovementComponent()->GetGravityZ();
}

void APlayer_Mario::Die()
{
	//UGameplayStatics::StopSound(GetWorld(), SoundToStop, Location);

	if (Sounds && Sounds->IsPlaying())
	{
		Sounds->Stop(); // 사운드 정지
	}
	if (FuckGitMario)
	{
		UGameplayStatics::PlaySound2D(this, DeadSound);
		FuckGitMario = false;
	}

	UE_LOG(LogTemp, Warning, TEXT("Call Player_Mario Die Function"));
	//GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeUIOnly());
	GetWorld()->GetFirstPlayerController()->SetIgnoreMoveInput(true); //플레이어 입력 무시
	CatBody->SetMaterial(0, CatMaterial[2]);

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

void APlayer_Mario::Jump()
{
	if(not IsStart)
	{
		return;
	}
	Super::Jump();
	if (FuckGitMario == false and CanJump())
	{
		UGameplayStatics::PlaySound2D(this, JumpSound);
	}
}

void APlayer_Mario::SetIsDeadCall(bool& value)
{
	FuckGitMario = value;
}

bool& APlayer_Mario::GetIsDeadCall()
{
	return FuckGitMario;
}