// Fill out your copyright notice in the Description page of Project Settings.


#include "HandControllerBase.h"

// Sets default values
AHandControllerBase::AHandControllerBase()
{
	MotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("MotionController"));
	SetRootComponent(MotionController);
	MotionController->SetShowDeviceModel(true);
}

void AHandControllerBase::SetHand(EControllerHand Hand)
{
	MotionController->SetTrackingSource(Hand);
}
