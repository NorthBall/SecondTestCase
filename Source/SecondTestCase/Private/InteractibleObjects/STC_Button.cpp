// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractibleObjects/STC_Button.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "Abilities/STC_AbilitySystemComponent.h"

ASTC_Button::ASTC_Button()
{
	ButtonASC = CreateDefaultSubobject<USTC_AbilitySystemComponent>("ButtonASC");

	SpawnLocation = FVector();
	DestinationLocation = FVector();
	bIsActive = false;
}

FGameplayAbilityTargetDataHandle ASTC_Button::GetTargetData_Implementation() const
{
	FGameplayAbilityTargetingLocationInfo SpawnInfo;
	SpawnInfo.LiteralTransform = FTransform(SpawnLocation);
	SpawnInfo.LocationType = EGameplayAbilityTargetingLocationType::LiteralTransform;
	FGameplayAbilityTargetingLocationInfo DestinationInfo;
	DestinationInfo.LiteralTransform = FTransform(DestinationLocation);
	DestinationInfo.LocationType = EGameplayAbilityTargetingLocationType::LiteralTransform;

	return UAbilitySystemBlueprintLibrary::AbilityTargetDataFromLocations(SpawnInfo, DestinationInfo);
}

UAbilitySystemComponent* ASTC_Button::GetAbilitySystemComponent() const
{
	return ButtonASC;
}

bool ASTC_Button::Activate_Implementation()
{
	if (bIsActive)
	{
		return false;
	}

	bIsActive = true;
	return true;
}

bool ASTC_Button::Deactivate_Implementation()
{
	if (!bIsActive)
	{
		return false;
	}

	bIsActive = false;
	return true;
}

void ASTC_Button::BeginPlay()
{
	Super::BeginPlay();

	InitASC();
}

void ASTC_Button::InitASC_Implementation()
{
	if (IsValid(ButtonASC))
	{
		ButtonASC->InitAbilityActorInfo(this, this);
	}
}
