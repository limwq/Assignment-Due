// BaseGameMode.cpp
#include "BaseGameMode.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

ABaseGameMode::ABaseGameMode()
{
    // Default values
    LevelTimeLimit = 300.0f;
    TimeRemaining = LevelTimeLimit;
}

void ABaseGameMode::BeginPlay()
{
    Super::BeginPlay();

    // Initialize remaining time
    TimeRemaining = LevelTimeLimit;

    // Create & add the timer widget if assigned
    if (TimerWidgetClass)
    {
        TimerWidget = CreateWidget<UUserWidget>(GetWorld(), TimerWidgetClass);
        if (TimerWidget)
        {
            TimerWidget->AddToViewport();
        }
    }

    // Start countdown ticking every 1 second
    GetWorldTimerManager().SetTimer(
        CountdownTimerHandle,
        this,
        &ABaseGameMode::HandleCountdown,
        1.0f,   // tick every 1 second
        true    // looping
    );
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
    // Default behavior: go to fail scene when timer ends
    GoToFailScene();
}

void ABaseGameMode::GoToLevel(FName LevelName)
{
    LastLevelName = LevelName;
    UGameplayStatics::OpenLevel(this, LevelName);
}

void ABaseGameMode::GoToFailScene()
{
    UGameplayStatics::OpenLevel(this, "FailScene");
}

void ABaseGameMode::GoToVictoryScene()
{
    UGameplayStatics::OpenLevel(this, "VictoryScene");
}
