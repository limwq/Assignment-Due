// BaseGameMode.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BaseGameMode.generated.h"

// === Timer rule ===
UENUM(BlueprintType)
enum class ETimerCondition : uint8
{
    LoseOnTimeout UMETA(DisplayName = "Lose On Timeout"),
    WinOnTimeout  UMETA(DisplayName = "Win On Timeout")
};

UCLASS()
class ASSIGNMENT_API ABaseGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    ABaseGameMode();

protected:
    virtual void BeginPlay() override;

    // === Timer ===
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Timer")
    float LevelTimeLimit = 300.0f; // default 5 min

    UPROPERTY(BlueprintReadOnly, Category = "Timer")
    float TimeRemaining;

    FTimerHandle CountdownTimerHandle;

    // Win/Lose condition
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Timer")
    ETimerCondition TimerCondition;

    // === UI ===
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
    TSubclassOf<class UUserWidget> TimerWidgetClass;

    UPROPERTY()
    class UUserWidget* TimerWidget;

    // === Functions ===
    void HandleCountdown();

    UFUNCTION(BlueprintCallable, Category = "GameMode")
    virtual void OnTimerFinished();

public:
    // === Scene / Level transitions ===
    UFUNCTION(BlueprintCallable, Category = "GameMode")
    void GoToLevel(FName LevelName);

    UFUNCTION(BlueprintCallable, Category = "GameMode")
    void GoToFailScene();

    UFUNCTION(BlueprintCallable, Category = "GameMode")
    void GoToVictoryScene();

    UFUNCTION(BlueprintPure, Category = "Timer")
    float GetTimeRemaining() const { return TimeRemaining; }
};
