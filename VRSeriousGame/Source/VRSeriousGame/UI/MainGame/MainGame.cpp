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
}

// Called when the game starts or when spawned
void AMainGame::BeginPlay()
{
	Super::BeginPlay();
	
}

