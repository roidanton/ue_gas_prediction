// Richard Hähne 2019

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "MyCharacter.generated.h"

UCLASS()
class UE4_GAS_PREDICTION_API AMyCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AMyCharacter();
protected:
	virtual void BeginPlay() override;
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AbilityOnCharacter)
	UAbilitySystemComponent* ASC;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AbilityOnCharacter)
	class UMyAttributeSet* AttributeSet;
	UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	void Restart() override;
	UFUNCTION(BlueprintCallable, Category = AbilityOnCharacter)
	void AquireAbility(TSubclassOf<class UGameplayAbility> AbilityToAquire);
	void OnMyAttributeValueChange(const FOnAttributeChangeData& Data);
};
