// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuActions.h"



bool UMenuActions::Initialize()
{
	if (!Super::Initialize()) return false;

	if (!UserName) return false;

	if (!UserNameRequired) return false;

	if (!PlayBtn) return false;
	PlayBtn->SetIsEnabled(false);
	PlayBtn->OnClicked.AddDynamic(this, &UMenuActions::PlayBtnClicked);


	return true;
}

void UMenuActions::PlayBtnClicked()
{
}

void UMenuActions::UserNameEntered()
{
}
