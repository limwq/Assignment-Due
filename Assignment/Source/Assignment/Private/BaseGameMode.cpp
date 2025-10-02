// BaseGameMode.cpp
#include "BaseGameMode.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "SceneManager.h"

ABaseGameMode::ABaseGameMode()
{
    LevelTimeLimit = 300.0f;
    TimeRemaining = LevelTimeLimit;
    TimerCondition = ETimerCondition::LoseOnTimeout; // default rule
}

void ABaseGameMode::BeginPlay()
{
    Super::BeginPlay();

    // Reset time
    TimeRemaining = LevelTimeLimit;

    // Create timer UI
    if (TimerWidgetClass)
    {
        TimerWidget = CreateWidget<UUserWidget>(GetWorld(), TimerWidgetClass);
        if (TimerWidget)
        {
            TimerWidget->AddToViewport();
        }
    }

    // Start countdown
    GetWorldTimerManager().SetTimer(
        CountdownTimerHandle,
        this,
        &ABaseGameMode::HandleCountdown,
        1.0f,
        true
    );

    // Lock input to game
    APlayerController* PC = GetWorld()->GetFirstPlayerController();
    if (PC)
    {
        FInputModeGameOnly InputMode;
        PC->SetInputMode(InputMode);
        PC->bShowMouseCursor = false;
    }
}

void ABaseGameMode::HandleCountdown()
{
    if (TimeRemaining > 0)
    {
        TimeRemaining--;
    }
    else
    {
        GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
        OnTimerFinished();
    }
}

void ABaseGameMode::OnTimerFinished()
{
    if (TimerCondition == ETimerCondition::LoseOnTimeout)
    {
        GoToFailScene();
    }
    else if (TimerCondition == ETimerCondition::WinOnTimeout)
    {
        GoToVictoryScene();
    }
}

void ABaseGameMode::GoToLevel(FName LevelName)
{
    UGameplayStatics::OpenLevel(this, LevelName);
}

void ABaseGameMode::GoToFailScene()
{
    USceneManager::GoToFail(this);
}

void ABaseGameMode::GoToVictoryScene()
{
    UGameplayStatics::OpenLevel(this, "VictoryScene");
}
