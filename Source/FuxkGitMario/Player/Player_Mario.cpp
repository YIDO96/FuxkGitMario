#include "Player_Mario.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

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
		if(CurrentTime <= DeathAnimationDuration) //뒈짖 애니메이션 지속시간 확인
		{
			//점프력 만큼 UpVector 방향으로 애니메이션 재생
			FVector newLocation = GetActorLocation() + GetActorUpVector() * DeltaTime * GetCharacterMovement()->JumpZVelocity;
			SetActorLocation(newLocation);
			CurrentTime += DeltaTime;
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
	GetWorld()->GetFirstPlayerController()->SetIgnoreMoveInput(true); //플레이어 입력 무시
	GetCharacterMovement()->Velocity = FVector(0.0f); //움직임(속력) 0으로 고정(애니메이션 좌우 움직임 없도록)
	GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECR_Ignore); //Collision 끔
	bIsDead = true; // 뒈짖
}