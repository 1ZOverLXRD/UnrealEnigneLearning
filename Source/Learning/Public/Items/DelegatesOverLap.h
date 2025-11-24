// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DelegatesOverLap.generated.h"

class USphereComponent;
class UStaticMeshComponent;

UCLASS()
class LEARNING_API ADelegatesOverLap : public AActor
{
	GENERATED_BODY()
	
public:	
	ADelegatesOverLap();
	virtual void Tick(float DeltaTime) override;
	//要使用委托就必须是UFUNCTION
	UFUNCTION()
	void OnSphereOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ItemMesh;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* Sphere;


};
