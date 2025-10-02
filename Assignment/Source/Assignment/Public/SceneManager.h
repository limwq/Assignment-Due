// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "SceneManager.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENT_API USceneManager : public UGameplayStatics
{
	GENERATED_BODY()
	
public:
    // Open a new scene
    UFUNCTION(BlueprintCallable, Category = "Scene")
    static void OpenScene(UObject* WorldContext, const FString& SceneName);

    // Save current and go to Fail
    UFUNCTION(BlueprintCallable, Category = "Scene")
    static void GoToFail(UObject* WorldContext);

    // Return to last saved scene
    UFUNCTION(BlueprintCallable, Category = "Scene")
    static void RetryLast(UObject* WorldContext);
};
