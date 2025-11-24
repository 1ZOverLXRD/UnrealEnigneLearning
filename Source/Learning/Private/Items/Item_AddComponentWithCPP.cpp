// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item_AddComponentWithCPP.h"
#include "UObject/ConstructorHelpers.h"
// Sets default values
AItem_AddComponentWithCPP::AItem_AddComponentWithCPP()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	/*CreateDefaultSubobject:专门用于在 UObject、AActor的构造函数中创建和初始化组件
		*parm:您必须提供一个唯一的名称（如 TEXT("RootMesh")）。这个名称是 $\text{FName}$ 类型，用于 UE 的内部查找和哈希。在同一个 $\text{UObject}$ 类中，所有
	*/
	this->meshComponent=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemStaticMeshApexPathFinder"));
	RootComponent = this->meshComponent;//将根组件设置为 meshComponent，不再为deafultScreenRootComponent了
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAssetFinder(TEXT("/Script/Engine.StaticMesh'/Game/MYFBX/ApexPathfinder/SM_PathFinder.SM_PathFinder'"));
	if (MeshAssetFinder.Succeeded())
	{
		// 3. 将找到的 Static Mesh 资产设置给组件
		this->meshComponent->SetStaticMesh(MeshAssetFinder.Object);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to find Static Mesh asset!"));
	}
}

// Called when the game starts or when spawned
void AItem_AddComponentWithCPP::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItem_AddComponentWithCPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

