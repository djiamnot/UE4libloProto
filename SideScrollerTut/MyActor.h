// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class SIDESCROLLERTUT_API AMyActor : public AActor
{
	GENERATED_BODY()
	
          public:	
	// Sets default values for this actor's properties
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Damage")
    int32 TotalDamage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Damage")
    float DamageTimeInSeconds;

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category="Damage")
    float DamagePerSecond;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="OSC")
    FString OSChost;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="OSC")
    FString OSCport;

    
    
	AMyActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
        
        void PostInitProperties();
        UFUNCTION(BlueprintCallable, Category="Damage")

        void CalculateValues();
        void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent);
	
};
