// Fill out your copyright notice in the Description page of Project Settings.


#include "FlashlightComp.h"

// Sets default values for this component's properties
UFlashlightComp::UFlashlightComp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	bIsOn = false;

	// ...
}


// Called when the game starts
void UFlashlightComp::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UFlashlightComp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	DrainBattery(DeltaTime);

	if (bIsOn && GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 0.1f, FColor::Blue, FString::Printf(TEXT("Current Battery: %.1f%%"), CurrentBattery));
	}

	// ...
}

void UFlashlightComp::ToggleFlashLight()
{
	bIsOn = !bIsOn;

	if (GEngine)
	{
		FColor MessageColour = bIsOn ? FColor::Green : FColor::Orange;
		FString MessageText = bIsOn ? TEXT("Flashlight: ON") : TEXT("Flashlight: OFF");
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, MessageColour, MessageText);
	}
}

void UFlashlightComp::DrainBattery(float DeltaTime)
{
	if (CurrentBattery <= 0.0f)
	{
		CurrentBattery = 0.0f;
		bIsOn = false;
		return;
	}

	if (bIsOn && CurrentBattery > 0.0f)
	{
		CurrentBattery -= (DrainRate * DrainRateModifier) * DeltaTime;

		if (CurrentBattery <= 0.0f)
		{
			CurrentBattery = 0.0f;
			bIsOn = false; 
			 
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 4.0f, FColor::Red, TEXT("Battery is Empty"));
			}
		}
	}
}
