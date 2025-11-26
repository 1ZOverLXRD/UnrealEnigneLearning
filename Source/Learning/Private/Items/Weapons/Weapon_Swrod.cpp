// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Weapons/Weapon_Swrod.h"
#include "Characters/OverLxrdCharacter.h"
#include "Components/SphereComponent.h"
#include "Items/Weapons/WeaponItem.h"

void AWeapon_Swrod::BeginPlay()
{
	Super::BeginPlay();
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	PickupSphere->SetCollisionProfileName(FName("OverlapOnlyPawn"));
	PickupSphere->OnComponentBeginOverlap.AddDynamic(this, &AWeapon_Swrod::OnSphereOverlapBegin);
	PickupSphere->OnComponentEndOverlap.AddDynamic(this, &AWeapon_Swrod::OnSphereEndOverlap);
}

void AWeapon_Swrod::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
} 

void AWeapon_Swrod::OnSphereOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	//Super::OnSphereOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	auto player=Cast<AOverLxrdCharacter>(OtherActor);
	if (player) {
		player->SetAroundWeapon(this);
	}
}

void AWeapon_Swrod::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	auto player = Cast<AOverLxrdCharacter>(OtherActor);
	if (player) {
		player->SetAroundWeapon(nullptr);
	}
}
