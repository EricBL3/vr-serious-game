// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "MiniMapImageUI.generated.h"

/**
 * 
 */
UCLASS()
class VRSERIOUSGAME_API UMiniMapImageUI : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	UImage* MiniMapImage;
	
};
