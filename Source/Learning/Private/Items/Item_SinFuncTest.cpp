// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item_SinFuncTest.h"

// Sets default values
AItem_SinFuncTest::AItem_SinFuncTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AItem_SinFuncTest::BeginPlay()
{
	Super::BeginPlay();
	
}

float AItem_SinFuncTest::transformedSin_callable(float Value)
{
	return this->floatHeight * FMath::Sin(Value * this->moveSpeed);
}

float AItem_SinFuncTest::transformedSin_callable_noarg()
{
	return this->floatHeight * FMath::Sin(this->RunningTime * this->moveSpeed);
}

float AItem_SinFuncTest::transformedCos_callable(float Value)
{
	return this->floatHeight * FMath::Cos(this->RunningTime * this->moveSpeed);
}

// Called every frame
void AItem_SinFuncTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RunningTime += DeltaTime;
	auto DeltaZ = this->floatHeight*FMath::Sin(RunningTime*this->moveSpeed); //limit*sin(val *Speed)
	UE_LOG(LogTemp, Warning, TEXT("OVERLXRD DEBUG:%f"), DeltaZ);
	auto newLoc = FVector(0, 0, DeltaZ);
	AddActorWorldOffset(newLoc);
	UE_LOG(LogTemp, Warning, TEXT("OVERLXRD ActorPos:%s"), *(newLoc.ToString()));
	DrawDebugSphere(GetWorld(),GetActorLocation(),32,16,FColor::Purple,false,0.0F);
}

