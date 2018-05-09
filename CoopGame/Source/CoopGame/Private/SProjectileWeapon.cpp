// Fill out your copyright notice in the Description page of Project Settings.

#include "SProjectileWeapon.h"

void ASProjectileWeapon::Fire()
{
	AActor* Owner = GetOwner();

	if (Owner)
	{
		FVector EyeLocation;
		FRotator EyeRotation;
		Owner->GetActorEyesViewPoint(EyeLocation, EyeRotation);



	}

}


