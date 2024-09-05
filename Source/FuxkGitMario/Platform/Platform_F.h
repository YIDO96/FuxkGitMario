// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Platform/PlatformBase.h"
#include "Platform_F.generated.h"

UENUM(BlueprintType)
enum class EPlatformType : uint8
{
	Platform_Default,
	Platform_F UMETA(DisplayName = "F"),
	Platform_U UMETA(DisplayName = "U"),
	Platform_X UMETA(DisplayName = "X"),
	Platform_K UMETA(DisplayName = "K"),
	Platform_G UMETA(DisplayName = "G"),
	Platform_I UMETA(DisplayName = "I"),
	Platform_T UMETA(DisplayName = "T"),
	Platform_M UMETA(DisplayName = "M"),
	Platform_A UMETA(DisplayName = "A"),
	Platform_R UMETA(DisplayName = "R"),
	Platform_O UMETA(DisplayName = "O"),
};

UCLASS()
class FUXKGITMARIO_API APlatform_F : public APlatformBase
{
	GENERATED_BODY()

public:
	APlatform_F();
	
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere)
	EPlatformType PlatformType = EPlatformType::Platform_Default;

	UPROPERTY(EditAnywhere)
	TMap<FString, class UStaticMesh*> PlatformMeshes;

	UPROPERTY(EditAnywhere)
	FString PlatformName = "Default";

	
	void Platform_F();
	void Platform_U();
	void Platform_X();
	void Platform_K();
	void Platform_G();
	void Platform_I();
	void Platform_T();
	void Platform_M();
	void Platform_A();
	void Platform_R();
	void Platform_O();
};
