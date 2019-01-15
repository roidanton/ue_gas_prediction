// Richard Hähne 2019

#include "MyAttributeSet.h"

#include "UnrealNetwork.h"

void UMyAttributeSet::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UMyAttributeSet, MyAttribute, COND_None, REPNOTIFY_Always);
}