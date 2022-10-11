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

	FString GetQuestionTxt() { return QuestionTxt; }

	FString GetPossibleAnswers() { return PossibleAnswers; }

	FString GetReferenceTxt() { return ReferenceTxt; }

	int32 GetQuestionNum() { return QuestionNum; }

	int32 GetValue() { return Value; }

	bool GetIsMultipleChoice() { return bIsMultipleChoice; }

	QuestionAnswer GetAnswer() { return Answer; }

protected:
	int32 QuestionNum;

private:
	//Properties
	FString QuestionTxt;
	FString PossibleAnswers;
	FString ReferenceTxt;

	int32 Value;

	bool bIsMultipleChoice;
	QuestionAnswer Answer;
};
