// Copyright Studio3F

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "TargetDataUnderMouse.generated.h"

// 1. Output Execution Pin 정의 (비동기 완료 시 실행될 핀)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMouseTargetDataSignature, const FGameplayAbilityTargetDataHandle&, DataHandle);

/**
 * 
 */
UCLASS()
class AURA_API UTargetDataUnderMouse : public UAbilityTask
{
	GENERATED_BODY()
public:
	// 2. Factory Function: 블루프린트 노드 생성자
	UFUNCTION(BlueprintCallable, Category = "Ability|Tasks", meta = (DisplayName = "TargetDataUnderMouse", HidePin = "OwningAbility", DefaultToSelf = "OwningAbility", BlueprintInternalUseOnly = "true"))
	static UTargetDataUnderMouse* CreateTargetDataUnderMouse(UGameplayAbility* OwningAbility);

	// 3. Delegate Property: 블루프린트 핀으로 노출됨
	UPROPERTY(BlueprintAssignable)
	FMouseTargetDataSignature ValidData;

private:
	// 4. Activate Override: 실제 로직 진입점
	virtual void Activate() override;

	void SendMouseCursorData();
};
