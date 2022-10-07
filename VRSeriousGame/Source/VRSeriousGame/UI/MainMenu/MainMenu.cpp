// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"

// Sets default values
AMainMenu::AMainMenu()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	MenuActions = CreateDefaultSubobject<UWidgetComponent>(TEXT("MenuActions"));
	MenuActions->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void AMainMenu::BeginPlay()
{
	Super::BeginPlay();
	
}
