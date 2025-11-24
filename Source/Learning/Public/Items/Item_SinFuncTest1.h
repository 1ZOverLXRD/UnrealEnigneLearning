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
	* UPROPERTY  :  ô˱      뵽   价  ,        ¶   ༭  (private  ͼ ò   )
		* EditAnywhere:   κεط  ɱ༭  (only:  ͼ+ʾ  )
		* EditDefaultsOnly:ֻ      Ĭ ϶   (  ͼ  Ĭ  ֵ) б༭,ʵ        (    Ϸ  ͼ  )   ɱ༭ (only:  ͼ)
		* EditInstanceOnly:ֻ    ʵ         б༭,  Ĭ ϶  󲻿ɱ༭   only:ʵ  )
	* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		* VisibleAnywhere	   κεط  ɼ                       ͼ  Ĭ  ֵ         ڳ    з  õ ʵ         ǿɼ      ɱ༭ ġ 	  ͼĬ  ֵ +     ʵ  
		* VisibleDefaultsOnly	      ͼ   Ĭ  ֵ пɼ            ͼ ࣬ 鿴 䡰  Ĭ  ֵ (Class Defaults)  ʱ ɼ            볡    Ϊʵ      ʵ    ϸ      в  ɼ   	  ͼĬ  ֵ
		* VisibleInstanceOnly	   ڳ   ʵ   пɼ        ͼ   Ĭ  ֵ в  ɼ   	    ʵ  
	* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*   BluePrint  ¶ʱ        private
		* BlueprintReadOnly	   ͼֻ    	    ͼͼ   У   ֻ   ϳ    Ż ʹ     Get    ڵ     ȡ     Ե ֵ  	      ͼ 鿴 C++    ԣ        ޸ġ      ڹ    C++    ڲ ״̬  
		* BlueprintReadWrite   ͼ  д  	    ͼͼ   У        ϳ    ţ Ҳ    ʹ     Get    ڵ  ȡֵ   Լ ʹ     Set    ڵ     ֵ  	      ͼ  ȫ   Ƹ  C++    Ե ֵ  
	* -----------------------------------------------------------------------------Category-----------------------------------------------------------------------------------------------------
		* Category=ϸ      (Details Panel)     ͼ ڵ      б  (Blueprint Node Search)       ķ       
			* ʹ       |      ӷ  ࣺ      $\text{Category = "Combat|Damage"}$  ᴴ  һ   Combat      µ  Damage  ӷ  ࣬     ڱ   ϸ         ࡣ
	* ----------------------------------------Meta--------------------------------------------------------------------------------------------------------------------------------------------------------
		* Meta:       UE  ķ   ϵͳ   ݶ   ġ  Ǳ ׼    Ԫ    
		*	AllowPrivateAccess = "true"        ͼ    ˽   (private)    ܱ    (protected)    C++   Ա          
			ToolTip, ڱ༭      ʾ      ʾ          ͣ     Ի     ʱ    ʾ     ı   ,"UPROPERTY(EditAnywhere, meta=(ToolTip=""  ɫ         ֵ  ""))"
			ClampMin / ClampMax,  ϸ              뷶Χ        ڱ༭     棬    ʱ        ʹ   FMath::Clamp  ,"UPROPERTY(EditAnywhere, meta=(ClampMin=""0.0"", ClampMax=""100.0""))"
			Units,Ϊ    ֵ  ӵ λ  ׺     ߿ɶ  ԡ ,"UPROPERTY(EditAnywhere, meta=(Units=""cm/s""))"
			AllowedClasses,       ñ   ֻ ܽ   ĳЩ   ͵  ʲ    ࡣ,"UPROPERTY(EditAnywhere, meta=(AllowedClasses=""Blueprint, StaticMesh""))"
			MakeEditWidget,       FVector/FRotator    ڳ       ʾ   ϶    gizmo С       ༭ֵ  ,"UPROPERTY(EditAnywhere, meta=(MakeEditWidget=true))"
			EditCondition,     ༭   ֻ е   һ      Ϊ ض ֵʱ       Բſɱ  ༭     ã   ,"UPROPERTY(EditAnywhere, meta=(EditCondition=""bIsActive""))"
			DeprecationMessage,   þ  档     ͼ  ʹ  ʱ       棬  ʾ ú   /     ѱ    á ,"UFUNCTION(meta=(DeprecationMessage=""     NewFunction.""))"
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
		BlueprintCallable	        ͼͼ   б    á      C++       ¶    ͼʹ          η   	    ͼ ¼ ͼ   (Event Graph)     Ϊ  ͨ ڵ ִ С 
		BlueprintPure	        ͼͼ   б    ã    ǡ        ġ    û  ִ     ţ ֻ    Ϊȡֵ ڵ㡣    Ӧ   ޸         ״̬  	   ڼ      Ի ִ   ޸    õĲ ѯ       GetHealth()      Ҫǰ     Ϳ   ִ е 
		BlueprintImplementableEvent	  ͼʵ   ¼     ú      C++   ֻ        û ж  塣  Ҫ        ͼ    ʵ     ߼   	C++ ֪ͨ  ͼ      һ   ¼        OnKilled()    
		BlueprintNativeEvent	  ͼԭ   ¼           C++    ṩһ  Ĭ  ʵ ֣   Ҳ   Ա     ͼ    д  	 ṩ   C++ Ĭ    Ϊ  ͬʱ      ͼ Զ    ߼   
	* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	*	Ҳ  ʹ  Category
	
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
