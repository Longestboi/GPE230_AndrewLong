// Fill out your copyright notice in the Description page of Project Settings.

#include "GameFramework/DefaultPawn.h"
#include "MazeCharacter.h"

// Sets default values
AMazeCharacter::AMazeCharacter() {
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMazeCharacter::BeginPlay() {
	Super::BeginPlay();
	
}

// Called every frame
void AMazeCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input.
void AMazeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	// Do input of inherited class. 
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	// Bind callback functions to player input.
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AMazeCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AMazeCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AMazeCharacter::Turn);
}

// Move forward/backward callback function.
void AMazeCharacter::MoveForward(float value) {
	AddMovementInput(GetActorForwardVector(), value * moveSpeed);
}

// Move right/left callback function.
void AMazeCharacter::MoveRight(float value) {
	AddMovementInput(GetActorRightVector(), value * moveSpeed);
}

// Rotation callback function.
void AMazeCharacter::Turn(float value) {
	AddControllerYawInput(value * turnSpeed);
}
