// Richard H�hne 2019
#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "MyAttributeSet.generated.h"

// Uses macros from AttributeSet.h
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 *
 */
UCLASS()
class UE4_GAS_PREDICTION_API UMyAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	UPROPERTY(ReplicatedUsing = OnRep_MyAttribute, EditAnywhere, BlueprintReadWrite, Category = MyAttributeSet)
	FGameplayAttributeData MyAttribute { 100.f };
	ATTRIBUTE_ACCESSORS(UMyAttributeSet, MyAttribute)
	UFUNCTION() void OnRep_MyAttribute(const FGameplayAttributeData& OldValue) { GAMEPLAYATTRIBUTE_REPNOTIFY(UMyAttributeSet, MyAttribute, OldValue); }
};
