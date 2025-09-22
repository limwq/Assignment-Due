// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UIManager.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENT_API UUIManager : public UUserWidget
{
	GENERATED_BODY()

public:
    // For hints ("Press F to Open")
    UFUNCTION(BlueprintCallable, Category = "UI")
    void ShowHint(const FText& Hint);

    UFUNCTION(BlueprintCallable, Category = "UI")
    void HideHint();

    // For notes
    UFUNCTION(BlueprintCallable, Category = "UI")
    void ShowNote(class UTexture2D* NoteImage);

    UFUNCTION(BlueprintCallable, Category = "UI")
    void HideNote();

    // For temporary messages ("Use the key to open doors")
    UFUNCTION(BlueprintCallable, Category = "UI")
    void ShowMessage(const FText& Message, float Duration);

    // To check if note UI is currently open
    UFUNCTION(BlueprintCallable, Category = "UI")
    bool IsNoteOpen() const { return bIsNoteOpen; }

private:
    bool bIsNoteOpen = false;
	
};
