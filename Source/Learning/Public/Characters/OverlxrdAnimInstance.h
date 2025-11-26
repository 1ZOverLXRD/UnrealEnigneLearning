// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Characters/CharacterHandState.h"
#include "OverlxrdAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class LEARNING_API UOverlxrdAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	//即使游戏没有运行，动画实例也会更新
public:
	UFUNCTION(BlueprintCallable, Category = Movement)
	ECharacterState GetCurrentState();
	FORCEINLINE void SetCharacterState(ECharacterState NewState) { CharacterState = NewState; }
	//初始化动画实例时调用的函数
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
protected:
	UPROPERTY(BlueprintReadWrite,Category=Movement)
	class AOverLxrdCharacter* OverLxrdCharacter;
	UPROPERTY(BlueprintReadWrite,Category=Movement)
	class UCharacterMovementComponent* OverLxrdMovementComponent;
	UPROPERTY(BlueprintReadWrite, Category = Movement)
	float GroundSpeed;
	UPROPERTY(BlueprintReadWrite, Category = Movement)
	bool IsFalling;

	UPROPERTY(BlueprintReadWrite, Category = Movement)
	ECharacterState CharacterState;
};
