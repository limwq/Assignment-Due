#include "MyGameInstance.h"

void UMyGameInstance::SaveLastLevel(const FString& LevelName)
{
    LastLevelName = LevelName;
    UE_LOG(LogTemp, Warning, TEXT("GameInstance: Saved last level: %s"), *LastLevelName);
}

FString UMyGameInstance::GetLastLevel() const
{
    return LastLevelName;
}
