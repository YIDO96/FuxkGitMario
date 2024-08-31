// Fill out your copyright notice in the Description page of Project Settings.


#include "Trap_Block.h"

#include "Components/BoxComponent.h"

void ATrap_Block::BeginPlay()
{
	Super::BeginPlay();
}

void ATrap_Block::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATrap_Block::ActiveTrap(AActor* Player)
{
	Super::ActiveTrap(Player);
	UE_LOG(LogTemp, Warning, TEXT("Trap Block Active Trap"));
	FVector PlayerUpVector = Player->GetActorUpVector(); // Player의 UpVector가져오기
	FVector ImpactDir = GetActorLocation() - Player->GetActorLocation(); // Player -> Trap의 방향벡터
	ImpactDir.Normalize();

	float DotProduct = FVector::DotProduct(PlayerUpVector, ImpactDir); // (0,0,1) 벡터와 방향벡터의 내적값
	//UE_LOG(LogTemp, Warning, TEXT("DotProduct_PlayerUpVector-ImpactDir : %.2f"), DotProduct);

	if(DotProduct > 0.5f)
	{
		UE_LOG(LogTemp, Warning, TEXT("Success DotProduct > 0.5f"));
		//FVector ForwardVector = Player->GetActorForwardVector(); // Player의 앞방향 벡터
		FVector ForwardVector = Player->GetActorRightVector(); // Player의 앞방향 벡터
		//float DotProduct11 = FVector::DotProduct(ImpactDir, ForwardVector);
		float Angle = FMath::Acos(FVector::DotProduct(ImpactDir, ForwardVector)); // (0,1,0) 벡터와 방향벡터의 내적값 ACos의 Radian값
		//UE_LOG(LogTemp, Warning, TEXT("Player's ForwardVector x : %.2f, y : %.2f, z : %.2f"), ForwardVector.X, ForwardVector.Y, ForwardVector.Z);
		//UE_LOG(LogTemp, Warning, TEXT("DotProduct11_ImpactDir-ForwardVector : %.2f"), DotProduct11);
		//UE_LOG(LogTemp, Warning, TEXT("Angle_ImpactDir-ForwardVector : %.2f"), Angle);

		float AngleDegrees = FMath::RadiansToDegrees(Angle); // Radian을 degree값으로 변경
		//UE_LOG(LogTemp, Warning, TEXT("AngleDegrees : %.2f"), AngleDegrees);
		if(AngleDegrees >= 15.0f) // 플레이어 앞방향과 방향벡터의 사이각이 15도 이상이면 (옆에서 오버랩이 된게 아니라면..?)
		{
			// Trap Activation
			UE_LOG(LogTemp, Warning, TEXT("Success AngleDegree <= 15.0f"));
			BoxComp->SetCollisionResponseToChannel(ECC_EngineTraceChannel1, ECR_Block); // CollisionChannel을 Block으로 변경
			MeshComp->SetMaterial(0, ExposeMat); // Material 변경
		}
	}
}

