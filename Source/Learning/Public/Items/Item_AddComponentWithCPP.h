// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item_AddComponentWithCPP.generated.h"

UCLASS()
class LEARNING_API AItem_AddComponentWithCPP : public AActor
{
	GENERATED_BODY()
private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* meshComponent;
public:	
	// Sets default values for this actor's properties
	AItem_AddComponentWithCPP();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
