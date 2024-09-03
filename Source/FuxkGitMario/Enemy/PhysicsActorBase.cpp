// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/PhysicsActorBase.h"

#include "Components/SphereComponent.h"

// Sets default values
APhysicsActorBase::APhysicsActorBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Velocity = FVector::ZeroVector;
	Acceleration = FVector::ZeroVector;
	CustomGravity = FVector(0.0f, 0.0f, -980.0f);  //초기 중력값을 Z축 방향으로 설정 (단위: cm/s^2)

	SphereComp = CreateDefaultSubobject<USphereComponent>(FName("Sphere Collider"));
	SetRootComponent(SphereComp);
	SphereComp->SetSphereRadius(50.0f);
	SphereComp->SetCollisionProfileName(FName("Trap"));

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(FName("Static Mesh"));
	ConstructorHelpers::FObjectFinder<UStaticMesh>FindMesh(TEXT("/Script/Engine.StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	MeshComp->SetStaticMesh(FindMesh.Object);
	MeshComp->SetupAttachment(GetRootComponent());
	MeshComp->SetCollisionProfileName(FName("NoCollision"));
	
}

// Called when the game starts or when spawned
void APhysicsActorBase::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void APhysicsActorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ApplyCustomGravity();
	ApplyPhysics(DeltaTime);
}

void APhysicsActorBase::SetCustomGravity(FVector NewGravity)
{
	CustomGravity = NewGravity;
}

void APhysicsActorBase::SetCustomGravityTarget(AActor* Target)
{
	FVector Dir = Target->GetActorLocation() - GetActorLocation();
	CustomGravity = Dir.GetSafeNormal() * 980.0f;
}

void APhysicsActorBase::ApplyPhysics(float DeltaTime)
{
	//가속도 기반 속도 업데이트
	Velocity += Acceleration * DeltaTime;

	//속도 기반 위치 업데이트
	FVector newLocation = GetActorLocation() + Velocity * DeltaTime;
	SetActorLocation(newLocation);

	PrevTickVelocity = Velocity;
	Velocity = FVector::ZeroVector;
}

void APhysicsActorBase::ApplyCustomGravity()
{
	// 질량의 1/10배 * 중력 보다 현재 가속도가 크다면 추가 가속 제외
	// if(Acceleration.Length() < (Mass * 0.1f * CustomGravity).Length())
	// {
	// 	//Custom 중력 방향으로 기본 가속도 추가
	// }
	float CalcVelocityDirChange = FVector::DotProduct(PrevTickVelocity.GetSafeNormal(), CustomGravity.GetSafeNormal());
	UE_LOG(LogTemp, Warning, TEXT("Dot Result : %f"), CalcVelocityDirChange);
	Acceleration *= CalcVelocityDirChange;
	Acceleration += CustomGravity;
}