// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "OverLxrdCharacter.generated.h"


UCLASS()
class LEARNING_API AOverLxrdCharacter : public ACharacter
{
	GENERATED_BODY()
private:
	//添加组件并初始化组件
	void AddComponentAndInit();

	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* CHR_SpringArm;

	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* CHR_Camera_SA;
public:
	AOverLxrdCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
protected:
	UPROPERTY(VisibleInstanceOnly, Category =OverLxrd)
	float SprintSpeed = 1.f;


	virtual void BeginPlay() override;
	void BindAxisInputs(class UInputComponent* PlayerInputComponent);
	//前进函数
	void onMove_Forward(float Value);
	//处理视角左右(Yaw)
	void onTurnUp(float Value);
	//处理Pitch函数
	void onLookUp(float Value);
	//处理pos左右
	void onMoveLOR(float Value);
};
