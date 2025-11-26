// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/OverlxrdAnimInstance.h"
#include "Characters/OverLxrdCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

ECharacterState UOverlxrdAnimInstance::GetCurrentState()
{
	return OverLxrdCharacter->GetCharacterState();
}

void UOverlxrdAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	OverLxrdCharacter=Cast<AOverLxrdCharacter>(TryGetPawnOwner());//尝试获取拥有该动画实例的Pawn
	if (OverLxrdCharacter) {
		OverLxrdMovementComponent = OverLxrdCharacter->GetCharacterMovement();
	}
}

void UOverlxrdAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	//实时跟新Globalspeed
	if (OverLxrdMovementComponent) {
		GroundSpeed = UKismetMathLibrary::VSizeXY(OverLxrdMovementComponent->Velocity);
		IsFalling=OverLxrdMovementComponent->IsFalling();
	}
}
