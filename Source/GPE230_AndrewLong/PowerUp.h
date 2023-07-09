// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "MazeCharacter.h"
#include "PowerUp.generated.h"

/**
 * 
 */
UCLASS()
class GPE230_ANDREWLONG_API APowerUp : public ATriggerBox
{
	GENERATED_BODY()
	
public:
	/// <summary> Time used in the respawn timer </summary> 
	UPROPERTY(EditAnywhere)
	float respawnTimerStart = 5.0;
	/// <summary> Flag for power up being disabled </summary>
	UPROPERTY(EditAnywhere)
	bool isDisabled = false;

	APowerUp();
	
	virtual void Tick(float DeltaTime) override;
	
	// Check if the overlapping actor can open the door
	UFUNCTION()
	void CheckActorType(class AActor* OverlappedActor, class AActor* OtherActor);
	// Blueprint implementable
	UFUNCTION(BlueprintImplementableEvent)
	void OnCollection(class AMazeCharacter* Player);
	// Make reenable blueprint callable
	UFUNCTION(BlueprintCallable)
	void Reenable();
	// Make disable or kill blueprint callable
	UFUNCTION(BlueprintCallable)
	void DisableOrKill();
	
private:
	/// <summary> Flag for if the power up is respawnable </summary>
	UPROPERTY(EditAnywhere)
	bool isRespawnable;

	/// <summary> Respawn timer buffer </summary>
	UPROPERTY(VisibleAnywhere)
	float _respawnTimer = 0.0;
};
