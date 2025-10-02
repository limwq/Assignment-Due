// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENT_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
    UPROPERTY(BlueprintReadWrite)
    FString LastSceneName;

    // Store the last scene (call this before opening Fail)
    UFUNCTION(BlueprintCallable)
    void SaveLastScene(const FString& SceneName);

    // Retrieve saved scene name
    UFUNCTION(BlueprintCallable)
    FString GetLastScene() const;
};
