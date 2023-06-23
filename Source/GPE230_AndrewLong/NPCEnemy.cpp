// Fill out your copyright notice in the Description page of Project Settings.


#include "NPCEnemy.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/DamageType.h"

// Sets default values
ANPCEnemy::ANPCEnemy() {
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ANPCEnemy::BeginPlay() {
	Super::BeginPlay();
}

// Called every frame
void ANPCEnemy::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ANPCEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

// <summary>Check if the NPC hit something.</summary>
void ANPCEnemy::DetectHit() {
	// I wonder if there's a way to use raymarching instead of a SphereTrace? //

	bool canDamage = true;
	
	// Get location of fist
	const FVector PunchLocation = GetMesh()->GetSocketLocation(_PunchingHandSocketName);
	
	// Disregard this actor and its controller
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(this);
	ActorsToIgnore.Add(GetOwner());
	
	// Array of hit actors
	TArray<FHitResult> HitArray;
	
	// Spheretrace around the fist for overlapped actors
	// returns true - if there are any, returns false if there is none
	const bool Hit = UKismetSystemLibrary::SphereTraceMulti(
		GetWorld(), PunchLocation, PunchLocation, _TraceRadius,
		UEngineTypes::ConvertToTraceType(ECC_Camera), false,
		ActorsToIgnore, EDrawDebugTrace::ForDuration, HitArray,
		true, FLinearColor::Red, FLinearColor::Green, 0.5f
	);

	// Name of the actor, for debugging
	FString ownerName = this->GetName();
	
	// If no hits detected, print then return.
	// Return home early, I know, but we're not allocating memory on the heap so it's fine.
	if (!Hit) {
		UE_LOG(LogTemp, Log, TEXT("NPCEnemy \"%s\" didn\'t hit anything"), *ownerName);
		return;
	}
	
	// Loop through all hits
	// If I'm not wrong, this code has a bug in it, if a hittable actor is detected, every other will not be hit because of the guard clause.
	for (const FHitResult &HitResult : HitArray) {
		if (!canDamage) continue;

		FString hitActorName = HitResult.GetActor()->GetName();

		UE_LOG(LogTemp, Log, TEXT("NPCEnemy \"%s\" hit actor, \"%s\" for %f damage."), *ownerName, *hitActorName, _HitDamage);

		// Apply damage to hit actor
		UGameplayStatics::ApplyDamage(HitResult.GetActor(), _HitDamage, GetController(), this, UDamageType::StaticClass());

		canDamage = false;
	}

	return;
}

