// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FlashlightComp.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GRANDFATHER_API UFlashlightComp : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFlashlightComp();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void ToggleFlashLight();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void DrainBattery(float DeltaTime);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flashlight")
	float CurrentBattery = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flashlight")
	float DrainRate = 5.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flashlight")
	float DrainRateModifier = 1.0f;

	bool bIsOn = false;


		
};
