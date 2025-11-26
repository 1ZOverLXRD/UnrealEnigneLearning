// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

//使用UCLASS宏后可以让Unreal引擎识别这个类，并提供反射和序列化等功能
UCLASS()
class LEARNING_API AItem : public AActor
{
	//诉编译器把 Unreal Header Tool (UHT) 为这个类生成的隐藏代码插入到这里。
	GENERATED_BODY()
private:
	double currentYaw = 5.0f; // 自旋转角度 (度/秒)
	void selfRatate(float DeltaTime);
public:	
	// Sets default values for this actor's properties
	AItem();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	// Called when the game starts or when spawned

	virtual void BeginPlay() override;
};
