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

	//속도 초기화
	//Velocity = FVector::ZeroVector;
}

void APhysicsActorBase::ApplyCustomGravity()
{
	//가속도 추가
	Acceleration += CustomGravity;
	//최대 가속도 설정 (질량 * 0.1 * Custom중력 Vector의 크기)
	float MaxAcceleration = Mass * 0.1f * CustomGravity.Size();
	UE_LOG(LogTemp, Warning, TEXT("CustomGravity X : %.2f, CustomGravity Y : %.2f, CustomGravity Z : %.2f"), CustomGravity.X, CustomGravity.Y, CustomGravity.Z);
	//가속력 Vector의 크기가 최대 가속력보다 크다면
	if(Acceleration.Size() > MaxAcceleration)
	{
		Acceleration = Acceleration.GetSafeNormal() * MaxAcceleration;
	}
}