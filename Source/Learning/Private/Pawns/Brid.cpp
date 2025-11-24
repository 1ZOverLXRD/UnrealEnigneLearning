// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/Brid.h"

#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"


// Sets default values
ABrid::ABrid()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//创建组件
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("BridCapsualCompoennt"));//胶囊组件
	BridSkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BridSkeletalMeshComponent"));//骨骼网格组件
	BridSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("BridSpringArmComponent"));//弹簧臂组件 SpringArm 自动处理摄像机碰撞问题
	BridSpringArm_Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("BridSpringArmCameraComponent"));//摄像机组件
	
	//设置Pawn旋转跟随控制器
	this->bUseControllerRotationPitch = true;
	this->bUseControllerRotationYaw = true;

	//设置根组件
	SetRootComponent(Capsule);
	//设置胶囊组件的大小 和碰撞箱
	Capsule->SetCapsuleSize(16.F, 22.F,false);//设置胶囊组件的大小
	Capsule->SetCapsuleHalfHeight(17.F);//如果要设置HalftHeight<22时SetCapsuleSize
	Capsule->SetCapsuleRadius(16.F);
	Capsule->SetCollisionProfileName(TEXT("BlockAll"));//设置碰撞预设BlockAll 这样才会有碰撞效果
	UE_LOG(LogTemp, Warning, TEXT("Capsule HalfHeight: %f, Radius: %f"), Capsule->GetUnscaledCapsuleHalfHeight(), Capsule->GetUnscaledCapsuleRadius());
	//设置骨骼网格组件
	BridSkeletalMesh->SetupAttachment(GetRootComponent());//将sketetalMesh组件附加到胶囊组件上
	BridMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("BridFloatingPawnMovement"));//CreateDefaultSuboject就可以添加组件根据情况才需要Attach
	//设置Camera配置
	BridSpringArm->SetupAttachment(Capsule);
	BridSpringArm->TargetArmLength = 130.f;//设置臂长
	BridSpringArm_Camera->SetupAttachment(BridSpringArm);//将摄像机组件附加到弹簧臂组件上
	//设置自动拥有玩家0,默认为0，如果为1的话就是分屏多的玩家
	AutoPossessPlayer = EAutoReceiveInput::Player0;

}

// Called when the game starts or when spawned
void ABrid::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABrid::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.f))
	{

		auto froward=GetActorForwardVector();
		/*bForce 使用情况：角色被“眩晕 / 冻结 / 禁用移动”

		你暂停了角色的移动（Disable Movement、Root Motion Lock、动画 Montage 锁定角色等）。
			此时玩家按 W 键，AddMovementInput 会完全被丢弃。

			如果你想 记录这段时间玩家的输入，让角色在恢复后立即往该方向动：
		*/
		AddMovementInput(froward, Value);
	}
	

}

void ABrid::Turn(float Value)
{
	if ((Controller != nullptr) && (Value != 0.f)) {
		AddControllerYawInput(Value);
	}
}

void ABrid::LookUp(float Value)
{
	if ((Controller != nullptr) && (Value != 0.f)) {
		AddControllerPitchInput(Value);
	}
}

// Called every frame
void ABrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABrid::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//将输入轴映射绑定到函数
	PlayerInputComponent->BindAxis(FName("MoveForward"),this,&ABrid::MoveForward);
	PlayerInputComponent->BindAxis(FName("Turn"),this,&ABrid::Turn);
	PlayerInputComponent->BindAxis(FName("LookUp"),this,&ABrid::LookUp);
	/*enhanceinput*/
}

