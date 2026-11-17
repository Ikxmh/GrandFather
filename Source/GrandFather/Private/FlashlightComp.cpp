// Fill out your copyright notice in the Description page of Project Settings.


#include "FlashlightComp.h"
#include "Components/SpotLightComponent.h"
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

	if (!SpotLight && GetOwner())
	{
		SpotLight = GetOwner()->FindComponentByClass<USpotLightComponent>();
	}

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

void UFlashlightComp::SetFlashLightState(bool bNewState)
{
	bIsOn = bNewState;

	if (SpotLight)
	{
		SpotLight->SetVisibility(bIsOn);
	}
}

void UFlashlightComp::ToggleFlashLight()
{
	if (CurrentBattery <= 0.0f)
	{
		SetFlashLightState(false);

		return;
	}

	SetFlashLightState(!bIsOn);

	if (GEngine)
	{
		FColor MessageColour = bIsOn ? FColor::Green : FColor::Orange;
		FString MessageText = bIsOn ? TEXT("Flashlight: ON") : TEXT("Flashlight: OFF");
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, MessageColour, MessageText);
	}
}

void UFlashlightComp::DrainBattery(float DeltaTime)
{
	if (!bIsOn)
		return; 

	CurrentBattery = FMath::Max(0.0f, CurrentBattery - (DrainRate * DrainRateModifier) * DeltaTime);

	if (CurrentBattery <= 0.0f)
	{
		SetFlashLightState(false);

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 4.0f, FColor::Red, TEXT("Battery is Empty"));
		}

	}
}

void UFlashlightComp::SetSpotLight(USpotLightComponent* NewSpotLight)
{
	SpotLight = NewSpotLight;
}
