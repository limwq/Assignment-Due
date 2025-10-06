#include "SceneManager.h"
#include "Kismet/GameplayStatics.h"
#include "MyGameInstance.h"

void USceneManager::GoToLevel(UObject* WorldContext, FName LevelName)
{
    if (!WorldContext) return;

    UWorld* World = WorldContext->GetWorld();
    if (!World) return;

    FString MapName = World->GetMapName();
    MapName.RemoveFromStart(World->StreamingLevelsPrefix); // Removes UEDPIE_0_

    if (UMyGameInstance* GI = World->GetGameInstance<UMyGameInstance>())
    {
        // Save the CURRENT level (cleaned name)
        GI->SaveLastLevel(MapName);
    }

    UGameplayStatics::OpenLevel(WorldContext, LevelName);
}

void USceneManager::GoToFail(UObject* WorldContext)
{
    USceneManager::GoToLevel(WorldContext, "Fail");
}

void USceneManager::GoToVictory(UObject* WorldContext)
{
    USceneManager::GoToLevel(WorldContext, "Victory");
}

void USceneManager::RetryLastLevel(UObject* WorldContext)
{
    if (!WorldContext) return;

    UWorld* World = WorldContext->GetWorld();
    if (!World) return;

    if (UMyGameInstance* GI = World->GetGameInstance<UMyGameInstance>())
    {
        FString LastLevel = GI->GetLastLevel();

        if (!LastLevel.IsEmpty())
        {
            UE_LOG(LogTemp, Warning, TEXT("Retrying last level: %s"), *LastLevel);
            USceneManager::GoToLevel(WorldContext, FName(*LastLevel));
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("No last level saved!"));
        }
    }
}

void USceneManager::GoToMainMenu(UObject* WorldContext)
{
    USceneManager::GoToLevel(WorldContext, "MainMenu");
}
