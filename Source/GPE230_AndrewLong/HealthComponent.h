// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GPE230_ANDREWLONG_API UHealthComponent : public UActorComponent {
	GENERATED_BODY()
	/* Vars */
	
public:
	/// <summary>Maximum starting health for the character.</summary>
	UPROPERTY(EditAnywhere)
	float maxHealth;
	
protected:
	/// <summary>Current health of the character.</summary>
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float _currentHealth;

private:
	/// <summary>Animation to do on death.</summary>
	UPROPERTY(EditAnywhere)
	UAnimSequence* _deathAnim;
	
	// is dead flag
	bool _isDead = false;


	/* Methods */
public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Custom TakeDamage delagate function 
	UFUNCTION()
	virtual void TakeDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);
	
	UFUNCTION(BlueprintCallable)
	void SetHealth(int h);
	UFUNCTION(BlueprintCallable)
	int GetHealth();
	
	// The death sequence of the parent actor
	UFUNCTION(BlueprintCallable)
	virtual void Die();
};
