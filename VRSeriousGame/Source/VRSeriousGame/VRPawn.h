// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "HandControllerBase.h"

#include "VRPawn.generated.h"

UCLASS()
class VRSERIOUSGAME_API AVRPawn : public APawn
{
	GENERATED_BODY()

public:
	AVRPawn();

protected:
	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

private:
	void RightTriggerPressed() { if (RightHandController) RightHandController->TriggerPressed(); }
	void RightTriggerReleased() { if (RightHandController) RightHandController->TriggerReleased(); }

public:	
	// Config
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AHandControllerBase> RightHandControllerClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AHandControllerBase> LeftHandControllerClass;

	// Components
	UPROPERTY(VisibleAnywhere)
	USceneComponent* VRRoot;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;

	// Reference
	UPROPERTY()
	AHandControllerBase* RightHandController;

	UPROPERTY()
	AHandControllerBase* LeftHandController;

};
