// Richard Hähne 2019

#include "MyCharacter.h"

#include "MyAttributeSet.h"

AMyCharacter::AMyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	this->ASC = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("ASC"));
	this->AttributeSet = CreateDefaultSubobject<UMyAttributeSet>(TEXT("AttributeSet"));
}

void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (ASC)
	{
		ASC->GetGameplayAttributeValueChangeDelegate(UMyAttributeSet::GetMyAttributeAttribute()).AddUObject(this, &AMyCharacter::OnMyAttributeValueChange);
	}
}

UAbilitySystemComponent* AMyCharacter::GetAbilitySystemComponent() const
{
	return ASC;
}

void AMyCharacter::Restart()
{
	Super::Restart();
	if (this->ASC)
	{
		ASC->InitAbilityActorInfo(this, this);
	}
}

void AMyCharacter::AquireAbility(TSubclassOf<UGameplayAbility> AbilityToAquire)
{
	if (this->ASC && AbilityToAquire)
	{
		if (this->HasAuthority())
		{
			ASC->GiveAbility(FGameplayAbilitySpec(AbilityToAquire));
		}
	}
}

void AMyCharacter::OnMyAttributeValueChange(const FOnAttributeChangeData& Data)
{
	if (GEngine)
	{
		constexpr auto displayDuration = 999.f;
		const FString instance = GetWorld()->IsServer() ? "Server" : "Client";
		FString role;
		switch (Role)
		{
		case ROLE_Authority: role = "Authority"; break;
		case ROLE_AutonomousProxy: role = "Owner"; break;
		case ROLE_SimulatedProxy: role = "Proxy"; break;
		default: role = {};
		}
		auto color = FColor::Emerald;
		auto comparison = FString(">");
		if (Data.OldValue == Data.NewValue)
		{
			color = FColor::Orange;
			comparison = "=";
		}
		else if (Data.OldValue < Data.NewValue)
		{
			color = FColor::Magenta;
			comparison = "<";
		}
		GEngine->AddOnScreenDebugMessage(-1, displayDuration, color,
			FString::Printf(TEXT("(%s, %s) %s changed value on %s: OldValue  %g  %s NewValue  %g"),
				*instance,
				*role,
				*Data.Attribute.AttributeName,
				*this->GetName(),
				Data.OldValue,
				*comparison,
				Data.NewValue));
	}
}
