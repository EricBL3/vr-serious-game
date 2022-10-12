// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Question.generated.h"

UENUM(BlueprintType)
enum QuestionAnswer
{
	Yes,
	No,
	A,
	B,
	C,
	D
};

/**
 * 
 */
UCLASS()
class VRSERIOUSGAME_API UQuestion : public UObject
{
	GENERATED_BODY()
public:

	void SetupQuestion(int32 num);
	int32 CalculateX();
	int32 CalculateY();

	UFUNCTION(BlueprintCallable)
	FString GetQuestionTxt() { return QuestionTxt; }

	UFUNCTION(BlueprintCallable)
	FString GetPossibleAnswers() { return PossibleAnswers; }

	UFUNCTION(BlueprintCallable)
	FString GetReferenceTxt() { return ReferenceTxt; }

	UFUNCTION(BlueprintCallable)
	int32 GetQuestionNum() { return QuestionNum; }

	UFUNCTION(BlueprintCallable)
	int32 GetValue() { return Value; }

	UFUNCTION(BlueprintCallable)
	bool GetIsMultipleChoice() { return bIsMultipleChoice; }

	UFUNCTION(BlueprintCallable)
	bool GetQuestionIsAnswered() { return bQuestionIsAnswered; }

	UFUNCTION(BlueprintCallable)
	void SetQuestionIsAnswered(bool isAnswered) { bQuestionIsAnswered = isAnswered; }

	UFUNCTION(BlueprintCallable)
	bool GetUserAnsweredCorrectly() { return bUserAnsweredCorrectly; }

	UFUNCTION(BlueprintCallable)
	void SetUserAnsweredCorrectly(bool val) { bUserAnsweredCorrectly = val; }

	UFUNCTION(BlueprintCallable)
	QuestionAnswer GetAnswer() { return Answer; }

	UFUNCTION(BlueprintCallable)
	QuestionAnswer GetUserAnswer() { return UserAnswer; }

	UFUNCTION(BlueprintCallable)
	void SetUserAnswer(QuestionAnswer answer) { UserAnswer = answer; }

protected:
	int32 QuestionNum;

private:
	//Properties
	FString QuestionTxt;
	FString PossibleAnswers;
	FString ReferenceTxt;

	int32 Value;

	bool bIsMultipleChoice;
	bool bQuestionIsAnswered;
	bool bUserAnsweredCorrectly;
	QuestionAnswer Answer;
	QuestionAnswer UserAnswer;
};
