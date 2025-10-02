#include "MyGameInstance.h"

void UMyGameInstance::SaveLastScene(const FString& SceneName)
{
    LastSceneName = SceneName;
}

FString UMyGameInstance::GetLastScene() const
{
    return LastSceneName;
}
