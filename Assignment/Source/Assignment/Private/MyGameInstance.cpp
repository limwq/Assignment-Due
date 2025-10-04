#include "MyGameInstance.h"
#include "Blueprint/UserWidget.h"

void UMyGameInstance::SaveLastLevel(const FName& LevelName)
{
    LastLevelName = LevelName;
}

FName UMyGameInstance::GetLastLevel() const
{
    return LastLevelName;
}

void UMyGameInstance::Init()
{
    Super::Init();

    // Create the scene fader widget if assigned
    if (SceneFaderClass)
    {
        SceneFader = CreateWidget<UUserWidget>(this, SceneFaderClass);
        if (SceneFader)
        {
            SceneFader->AddToViewport(100); // high ZOrder so it overlays everything
        }
    }
}
