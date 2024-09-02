// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include "Components/SphereComponent.h"
#include "Interface/MarioInterface.h"


// Sets default values
ABullet::ABullet()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulletMesh"));
	SetRootComponent(MeshComp);
	
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("BulletCollider"));
	SphereComp->SetupAttachment(MeshComp);
	SphereComp->SetSphereRadius(50.0f);
	
	ConstructorHelpers::FObjectFinder<UStaticMesh>InitMesh(TEXT("/Script/Engine.StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	MeshComp->SetStaticMesh(InitMesh.Object);
	
	MeshComp->SetCollisionProfileName(TEXT("NoCollision"));
	SphereComp->SetCollisionProfileName(TEXT("Trap"));
	SphereComp->SetGenerateOverlapEvents(true);
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	
	SphereComp->OnComponentBeginOverlap.AddDynamic(this, &ABullet::OnTrapSphereOverlap);
	// 타이머 설정, 반복 호출할 함수와 반복 간격 지정
	GetWorldTimerManager().SetTimer(BulletTimer, this, &ABullet::BulletCurve, 0.02f, true);
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABullet::SetTargetLocation(FVector TargetLoc)
{
	TargetLocation = TargetLoc;
}

void ABullet::OnTrapSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	IMarioInterface* Mario = Cast<IMarioInterface>(OtherActor);
	if(Mario)
	{
		Mario->Die();
		Destroy();
	}
}

void ABullet::BulletCurve()
{
	if(CurrentTime <= BulletFloatDuration)
	{
		//타이머 반복 간격 만큼 현재 시간 증가
		CurrentTime += GetWorldTimerManager().GetTimerRate(BulletTimer);
		//UE_LOG(LogTemp, Warning, TEXT("Current time : %f"), CurrentTime / BulletFloatDuration);

		//Bullet 포물선 이동 로직, 
		FVector newLocation = FVector(GetActorLocation().X, FMath::Lerp(GetActorLocation().Y, TargetLocation.Y, CurrentTime / BulletFloatDuration), FMath::Lerp(GetActorLocation().Z + BulletAmplitude * (0.5f - CurrentTime / BulletFloatDuration), TargetLocation.Z - 300.0f, CurrentTime / BulletFloatDuration));
		SetActorLocation(newLocation);
	}
	else
	{
		//타이머가 끝난 뒤 사망
		Destroy();
	}
}

