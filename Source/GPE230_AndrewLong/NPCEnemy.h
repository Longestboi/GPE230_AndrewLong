// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NPCEnemy.generated.h"

UCLASS()
class GPE230_ANDREWLONG_API ANPCEnemy : public ACharacter {
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANPCEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Check if the NPC hit something.
	UFUNCTION(BlueprintCallable, Category="Collision")
	void DetectHit();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// Radius of the "hitbox"
	UPROPERTY(EditAnywhere)
	float _TraceRadius = 100.0f;
	
	// The spawn point of the spheretrace
	UPROPERTY(EditAnywhere)
	FName _PunchingHandSocketName;
	
	// The amount of damage done in one hit.
	UPROPERTY(EditAnywhere)
	float _HitDamage;	
};
