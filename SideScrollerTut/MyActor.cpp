// Fill out your copyright notice in the Description page of Project Settings.

#include "SideScrollerTut.h"
#include "MyActor.h"
#include <iostream>
#include <lo/lo.h>
#include <lo/lo_cpp.h>


// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
        TotalDamage = 150;
        DamageTimeInSeconds = 2.f;
OSChost = "localhost";
OSCport = "9000";

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
Super::BeginPlay();
std::cout << "Begin play" << std::endl;
std::string host(TCHAR_TO_UTF8(*OSChost));
std::string port(TCHAR_TO_UTF8(*OSCport));
lo::Address dumpster(host, port);
dumpster.send("hello", "i", 1000);
	
}

// Called every frame
void AMyActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AMyActor::PostInitProperties()
{
    Super::PostInitProperties();
    CalculateValues();
}

void AMyActor::CalculateValues()
{
    DamagePerSecond = TotalDamage / DamageTimeInSeconds;
}

#if WITH_EDITOR
void AMyActor::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
    CalculateValues();

    Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif
