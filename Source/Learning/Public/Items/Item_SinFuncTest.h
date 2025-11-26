// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item_SinFuncTest.generated.h"

UCLASS()
class LEARNING_API AItem_SinFuncTest : public AActor
{
	GENERATED_BODY()
private:
	/*UPROPERTY
	* UPROPERTY宏: 让此变量参与到反射环节,将变量暴露到编辑器(private蓝图拿不到)
		* EditAnywhere:在任何地方可编辑。(only:蓝图+示例)
		* EditDefaultsOnly:只能在类默认对象(蓝图类默认值)中编辑,实例化对象(在游戏视图中)不可编辑 (only:蓝图)
		* EditInstanceOnly:只能在实例化对象中编辑,类默认对象不可编辑 （only:实例)
	* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		* VisibleAnywhere	在任何地方可见。 无论这个属性是属于蓝图类默认值，还是属于场景中放置的实例，它都是可见但不可编辑的。	蓝图默认值 + 场景实例
		* VisibleDefaultsOnly	仅在蓝图类的默认值中可见。 当您打开蓝图类，查看其“类默认值 (Class Defaults)”时可见。当它被拖入场景成为实例后，在实例的细节面板中不可见。	蓝图默认值
		* VisibleInstanceOnly	仅在场景实例中可见。 在蓝图类的默认值中不可见。	场景实例
	* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		* 对BluePrint暴露时不能设置private
		* BlueprintReadOnly	 蓝图只读。	在蓝图图表中，您只能拖出引脚或使用 “Get” 节点来获取该属性的值。	允许蓝图查看 C++ 属性，但不能修改。常用于公开 C++ 的内部状态。
		* BlueprintReadWrite 蓝图读写。	在蓝图图表中，您可以拖出引脚，也可以使用 “Get” 节点获取值，以及使用 “Set” 节点设置值。	允许蓝图完全控制该 C++ 属性的值。
	* -----------------------------------------------------------------------------Category-----------------------------------------------------------------------------------------------------
		* Category=细节面板 (Details Panel) 和蓝图节点搜索列表 (Blueprint Node Search) 中所属的分类名称
			* 使用竖线 | 创建子分类： 例如 $\text{Category = "Combat|Damage"}$ 会创建一个 Combat 分类下的 Damage 子分类，有助于保持细节面板的整洁。
	* ----------------------------------------Meta--------------------------------------------------------------------------------------------------------------------------------------------------------
		* Meta:用于向 UE 的反射系统传递额外的、非标准化的元数据
		*	AllowPrivateAccess = "true"：允许蓝图访问私有 (private) 或受保护 (protected) 的 C++ 成员变量或函数。
			ToolTip,在编辑器中显示工具提示。 当鼠标悬停在属性或函数上时，显示帮助文本。,"UPROPERTY(EditAnywhere, meta=(ToolTip=""角色的最大生命值。""))"
			ClampMin / ClampMax,在细节面板中限制输入范围。 仅用于编辑器界面，运行时代码仍需使用 FMath::Clamp。,"UPROPERTY(EditAnywhere, meta=(ClampMin=""0.0"", ClampMax=""100.0""))"
			Units,为属性值添加单位后缀。 提高可读性。,"UPROPERTY(EditAnywhere, meta=(Units=""cm/s""))"
			AllowedClasses,限制引用变量只能接受某些类型的资产或类。,"UPROPERTY(EditAnywhere, meta=(AllowedClasses=""Blueprint, StaticMesh""))"
			MakeEditWidget,（用于 FVector/FRotator） 在场景中显示可拖动的 gizmo 小工具来编辑值。,"UPROPERTY(EditAnywhere, meta=(MakeEditWidget=true))"
			EditCondition,条件编辑。 只有当另一个属性为特定值时，该属性才可被编辑（启用）。,"UPROPERTY(EditAnywhere, meta=(EditCondition=""bIsActive""))"
			DeprecationMessage,弃用警告。 在蓝图中使用时发出警告，提示该函数/属性已被弃用。,"UFUNCTION(meta=(DeprecationMessage=""请改用NewFunction.""))"
	*/
	UPROPERTY(VisibleAnywhere)
	float RunningTime = 0.0F;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Sets default values for this actor's properties
	AItem_SinFuncTest();
protected:

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="OVERLXRD")
	float floatHeight = 1.0F;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OVERLXRD")
	float moveSpeed = 6.0F;


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	/* UFunction:
	* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		BlueprintCallable	允许在蓝图图表中被调用。这是 C++ 函数暴露给蓝图使用最常见的修饰符。	在蓝图事件图表 (Event Graph) 中作为普通节点执行。
		BlueprintPure	允许在蓝图图表中被调用，且是“纯净”的。 它没有执行引脚，只能作为取值节点。它不应该修改所属对象的状态。	用于计算属性或执行无副作用的查询，例如 GetHealth()，不需要前因后果就可以执行的
		BlueprintImplementableEvent	蓝图实现事件。 该函数在 C++ 中只有声明，没有定义。它要求在子蓝图类中实现其逻辑。	C++ 通知蓝图发生了一个事件（例如 OnKilled()）。
		BlueprintNativeEvent	蓝图原生事件。 允许在 C++ 中提供一个默认实现，但也可以被子蓝图类重写。	提供了 C++ 默认行为，同时允许蓝图自定义逻辑。
	* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	*	也能使用Category
	
	*/
	UFUNCTION(BlueprintCallable)
	float transformedSin_callable(float Value);

	UFUNCTION(BlueprintPure)
	float transformedSin_callable_noarg();

	UFUNCTION(BlueprintCallable)
	float transformedCos_callable(float Value);

	template<typename T>
	T AVG(T A, T B);
};

template<typename T>
inline T AItem_SinFuncTest::AVG(T A, T B)
{
	return (A + B) / 2;
}
