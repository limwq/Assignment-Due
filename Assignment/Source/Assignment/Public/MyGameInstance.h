#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

UCLASS()
class ASSIGNMENT_API UMyGameInstance : public UGameInstance
{
    GENERATED_BODY()

public:
    // Store last level visited (for Retry button)
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Scene")
    FName LastLevelName;

    // Reference to Scene Fader widget
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Scene")
    class UUserWidget* SceneFader;

    // Scene fader widget class (set in BP defaults)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scene")
    TSubclassOf<class UUserWidget> SceneFaderClass;

    // Save the last level name
    UFUNCTION(BlueprintCallable, Category = "Scene")
    void SaveLastLevel(const FName& LevelName);

    // Get the last level name
    UFUNCTION(BlueprintCallable, Category = "Scene")
    FName GetLastLevel() const;

protected:
    virtual void Init() override;
};
