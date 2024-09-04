// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/GunEnemy.h"

#include "PhysicsBullet.h"
#include "Kismet/GameplayStatics.h"


AGunEnemy::AGunEnemy()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AGunEnemy::BeginPlay()
{
	Super::BeginPlay();
}


void AGunEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CurrentTime += DeltaTime;
	if(CurrentTime >= FireRate)
	{
		Fire();
		CurrentTime = 0.0f;
	}
}

void AGunEnemy::Fire()
{
	APhysicsBullet* bullet = GetWorld()->SpawnActor<APhysicsBullet>(BulletFactory, GetActorLocation(), GetActorRotation());
	AActor* player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if(bullet && player)
	{
		FVector BulletVelocity = player->GetActorLocation() - GetActorLocation(); 
		FirePower = BulletVelocity.Size();
		bullet->SetCustomGravity(FVector(0.0f, 0.0f, -980.0f));
		bullet->SetMass(FirePower * 0.01f);
		bullet->AddVelocity(BulletVelocity * 0.5f + FVector(0, 0, FirePower));
	}
}
