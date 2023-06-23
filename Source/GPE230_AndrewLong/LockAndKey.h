// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "LockAndKey.generated.h"

/**
 * 
 */
UCLASS()
class GPE230_ANDREWLONG_API ALockAndKey : public ATriggerBox
{
	GENERATED_BODY()
	
public:
	ALockAndKey();
	
	// Check if the overlapping actor can open the door
	UFUNCTION()
	void CheckActorType(class AActor* OverlappedActor, class AActor* OtherActor);
	
	UFUNCTION()
	void OpenDoor();
};
