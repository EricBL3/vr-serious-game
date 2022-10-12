// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/WidgetComponent.h"
#include "ChooseQuestion.h"
#include "QuestionUI.h"
#include "../../Question.h"
#include "Engine/Texture2D.h"
#include "MainGame.generated.h"

UCLASS()
class VRSERIOUSGAME_API AMainGame : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMainGame();

	UFUNCTION(BlueprintCallable)
	void LoadQuestion(int32 num);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Components
	UPROPERTY(VisibleAnywhere, BlueprintReadonly)
		UWidgetComponent* ChooseQuestions;

	UPROPERTY(VisibleAnywhere, BlueprintReadonly)
		UWidgetComponent* QuestionUI;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		TArray<FVector> QuestionLocations;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		TArray<FVector> QuestionRotations;

private:
	// Components
	UPROPERTY(VisibleAnywhere)
		USceneComponent* Root;

	//State
	TArray<UQuestion*> Questions;

	UPROPERTY(EditDefaultsOnly)
	TArray<UTexture2D*> MiniMapImages;

	UPROPERTY(EditDefaultsOnly)
	TArray<UTexture2D*> ReferenceImages;


	//Functions
	void CreateQuestion(int32 num);

};
