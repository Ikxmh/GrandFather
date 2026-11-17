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
	
	// for setting up flashlight mesh
	FlashlightMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FlashlightMesh")); // makes a pointer
	RootComponent = FlashlightMesh;
	FlashlightMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// for adding the light to flashlight
	SpotLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("Spotlight"));
	SpotLight->SetupAttachment(FlashlightMesh);
	SpotLight->SetVisibility(false);

	FlashlightComp = CreateDefaultSubobject<UFlashlightComp>(TEXT("FlashlightComp"));
	FlashlightComp->SetSpotLight(SpotLight);



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

