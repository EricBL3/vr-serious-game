// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGame.h"

// Sets default values
AMainGame::AMainGame()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	ChooseQuestions = CreateDefaultSubobject<UWidgetComponent>(TEXT("ChooseQuestions"));
	ChooseQuestions->SetupAttachment(GetRootComponent());

	QuestionUI = CreateDefaultSubobject<UWidgetComponent>(TEXT("QuestionUI"));
	QuestionUI->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void AMainGame::BeginPlay()
{
	Super::BeginPlay();

	Questions.Empty();

	for (int32 i = 1; i <= 10; i++)
	{
		CreateQuestion(i);
	}
	
}

void AMainGame::CreateQuestion(int32 num)
{
	UQuestion* NewQuestion = NewObject<UQuestion>(this, UQuestion::StaticClass(), FName("UQuestion"));
	Questions.Add(NewQuestion);
}

void AMainGame::LoadQuestion(int32 num)
{
	ChooseQuestions->GetUserWidgetObject()->SetIsEnabled(false);
	ChooseQuestions->GetUserWidgetObject()->SetVisibility(ESlateVisibility::Hidden);

	UQuestionUI* Question = Cast<UQuestionUI>(QuestionUI->GetUserWidgetObject());
	Question->QuestionTxt->Text = FText::FromString(Questions[num]->GetQuestionTxt());
	Question->PossibleAnswers->Text = FText::FromString(Questions[num]->GetPossibleAnswers());
	Question->AnswerReference->Text = FText::FromString(Questions[num]->GetReferenceTxt());
	Question->MiniMapImage->SetBrushFromTexture(MiniMapImages[num - 1]);
	Question->ReferenceImage->SetBrushFromTexture(ReferenceImages[num - 1]);

	QuestionUI->GetUserWidgetObject()->SetIsEnabled(true);
	QuestionUI->GetUserWidgetObject()->SetVisibility(ESlateVisibility::Visible);
}
