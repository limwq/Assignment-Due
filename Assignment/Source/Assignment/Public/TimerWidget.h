#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TimerWidget.generated.h"

UCLASS()
class ASSIGNMENT_API UTimerWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    // Bind this to a TextBlock in the UMG designer (name it TimerText)
    UPROPERTY(meta = (BindWidget))
    class UTextBlock* TimerText;

    // Update display, in seconds
    UFUNCTION(BlueprintCallable, Category = "Timer")
    void UpdateTimerText(int32 RemainingSeconds);
};
