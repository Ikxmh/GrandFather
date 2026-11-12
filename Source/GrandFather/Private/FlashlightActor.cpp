// Fill out your copyright notice in the Description page of Project Settings.



#include "FlashlightActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SpotLightComponent.h"
#include "FlashlightComp.h"

// Sets default values
AFlashlightActor::AFlashlightActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFlashlightActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFlashlightActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFlashlightActor::ToggleFlashLight()
{
	if (FlashlightComp)
	{
		FlashlightComp->ToggleFlashLight();
	}
}

