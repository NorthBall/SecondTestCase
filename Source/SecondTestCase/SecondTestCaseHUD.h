// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SecondTestCaseHUD.generated.h"

UCLASS()
class ASecondTestCaseHUD : public AHUD
{
	GENERATED_BODY()

public:
	ASecondTestCaseHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

