// Fill out your copyright notice in the Description page of Project Settings.


#include "StartWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "Components/CanvasPanel.h"

void UStartWidget::NativeConstruct()
{
    Super::NativeConstruct();

    btn_GameStart->OnClicked.AddDynamic(this, &UStartWidget::OnGameStartBtnClicked);
}

void UStartWidget::OnGameStartBtnClicked()
{
    StartCanvas->SetVisibility(ESlateVisibility::Hidden);

    GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeGameOnly());

    GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(false);
}