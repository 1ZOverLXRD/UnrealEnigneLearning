// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WeaponItem.generated.h"

class UStaticMeshComponent;
class USphereComponent;
UCLASS()
class LEARNING_API AWeaponItem : public AActor
{
	GENERATED_BODY()

public:
	AWeaponItem();
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	virtual void OnSphereOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	virtual void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	FORCEINLINE void SetFloating(bool bNewFloating) { bFloating = bNewFloating; }
private:
	void LoopFloating(float DeltaTime);
	UPROPERTY()
	float RunningTime = 0.f;
	UPROPERTY()
	FVector InitialLocation;
protected:
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, Category = Weapon)
	bool bFloating = true;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite,Category=Weapon)
	UStaticMeshComponent* WeaponMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Weapon)
	USphereComponent* PickupSphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	float Amplitude=70.f;//上下浮动幅度

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	float Frequency = 3.f;    // 频率（值越大浮动越快）
};
