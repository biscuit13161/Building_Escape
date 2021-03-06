// Fill out your copyright notice in the Description page of Project Settings.

#include "Building_Escape.h"
#include "OpenDoor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

}

void UOpenDoor::OpenDoor()
{
    // Find the Owning Actor
    AActor* Object = GetOwner();
    
    // Create Rotator
    FRotator NewRotation = FRotator(0.f,60.f,0.f);
    
    // Set Door rotation
    Object->SetActorRotation(NewRotation);
}

// Called every frame
void UOpenDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// poll TriggerVolume every frame
    if (PressurePlate->IsOverlappingActor(ActorThatOpens))
    {
    OpenDoor();
    }
}


