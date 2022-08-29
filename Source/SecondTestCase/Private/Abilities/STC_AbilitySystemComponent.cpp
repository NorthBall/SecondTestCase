// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/STC_AbilitySystemComponent.h"

bool USTC_AbilitySystemComponent::AddAbilityByClass(TSubclassOf<UGameplayAbility> AbilityClass, int Level)
{
	FGameplayAbilitySpec NewAbilitySpec = FGameplayAbilitySpec(AbilityClass, Level, INDEX_NONE);
	FGameplayAbilitySpecHandle NewAbilityHandle = GiveAbility(NewAbilitySpec);
	return NewAbilityHandle.IsValid();
}
