// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"

UTriggerComponent::UTriggerComponent() {
	PrimaryComponentTick.bCanEverTick = true;
	
}

void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();

	if (moverActor) {
		
		mover = moverActor->FindComponentByClass<UMover>();

		if (mover) {
			UE_LOG(LogTemp, Display, TEXT("Successfully found the mover component."));
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("Failed to find mover component."));
		}

	}

	else {
		UE_LOG(LogTemp, Warning, TEXT("Mover Actor is nullptr."));
	}

	if (isPressurePlate) {
		OnComponentBeginOverlap.AddDynamic(this, &UTriggerComponent::OnOverlapBegin);
		OnComponentEndOverlap.AddDynamic(this, &UTriggerComponent::OnOverlapEnd);
	}
	
}

void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
}

void UTriggerComponent::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	bool hasTag = OtherActor->ActorHasTag("PressurePlateActivator");

	if (mover && hasTag) {
		mover->shouldMove = true;
	}
	
}

void UTriggerComponent::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

	bool hasTag = OtherActor->ActorHasTag("PressurePlateActivator");

	if (mover && hasTag) {
		mover->shouldMove = false;
	}
	
}
