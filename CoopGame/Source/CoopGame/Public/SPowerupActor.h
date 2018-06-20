// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SPowerupActor.generated.h"

UCLASS()
class COOPGAME_API ASPowerupActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASPowerupActor();

protected:

	/* Time between powerup tics */
	UPROPERTY(EditDefaultsOnly, Category = "Powerups")
	float PowerupInterval;

	/* Total times we applied the powerup effect  */
	UPROPERTY(EditDefaultsOnly, Category = "Powerups")
	int32 TotalNumberOfTicks;

	FTimerHandle TimerHandler_PowerupTick;  

	/* Total numbers of ticks applied */
	int32 TicksProcessed;
	
	UFUNCTION()
	void OnTickPowerup();

	// Kepes state of the power up
	UPROPERTY(ReplicatedUsing=OnRep_PowerupActive)
	bool bIsPowerupActive;

	UFUNCTION()
	void OnRep_PowerupActive();

	// This implementable event will be implemeneted in blueprint, so we can  use visibility
	UFUNCTION(BlueprintImplementableEvent, Category = "Powerups")
	void OnPowerupStateActiveChanged(bool bNewIsActive);

public:

	void ActivatePowerup(AActor* ActiveFor);


	UFUNCTION(BlueprintImplementableEvent, Category = "Powerups")
	void OnActivated(AActor* ActiveFor);

	UFUNCTION(BlueprintImplementableEvent, Category = "Powerups")
	void OnPowerupTicked();

	UFUNCTION(BlueprintImplementableEvent, Category = "Powerups")
	void OnExpired();
};
