// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGame.h"
#include "Misc/Paths.h"

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

	MiniMapImageUI = CreateDefaultSubobject<UWidgetComponent>(TEXT("MiniMapImageUI"));
	MiniMapImageUI->SetupAttachment(GetRootComponent());

	ReferenceImageUI = CreateDefaultSubobject<UWidgetComponent>(TEXT("ReferenceImageUI"));
	ReferenceImageUI->SetupAttachment(GetRootComponent());

	CurrentTimeTxt = "00:00";
}

// Called when the game starts or when spawned
void AMainGame::BeginPlay()
{
	Super::BeginPlay();
	TotalScore = 0;
	CurrentScore = 0;

	ChooseQuestions->GetUserWidgetObject()->SetIsEnabled(false);
	ChooseQuestions->GetUserWidgetObject()->SetVisibility(ESlateVisibility::Hidden);

	Questions.Empty();

	for (int32 i = 0; i < 10; i++)
	{
		CreateQuestion(i);
	}

	ChooseQuestions->GetUserWidgetObject()->SetIsEnabled(true);
	ChooseQuestions->GetUserWidgetObject()->SetVisibility(ESlateVisibility::Visible);

	CurrentSeconds = 0;
	CurrentMinutes = 0;
	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &AMainGame::UpdateTimer, 1.0f, true);
	FString InitialResult = "Matricula " + CurrentFilename + "\n" +
		"Puntaje final, " + FString::FromInt(CurrentScore) + "/" + FString::FromInt(TotalScore) + "\n" +
		"Numero de pregunta, Resultado, Puntaje obtenido, Tiempo\n";
	SaveProgress(InitialResult, CurrentFilename);
}

void AMainGame::CreateQuestion(int32 num)
{
	UQuestion* NewQuestion = NewObject<UQuestion>(this, UQuestion::StaticClass(), FName("UQuestion" + FString::FromInt(num)));
	NewQuestion->SetupQuestion(num);
	TotalScore += NewQuestion->GetValue();
	Questions.Add(NewQuestion);
}

void AMainGame::UpdateTimer()
{
	CurrentSeconds++;
	if (CurrentSeconds == 60)
	{
		CurrentMinutes++;
		CurrentSeconds = 0;
	}

	CurrentTimeTxt = (CurrentMinutes < 10 ? "0" : "") + FString::FromInt(CurrentMinutes) + ":" + (CurrentSeconds < 10 ? "0" : "") + 
		FString::FromInt(CurrentSeconds);

	UE_LOG(LogTemp, Warning, TEXT("%s"), *CurrentTimeTxt);
	UpdateTimerTxt();
}

bool AMainGame::SaveProgress(FString StudentResult, FString Filename = "prueba")
{
	FString SaveDirectory = FPaths::ProjectUserDir() + "\\ResultadosAlumnos";
	UE_LOG(LogTemp, Warning, TEXT("project user dir: %s"), *FPaths::ProjectUserDir());

	if (!IFileManager::Get().DirectoryExists(*SaveDirectory))
	{
		IFileManager::Get().MakeDirectory(*SaveDirectory);

		//exit if dir couldn't be made
		if (!IFileManager::Get().DirectoryExists(*SaveDirectory))
		{
			return false;
		}
	}

	Filename += ".csv";
	SaveDirectory += "\\";
	SaveDirectory += Filename;
	StudentResult += Progress;

	return FFileHelper::SaveStringToFile(StudentResult, *SaveDirectory);
}


void AMainGame::SaveProgressOnQuestionAnswered(int32 QuestionNum)
{
	UQuestion* Question = Questions[QuestionNum];
	Progress += FString::FromInt(QuestionNum + 1) + ", ";
	if (Question->GetUserAnsweredCorrectly())
	{
		Progress += "Correcto, " + FString::FromInt(Question->GetValue()) + ", " + CurrentTimeTxt + "\n";
	}
	else
	{
		Progress += "Incorrecto, 0 puntos, " + CurrentTimeTxt + "\n";
	}

	FString StudentResult = "Matricula, " + CurrentFilename + "\n" +
		"Puntaje final, " + FString::FromInt(CurrentScore) + "/" + FString::FromInt(TotalScore) + "\n" +
		"Numero de pregunta, Resultado, Puntaje obtenido, Tiempo\n";
	SaveProgress(StudentResult, CurrentFilename);
}