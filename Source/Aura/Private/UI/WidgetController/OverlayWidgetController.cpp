// Copyright Studio3F


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UAuraAttributeSet* AS = CastChecked<UAuraAttributeSet>(AttributeSet);
	
	OnHealthChanged.Broadcast(AS->GetHealth());
	OnMaxHealthChanged.Broadcast(AS->GetMaxHealth());
	
	OnManaChanged.Broadcast(AS->GetMana());
	OnMaxManaChanged.Broadcast(AS->GetMaxMana());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UAuraAttributeSet* AS = CastChecked<UAuraAttributeSet>(AttributeSet);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AS->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AS->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
	AS->GetManaAttribute()).AddUObject(this, &UOverlayWidgetController::ManaChanged);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AS->GetMaxManaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxManaChanged);
	
	Cast<UAuraAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda(
		[](const FGameplayTagContainer& AssetTags)
		{
				
			for (const FGameplayTag& Tag : AssetTags)
			{
				//TODO: Broadcast the tag to the Widget Controller
				const FString MSG = FString::Printf(TEXT("GE Tag: %s"), *Tag.ToString());
				GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Blue, MSG);
			}
		}	
	);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}
