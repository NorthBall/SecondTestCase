// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Actor.h"
#include "Interfaces/STC_InteractibleObject.h"
#include "STC_Button.generated.h"

class USTC_AbilitySystemComponent;

UCLASS()
class SECONDTESTCASE_API ASTC_Button : public AActor, public ISTC_InteractibleObject, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ASTC_Button();

	virtual FGameplayAbilityTargetDataHandle GetTargetData_Implementation() const override;
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual bool Activate_Implementation() override;
	virtual bool Deactivate_Implementation() override;

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintNativeEvent, Category = "Ability")
	void InitASC();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ability")
	USTC_AbilitySystemComponent* ButtonASC;
	
	UPROPERTY(BlueprintReadWrite, Category = "Ability")
	FVector SpawnLocation;
	UPROPERTY(BlueprintReadWrite, Category = "Ability")
	FVector DestinationLocation;

	UPROPERTY(BlueprintReadWrite, Category = "Ability")
	bool bIsActive;
};
