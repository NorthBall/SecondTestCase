// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "STC_Turtle.generated.h"

class UBehaviorTree;

UENUM(BlueprintType)
enum class ETB_TurtleBehavior : uint8
{
	ETB_StraightForward UMETA(DisplayName = "Move straight to Destination"),
	ETB_WithStops UMETA(DisplayName = "Stop sometimes"),
	ETB_WithInverse UMETA(DisplayName = "Return sometimes")
};

UCLASS()
class SECONDTESTCASE_API ASTC_Turtle : public APawn
{
	GENERATED_BODY()
	
public:
	ASTC_Turtle();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = true), Category = "Behavior")
	FVector SpawnLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = true), Category = "Behavior")
	FVector DestinationLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = true), Category = "Behavior")
	ETB_TurtleBehavior TurtleBehavior;

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent, Category = "Behavior")
	void InitBehaviorTree();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Behavior")
	UBehaviorTree* BehaviorTree;

	UFUNCTION(BlueprintImplementableEvent, Category = "Behavior")
	void SimpleMoveTurtle();
};
