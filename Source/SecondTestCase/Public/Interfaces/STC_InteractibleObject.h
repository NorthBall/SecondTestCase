// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbilityTargetTypes.h"
#include "UObject/Interface.h"
#include "STC_InteractibleObject.generated.h"

UINTERFACE(MinimalAPI)
class USTC_InteractibleObject : public UInterface
{
	GENERATED_BODY()
};

class SECONDTESTCASE_API ISTC_InteractibleObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Ability")
	FGameplayAbilityTargetDataHandle GetTargetData() const;
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Ability")
	bool Activate();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Ability")
	bool Deactivate();
};
