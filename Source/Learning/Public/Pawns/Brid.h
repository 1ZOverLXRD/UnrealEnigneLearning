// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
//generated.h 必须在最后
#include "Brid.generated.h"

class UCapsuleComponent;
class USkeletalMeshComponent;
class UFloatingPawnMovement;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class LEARNING_API ABrid : public APawn
{
	GENERATED_BODY()
private:
	UPROPERTY(VisibleAnywhere)
	UCapsuleComponent* Capsule;

	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* BridSkeletalMesh;

	UPROPERTY(VisibleAnywhere)
	UFloatingPawnMovement* BridMovement;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* BridSpringArm;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* BridSpringArm_Camera;
	//UCapsual
public:
	// Sets default values for this pawn's properties
	ABrid();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//����Asixӳ��(�� ��Ŀ����->����->����->��ӳ�� ������)
	//���Ų���:���� 1����ת���� 2.�Ŵ���С�ƶ��ٶ�
	//��������Ϊvoid
	void MoveForward(float Value);
	void Turn(float Value);
	void LookUp(float Value);
};
