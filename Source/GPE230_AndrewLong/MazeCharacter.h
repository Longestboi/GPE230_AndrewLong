// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MazeCharacter.generated.h"

UCLASS()
class GPE230_ANDREWLONG_API AMazeCharacter : public ACharacter {
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMazeCharacter();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Die();

	void setMovementSpeed(float mSpeed) { this->moveSpeed = mSpeed; }
	void setTurnSpeed(float tSpeed) { this->turnSpeed = tSpeed; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	/* ---------------------- Movement code ---------------------- */
	UPROPERTY(EditAnywhere)
	float moveSpeed;
	UPROPERTY(EditAnywhere)
	float turnSpeed;
	
	// Player input handlers
	void MoveForward(float value);
	void MoveRight(float value);
	void Turn(float value);
};
