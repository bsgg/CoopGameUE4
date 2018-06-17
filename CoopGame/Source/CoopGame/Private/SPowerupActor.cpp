// Fill out your copyright notice in the Description page of Project Settings.

#include "SPowerupActor.h"


// Sets default values
ASPowerupActor::ASPowerupActor()
{
	PowerupInterval = 0.0f;
	TotalNumberOfTicks = 0;

}

// Called when the game starts or when spawned
void ASPowerupActor::BeginPlay()
{
	Super::BeginPlay();

	
	
}

void ASPowerupActor::OnTickPowerup()
{
	TicksProcessed++;

	OnPowerupTicked();

	if (TicksProcessed >= TotalNumberOfTicks)
	{
		OnExpired();

		// Delete timer
		GetWorldTimerManager().ClearTimer(TimerHandler_PowerupTick);
	}
}

void ASPowerupActor::ActivatePowerup()
{
	OnActivated();

	if (PowerupInterval > 0.0f)
	{
		GetWorldTimerManager().SetTimer(TimerHandler_PowerupTick, this, &ASPowerupActor::OnTickPowerup, PowerupInterval, true);
	}
	else
	{
		OnTickPowerup();
	}
}


