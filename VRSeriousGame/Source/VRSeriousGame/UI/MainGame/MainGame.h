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

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateTimerTxt();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Components
	UPROPERTY(VisibleAnywhere, BlueprintReadonly)
		UWidgetComponent* ChooseQuestions;

	UPROPERTY(VisibleAnywhere, BlueprintReadonly)
		UWidgetComponent* QuestionUI;

	//State
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		TArray<FVector> QuestionLocations;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		TArray<FVector> QuestionRotations;

	UPROPERTY(BlueprintReadOnly)
		TArray<UQuestion*> Questions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		TArray<UTexture2D*> MiniMapImages;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		TArray<UTexture2D*> ReferenceImages;

	UPROPERTY(BlueprintReadOnly)
	int32 CurrentScore;

	UPROPERTY(BlueprintReadOnly)
	int32 TotalScore;

	UPROPERTY(BlueprintReadOnly)
	FString CurrentTimeTxt;

	//Functions
	UFUNCTION(BlueprintCallable)
	void AddScore(int32 val) { CurrentScore += val; }

private:
	// Components
	UPROPERTY(VisibleAnywhere)
		USceneComponent* Root;

	//State
	FTimerHandle MemberTimerHandle;
	int32 CurrentSeconds;
	int32 CurrentMinutes;

	//Functions
	void CreateQuestion(int32 num);
	void UpdateTimer();

};
