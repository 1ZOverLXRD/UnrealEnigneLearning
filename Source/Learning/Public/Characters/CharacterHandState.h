#pragma once

//UE中使用enum class 来声明枚举类型，防止枚举常量内容一致
//前缀以E+枚举缩写来写常量内容
//UENUM(BlueprintType)暴露给蓝图s

UENUM(BlueprintType)
enum class ECharacterState :uint8 {
	ECS_Unequipped UMETA(DisplayName = "未装备武器"),
	ECS_EquippedOneHandWeapon UMETA(DisplayName = "装备单手武器"),
	ECS_EquippedTwoHandWeapon UMETA(DisplayName = "装备双手武器")
};