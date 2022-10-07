// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/WidgetComponent.h"
#include "MenuActions.h"
#include "MainMenu.generated.h"

UCLASS()
class VRSERIOUSGAME_API AMainMenu : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMainMenu();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:	
	// Components
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	UWidgetComponent* MenuActions;
};
