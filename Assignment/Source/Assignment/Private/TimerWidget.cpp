#include "TimerWidget.h"
#include "Components/TextBlock.h"

void UTimerWidget::UpdateTimerText(int32 RemainingSeconds)
{
    if (!TimerText) return;
    int32 Minutes = RemainingSeconds / 60;
    int32 Seconds = RemainingSeconds % 60;
    const FString TimeStr = FString::Printf(TEXT("%02d:%02d"), Minutes, Seconds);
    TimerText->SetText(FText::FromString(TimeStr));
}
