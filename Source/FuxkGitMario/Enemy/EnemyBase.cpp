// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBase.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Player/Player_Mario.h"


// Sets default values
AEnemyBase::AEnemyBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulletMesh"));
	SetRootComponent(MeshComp);
	
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("BulletCollider"));
	SphereComp->SetupAttachment(MeshComp);
	SphereComp->SetSphereRadius(500.0f);
	
	ConstructorHelpers::FObjectFinder<UStaticMesh>InitMesh(TEXT("/Script/Engine.StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	MeshComp->SetStaticMesh(InitMesh.Object);
	
	MeshComp->SetCollisionProfileName(TEXT("Trap"));
	MeshComp->SetGenerateOverlapEvents(true);
	SphereComp->SetCollisionProfileName(TEXT("Trap"));
	SphereComp->SetGenerateOverlapEvents(true);
}

// Called when the game starts or when spawned
void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();

	SphereComp->OnComponentBeginOverlap.AddDynamic(this, &AEnemyBase::OnTrapSphereOverlap);
	SphereComp->OnComponentEndOverlap.AddDynamic(this, &AEnemyBase::OnEndSphereOverlap);
	MeshComp->OnComponentBeginOverlap.AddDynamic(this, &AEnemyBase::OnMeshOverlap);
	
}

// Called every frame
void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void AEnemyBase::OnTrapSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	IMarioInterface* Mario = Cast<IMarioInterface>(OtherActor);
	if(Mario)
	{
		bIsEnemyActive = true;
	}
}

void AEnemyBase::OnMeshOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	IMarioInterface* Mario = Cast<IMarioInterface>(OtherActor);
	if(Mario)
	{
		Mario->Die();
	}
}

void AEnemyBase::OnEndSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	IMarioInterface* Mario = Cast<IMarioInterface>(OtherActor);
	if(Mario)
	{
		bIsEnemyActive = false;
	}
}

void AEnemyBase::Fire()
{
	
}

