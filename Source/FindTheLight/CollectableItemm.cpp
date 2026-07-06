// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectableItemm.h"

// Sets default values
ACollectableItemm::ACollectableItemm()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACollectableItemm::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACollectableItemm::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

