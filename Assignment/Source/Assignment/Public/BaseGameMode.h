// BaseGameMode.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BaseGameMode.generated.h"

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
    float LevelTimeLimit = 300.0f; // Default: 5 minutes

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Timer")
    float TimeRemaining;

    FTimerHandle CountdownTimerHandle;

    // === UI ===
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
    TSubclassOf<class UUserWidget> TimerWidgetClass;

    UPROPERTY()
    class UUserWidget* TimerWidget;

    // === Scene ===
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GameMode")
    FName LastLevelName;

    // === Functions ===
    void HandleCountdown();

    UFUNCTION(BlueprintCallable, Category = "Timer")
    void OnTimerFinished();

public:
    // === Scene / Level transitions ===
    UFUNCTION(BlueprintCallable, Category = "GameMode")
    void GoToLevel(FName LevelName);

    UFUNCTION(BlueprintCallable, Category = "GameMode")
    void GoToFailScene();

    UFUNCTION(BlueprintCallable, Category = "GameMode")
    void GoToVictoryScene();

    // Getter for TimeRemaining (for UI)
    UFUNCTION(BlueprintCallable, Category = "Timer")
    float GetTimeRemaining() const { return TimeRemaining; }
};
