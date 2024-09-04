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
	//Super::ActiveTrap(Player);

	FVector PlayerUpVector = Player->GetActorUpVector(); // Player의 UpVector가져오기
	FVector ImpactDir = GetActorLocation() - Player->GetActorLocation(); // Player -> Trap의 방향벡터
	ImpactDir.Normalize();

	float DotProduct = FVector::DotProduct(PlayerUpVector, ImpactDir); // (0,0,1) 벡터와 방향벡터의 내적값

	if(DotProduct > 0.5f)
	{
		FVector ForwardVector = Player->GetActorRightVector(); // Player의 앞방향 벡터
		float Angle = FMath::Acos(FVector::DotProduct(ImpactDir, ForwardVector)); // (0,1,0) 벡터와 방향벡터의 내적값 ACos의 Radian값

		float AngleDegrees = FMath::RadiansToDegrees(Angle); // Radian을 degree값으로 변경
		if(AngleDegrees >= 15.0f) // 플레이어 앞방향과 방향벡터의 사이각이 15도 이상이면 (옆에서 오버랩이 된게 아니라면..?)
		{                                                                         
			// Trap Activation
			//BoxComp->SetCollisionResponseToChannel(ECC_EngineTraceChannel1, ECR_Block);
			//MeshComp->SetCollisionResponseToAllChannels(ECR_Block); //Collision Block으로 변경
			//MeshComp->SetCollisionObjectType(ECC_EngineTraceChannel3); //Collision 프로필 Platform으로 변경
			MeshComp->SetCollisionProfileName("Platform");
			MeshComp->SetMaterial(0, ExposeMat); // Material 변경
		}
	}
}
void ATrap_Block::OnTrapMeshOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//Super::OnTrapMeshOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
}
