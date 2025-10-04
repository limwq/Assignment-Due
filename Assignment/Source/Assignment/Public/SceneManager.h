#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SceneManager.generated.h"

UCLASS()
class ASSIGNMENT_API USceneManager : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "Scene")
    static void GoToLevel(UObject* WorldContext, FName LevelName);

    UFUNCTION(BlueprintCallable, Category = "Scene")
    static void GoToFail(UObject* WorldContext);

    UFUNCTION(BlueprintCallable, Category = "Scene")
    static void GoToVictory(UObject* WorldContext);

    UFUNCTION(BlueprintCallable, Category = "Scene")
    static void RetryLastLevel(UObject* WorldContext);

    UFUNCTION(BlueprintCallable, Category = "Scene")
    static void GoToMainMenu(UObject* WorldContext);
};
