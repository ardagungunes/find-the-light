// Fill out your copyright notice in the Description page of Project Settings.


#include "Lock.h"

// Sets default values
ALock::ALock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	rootComp = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	SetRootComponent(rootComp);

	triggerComp = CreateDefaultSubobject<UTriggerComponent>(TEXT("Trigger Component"));
	triggerComp->SetupAttachment(rootComp);

	keyItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Key Item Mesh"));
	keyItemMesh->SetupAttachment(rootComp);

	Tags.Add("Lock");

}

// Called when the game starts or when spawned
void ALock::BeginPlay()
{
	Super::BeginPlay();
	setIsKeyPlaced(true);
	
}

// Called every frame
void ALock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ALock::getIsKeyPlaced()
{
	return isKeyPlaced;
}

void ALock::setIsKeyPlaced(bool isPlaced)
{
	isKeyPlaced = isPlaced;
	triggerComp->mover->setShouldMove(isPlaced);
	keyItemMesh->SetVisibility(isPlaced);
}

