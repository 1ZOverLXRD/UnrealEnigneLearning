// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Weapons/WeaponItem.h"
#include "Components/SphereComponent.h"

// Sets default values
AWeaponItem::AWeaponItem()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	RootComponent = WeaponMesh;

	PickupSphere = CreateDefaultSubobject<USphereComponent>(TEXT("PickupSphere"));
	PickupSphere->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AWeaponItem::BeginPlay()
{
	Super::BeginPlay();
	InitialLocation = GetActorLocation();
	PickupSphere->OnComponentBeginOverlap.AddDynamic(this, &AWeaponItem::OnSphereOverlapBegin);
	PickupSphere->OnComponentEndOverlap.AddDynamic(this, &AWeaponItem::OnSphereEndOverlap);
}



// Called every frame
void AWeaponItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(bFloating)LoopFloating(DeltaTime);
	
}

void AWeaponItem::OnSphereOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void AWeaponItem::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}



void AWeaponItem::LoopFloating(float DeltaTime)
{
	RunningTime += DeltaTime;

	float rawSin = FMath::Sin(RunningTime * Frequency); // -1 ~ 1
	float OffsetZ = (rawSin + 1.f) * 0.5f * Amplitude;  // 0 ~ Amplitude
	FVector NewLocation = InitialLocation;
	NewLocation.Z += OffsetZ;
	SetActorLocation(NewLocation);
}

