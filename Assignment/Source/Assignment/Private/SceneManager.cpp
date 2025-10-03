#include "SceneManager.h"
#include "Kismet/GameplayStatics.h"
#include "MyGameInstance.h"

void USceneManager::GoToLevel(UObject* WorldContext, FName LevelName)
{
    if (!WorldContext) return;

    if (UMyGameInstance* GI = WorldContext->GetWorld()->GetGameInstance<UMyGameInstance>())
    {
        GI->SaveLastLevel(LevelName);
    }

    UGameplayStatics::OpenLevel(WorldContext, LevelName);
}

void USceneManager::GoToFail(UObject* WorldContext)
{
    USceneManager::GoToLevel(WorldContext, "FailScene");
}

void USceneManager::GoToVictory(UObject* WorldContext)
{
    USceneManager::GoToLevel(WorldContext, "VictoryScene");
}

void USceneManager::RetryLastLevel(UObject* WorldContext)
{
    if (!WorldContext) return;

    if (UMyGameInstance* GI = WorldContext->GetWorld()->GetGameInstance<UMyGameInstance>())
    {
        if (!GI->LastLevelName.IsNone())
        {
            USceneManager::GoToLevel(WorldContext, GI->LastLevelName);
        }
    }
}

void USceneManager::GoToMainMenu(UObject* WorldContext)
{
    USceneManager::GoToLevel(WorldContext, "MainMenu");
}

