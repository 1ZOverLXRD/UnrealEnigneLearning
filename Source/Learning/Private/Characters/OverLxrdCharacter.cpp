// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/OverLxrdCharacter.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

void AOverLxrdCharacter::AddComponentAndInit()
{

	// CharMoveComp:bOrientRotationToMovement 朝向移动时旋转角色
	UCharacterMovementComponent* characterMoveComp;
	if ((characterMoveComp = GetCharacterMovement())) {
		characterMoveComp->bOrientRotationToMovement = true;
		characterMoveComp->RotationRate = FRotator{0.f,480.f,0.f};//旋转速率
	}
	//添加组件
	this->CHR_SpringArm=CreateDefaultSubobject<USpringArmComponent>(TEXT("CharacterSA"));
	/*SpringArm 和 Camera 是 辅助组件，不会自动成为根组件，也没有默认挂载逻辑，它们依赖父组件的 Transform 来生效。*/
	this->CHR_SpringArm->SetupAttachment(GetRootComponent());//添加到根组件下
	this->CHR_Camera_SA = CreateDefaultSubobject<UCameraComponent>(TEXT("CharacterC_SA"));
	this->CHR_Camera_SA->SetupAttachment(CHR_SpringArm);
	//控制的是角色的“Actor/胶囊体”是否跟随 Controller 的俯仰角（Pitch，上下看）旋转
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	CHR_SpringArm->bUsePawnControlRotation = true;//让弹簧臂跟随控制器旋转
	
}

AOverLxrdCharacter::AOverLxrdCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AddComponentAndInit();
}

void AOverLxrdCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AOverLxrdCharacter::BindAxisInputs(UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAxis(FName("MoveForward"),this,&AOverLxrdCharacter::onMove_Forward);
	PlayerInputComponent->BindAxis(FName("Turn"),this,&AOverLxrdCharacter::onTurnUp);
	PlayerInputComponent->BindAxis(FName("LookUp"),this,&AOverLxrdCharacter::onLookUp);
	PlayerInputComponent->BindAxis(FName("MoveLOR"),this,&AOverLxrdCharacter::onMoveLOR);
	PlayerInputComponent->BindAction(FName("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);
}

void AOverLxrdCharacter::onMove_Forward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.f))
	{
		//获取角色前方向量
		//const FVector Forward=GetActorForwardVector();
		//AddMovementInput(Forward,Value);
		const FRotator YawRotation{ 0.f,GetControlRotation().Yaw,0.f };//只要角色的偏航角
		/*
		把控制器的旋转（Yaw/Pitch/Roll）转换成一个旋转矩阵，然后取出它的前向（X轴）单位向量
			EAxis::X → 表示「前向（Forward）」方向
			EAxis::Y → 表示「右向（Right）」方向
			EAxis::Z → 表示「上向（Up）」方向
		*/
		const auto Direction = FRotationMatrix{ YawRotation }.GetUnitAxis(EAxis::X);//获取前方向量
		AddMovementInput(Direction, Value*SprintSpeed);
	}
}

void AOverLxrdCharacter::onTurnUp(float Value)
{
	if ((Controller != nullptr) && (Value != 0.f)) {
		AddControllerYawInput(Value);
	}
}

void AOverLxrdCharacter::onLookUp(float Value)
{
	if ((Controller != nullptr) && (Value != 0.f)) {

		AddControllerPitchInput(Value);
	}
}

void AOverLxrdCharacter::onMoveLOR(float Value)
{
	if ((Controller != nullptr) && (Value != 0.f)) {

		const FRotator YawRotation{ 0.f,GetControlRotation().Yaw,0.f };//只要角色的偏航角
		const auto Direction = FRotationMatrix{ YawRotation }.GetUnitAxis(EAxis::Y);//获取Right向量
		AddMovementInput(Direction, Value);
	}
}

void AOverLxrdCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AOverLxrdCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	BindAxisInputs(PlayerInputComponent);
}

