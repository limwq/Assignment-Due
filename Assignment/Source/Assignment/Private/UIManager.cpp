// Fill out your copyright notice in the Description page of Project Settings.


#include "UIManager.h"

void UUIManager::ShowHint(const FText& Hint)
{
    // Implementation will be in BP (you’ll bind this in UMG Graph)
}

void UUIManager::HideHint()
{
    // Implementation in BP
}

void UUIManager::ShowNote(UTexture2D* NoteImage)
{
    bIsNoteOpen = true;
    // Implementation in BP
}

void UUIManager::HideNote()
{
    bIsNoteOpen = false;
    // Implementation in BP
}

void UUIManager::ShowMessage(const FText& Message, float Duration)
{
    // Implementation in BP
}


