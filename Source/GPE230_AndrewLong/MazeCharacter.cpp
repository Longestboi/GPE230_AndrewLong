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

/// <summary>Called to bind functionality to input.</summary>
void AMazeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	// Do input of inherited class. 
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	// Bind callback functions to player input.
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AMazeCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AMazeCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AMazeCharacter::Turn);
}

/// <summary>Move forward/backward callback function.</summary>
void AMazeCharacter::MoveForward(float value) {
	AddMovementInput(GetActorForwardVector(), value * moveSpeed);
}

/// <summary>Move right/left callback function.</summary>
void AMazeCharacter::MoveRight(float value) {
	AddMovementInput(GetActorRightVector(), value * moveSpeed);
}

/// <summary>Rotation callback function.</summary>
void AMazeCharacter::Turn(float value) {
	AddControllerYawInput(value * turnSpeed);
}

/// <summary>Unused, likely to be removed.</summary>
void AMazeCharacter::Die() {
	UE_LOG(LogTemp, Log, TEXT("Player is DEAD"));
}

void AMazeCharacter::ActivateStunParticleSystem() {
	if (!_stunSystem) {
		UE_LOG(LogTemp, Error, TEXT("Player attempted to use the stun ability, but no template was not found."));
		return;
	}
	
	USceneComponent* AttachComp = GetDefaultAttachComponent();
	
	UNiagaraComponent* NiagaraComp = UNiagaraFunctionLibrary::SpawnSystemAttached(
		_stunSystem, AttachComp, NAME_None, FVector(0),
		FRotator(0), EAttachLocation::Type::KeepRelativeOffset, true
	);
	
	NiagaraComp->Activate();
}
