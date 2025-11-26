// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item.h"
#include "DrawDebugHelpers.h"


void AItem::selfRatate(float DeltaTime)
{
	currentYaw += 5.0f * DeltaTime;
	currentYaw = FMath::Fmod(currentYaw, 360.0f);
	auto actorRot = GetActorRotation();

	SetActorRotation({ actorRot.Pitch,currentYaw,actorRot.Roll });
}

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//设置这个Actor每帧调用Tick()函数。如果不需要，可以关闭以提高性能。
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	/*UELOG
	*p1:CategoryName:日志类别（也可以自定义）
		LogTemp	临时日志（调试用）
		LogBlueprint	蓝图相关日志
		LogNet	网络日志
		LogPhysics	物理系统日志
	p2:日志级别
		日志等级（Verbose、Warning、Error 等）
	P3 内容可格式化
	*/
	//Text 常量字符串转unicode
	UE_LOG(LogTemp, Warning, TEXT("OverLxrd on CPP-BeginPlay"));
	if (GEngine) {//判断GEngine是否为空,但是通常beginplay都在初始化后调用,所以GEngine一般不会为空
		GEngine->AddOnScreenDebugMessage(0, 60.0f, FColor::Cyan, FString("OverLxrd on C++-[ScreenDebug]")); 
	}
	auto actLoc = GetActorLocation();
	actLoc.Z += 50;
	//如果bSweep设置true修改位置时如果有碰撞体阻挡会停止移动
	SetActorLocation(actLoc);
	//bPersistentLines 的意思是 是否使调试图形永久存在
	//true:它将 保持可见(好像一直存在，除非手动清除?)
	//false:until lifetime expires (持续时间到期后消失)
	DrawDebugSphere(GetWorld(), GetActorLocation(), 32.0f, 12, FColor::Cyan, false, 3.0f);
	DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation()+GetActorForwardVector()*100, FColor::Red, true, 30.0f, 0, 1.0f);
	DrawDebugPoint(GetWorld(), GetActorLocation(), 10.f, FColor::Green, false, 5.f);
}


// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("OverLxrd on CPP-Tick Deltatime:%f"),DeltaTime);
	if (GEngine) {
		/*
		FString GetName()
			要获取FString的内容需要使用*操作符，类似String.c_str()

		FString::Printf类似于C语言中的sprintf函数，用于格式化字符串。
		*/
		auto msg = FString::Printf(TEXT("OverLxrd on CPP-Tick-Screen[%s-Deltatime:%f]"), *GetName(), DeltaTime);
		GEngine->AddOnScreenDebugMessage(0, 60.0f, FColor::Cyan, msg);
	}
	
	selfRatate(DeltaTime);

	FVector Start = GetActorLocation();
	FVector End = Start + GetActorForwardVector() * 100.0f; // 射线长度 200

	// 绘制调试射线：不持久化 (false)，显示 0.1 秒
	DrawDebugLine(GetWorld(), Start, End, FColor{ 255,192,203 }, false, 0.0F, 0, 3.0f);
}

