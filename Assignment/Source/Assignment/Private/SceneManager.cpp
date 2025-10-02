#include "SceneManager.h"
#include "MyGameInstance.h"

void USceneManager::OpenScene(UObject* WorldContext, const FString& SceneName)
{
    if (UWorld* World = WorldContext->GetWorld())
    {
        UGameplayStatics::OpenLevel(World, FName(*SceneName));
    }
}

void USceneManager::GoToFail(UObject* WorldContext)
{
    if (UWorld* World = WorldContext->GetWorld())
    {
        // Save current map
        if (UGameInstance* GI = World->GetGameInstance())
        {
            if (UMyGameInstance* MyGI = Cast<UMyGameInstance>(GI))
            {
                FString CurrentName = World->GetMapName();
                // Remove PIE prefix in editor
                if (CurrentName.StartsWith(World->StreamingLevelsPrefix))
                {
                    CurrentName.RemoveFromStart(World->StreamingLevelsPrefix);
                }
                MyGI->SaveLastScene(CurrentName);
            }
        }
        // Go to Fail scene
        UGameplayStatics::OpenLevel(World, TEXT("Fail"));
    }
}

void USceneManager::RetryLast(UObject* WorldContext)
{
    if (UWorld* World = WorldContext->GetWorld())
    {
        if (UGameInstance* GI = World->GetGameInstance())
        {
            if (UMyGameInstance* MyGI = Cast<UMyGameInstance>(GI))
            {
                FString LastScene = MyGI->GetLastScene();
                if (!LastScene.IsEmpty())
                {
                    UGameplayStatics::OpenLevel(World, FName(*LastScene));
                    return;
                }
            }
        }
        // fallback to MainMenu if no saved scene
        UGameplayStatics::OpenLevel(World, TEXT("MainMenu"));
    }
}
