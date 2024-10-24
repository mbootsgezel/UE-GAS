// Copyright 2021 Joseph "Narxim" Thigpen.


#include "EnergyAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

UEnergyAttributeSet::UEnergyAttributeSet() {
	MaximumEnergy = 0.0f;
	CurrentEnergy = 0.0f;
	EnergyRegeneration = 0.0f;
}


void UEnergyAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetMaximumEnergyAttribute())
	{
		AdjustAttributeForMaxChange(CurrentEnergy, MaximumEnergy, NewValue, GetCurrentEnergyAttribute());
	}
}

void UEnergyAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetCurrentEnergyAttribute())
	{
		SetCurrentEnergy(FMath::Clamp(GetCurrentEnergy(), 0.0f, GetMaximumEnergy()));
	}

	else if (Data.EvaluatedData.Attribute == GetEnergyRegenerationAttribute())
	{
		SetEnergyRegeneration(FMath::Clamp(GetEnergyRegeneration(), 0.0f, GetMaximumEnergy()));
	}
}

void UEnergyAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UEnergyAttributeSet, CurrentEnergy, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UEnergyAttributeSet, MaximumEnergy, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UEnergyAttributeSet, EnergyRegeneration, COND_None, REPNOTIFY_Always);
}

void UEnergyAttributeSet::OnRep_CurrentEnergy(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UEnergyAttributeSet, CurrentEnergy, OldValue);
}

void UEnergyAttributeSet::OnRep_MaximumEnergy(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UEnergyAttributeSet, MaximumEnergy, OldValue);
}

void UEnergyAttributeSet::OnRep_EnergyRegeneration(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UEnergyAttributeSet, EnergyRegeneration, OldValue);
}

