// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeCharacter.h"
#include "LockAndKey.h"

ALockAndKey::ALockAndKey() {
	// Attach callback function to this instance.
	OnActorBeginOverlap.AddDynamic(this, &ALockAndKey::CheckActorType);
}

void ALockAndKey::CheckActorType(
	class AActor* OverlappedActor,
	class AActor* OtherActor
) {
	// Open the door if the colliding object is a maze character
	if (OtherActor->IsA(AMazeCharacter::StaticClass())) {
		this->OpenDoor();
	}
}

void ALockAndKey::OpenDoor() {
	// Delete this whole thing when opening a door
	this->Destroy();
}

