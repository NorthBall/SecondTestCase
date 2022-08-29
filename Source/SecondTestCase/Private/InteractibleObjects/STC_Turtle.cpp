// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractibleObjects/STC_Turtle.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTree.h"

ASTC_Turtle::ASTC_Turtle()
{
	BehaviorTree = nullptr;
	TurtleBehavior = ETB_TurtleBehavior::ETB_StraightForward;
}

void ASTC_Turtle::BeginPlay()
{
	Super::BeginPlay();

	if (TurtleBehavior == ETB_TurtleBehavior::ETB_StraightForward)
	{
		SimpleMoveTurtle();
		return;
	}

	InitBehaviorTree();

	AAIController* AIController = Cast<AAIController>(GetController());
	if (!IsValid(AIController))
	{
		return;
	}
	if (!IsValid(BehaviorTree))
	{
		return;
	}
	AIController->RunBehaviorTree(BehaviorTree);
}
