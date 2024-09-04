// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/PhysicsBullet.h"

#include "Components/SphereComponent.h"
#include "Interface/MarioInterface.h"

APhysicsBullet::APhysicsBullet()
{
	PrimaryActorTick.bCanEverTick = true;

	MeshComp->SetWorldScale3D(FVector(0.8f));
	SphereComp->SetSphereRadius(40.0f);
	
}

void APhysicsBullet::BeginPlay()
{
	Super::BeginPlay();

	SphereComp->OnComponentBeginOverlap.AddDynamic(this, &APhysicsBullet::OnBulletOverlap);
}

void APhysicsBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APhysicsBullet::OnBulletOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	IMarioInterface* Mario = Cast<IMarioInterface>(OtherActor);
	if (Mario)
	{
		Mario->Die();
	}
}
