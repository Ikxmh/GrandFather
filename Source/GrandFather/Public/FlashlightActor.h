// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FlashlightActor.generated.h"

class UStaticMeshComponent;
class USpotLightComponent;
class UFlashlightComp;

UCLASS()
class GRANDFATHER_API AFlashlightActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFlashlightActor();

	void ToggleFlashLight();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* FlashlightMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USpotLightComponent* SpotLight;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UFlashlightComp* FlashlightComp;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
