// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "MenuActions.generated.h"

/**
 * 
 */
UCLASS()
class VRSERIOUSGAME_API UMenuActions : public UUserWidget
{
	GENERATED_BODY()
public:
	bool Initialize() override;

protected:
	//Widgets
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	UTextBlock* UserNameRequired;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	UButton* PlayBtn;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	UEditableTextBox* UserName;
	
private:
	UFUNCTION()
	void PlayBtnClicked();

	UFUNCTION()
	void UserNameEntered();
};
