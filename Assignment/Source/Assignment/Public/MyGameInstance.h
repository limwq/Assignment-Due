#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

UCLASS()
class ASSIGNMENT_API UMyGameInstance : public UGameInstance
{
    GENERATED_BODY()

public:
    // Last level stored as FString (safer between loads)
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Scene")
    FString LastLevelName;

    UFUNCTION(BlueprintCallable, Category = "Scene")
    void SaveLastLevel(const FString& LevelName);

    UFUNCTION(BlueprintCallable, Category = "Scene")
    FString GetLastLevel() const;
};
