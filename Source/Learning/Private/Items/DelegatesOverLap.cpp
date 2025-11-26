// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/DelegatesOverLap.h"

#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

#include "DrawDebugHelpers.h"

// Sets default values
ADelegatesOverLap::ADelegatesOverLap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ItemMesh=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMesh"));
	RootComponent = ItemMesh;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(GetRootComponent());
	/*
	* 
	DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_SixParams( 这个委托签名的名称其他代码将使用这个名称来声明委托实例。
	, 指明这个委托是作为 UPrimitiveComponent 类的成员使用的
	, 在蓝图中的名字, 
	以下全为参数
	UPrimitiveComponent*, OverlappedComponent, AActor*, OtherActor, UPrimitiveComponent*, OtherComp, int32, OtherBodyIndex, bool, bFromSweep, const FHitResult &, SweepResult);
	*/
}

// Called when the game starts or when spawned
void ADelegatesOverLap::BeginPlay()
{
	Super::BeginPlay();
	//绑定委托事件 事件.AddDynamic
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ADelegatesOverLap::OnSphereOverlapBegin);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &ADelegatesOverLap::OnComponentEndOverlap);
}

// Called every frame
void ADelegatesOverLap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DrawDebugSphere(GetWorld(), Sphere->GetComponentLocation(), 36, 12, FColor::Green);
}

void ADelegatesOverLap::OnSphereOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	FString text = FString::Printf(TEXT("OverLapComponent:%s OA:%s OC:%s OBI:%d FW:%s "), *OverlappedComponent->GetName()
		, *OtherActor->GetName(), *OtherComp->GetName()
		, OtherBodyIndex, (bFromSweep ? TEXT("YES") : TEXT("No")));
	UE_LOG(LogTemp, Warning,TEXT("%s"),*text);
}

void ADelegatesOverLap::OnComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	FString text = FString::Printf(TEXT("EndOverLapComponent:%s OA:%s OC:%s OBI:%d "), *OverlappedComponent->GetName()
		, *OtherActor->GetName(), *OtherComp->GetName()
		, OtherBodyIndex);
	UE_LOG(LogTemp, Warning, TEXT("%s"), *text);
}

