// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "StartWidget.generated.h"

UCLASS()
class FUXKGITMARIO_API UStartWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct();

	UPROPERTY(meta = (BindWidget))
	class UCanvasPanel* StartCanvas;

	UPROPERTY(meta = (BindWidget))
	class UButton* btn_GameStart;

	UFUNCTION()
	void OnGameStartBtnClicked();
};
