// Copyright 2021 Joseph "Narxim" Thigpen.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSetBase.h"
#include "EnergyAttributeSet.generated.h"

// Contains Attributes related to Energy. Any Character that uses Energy will need this Attribute Set.
//
// Contents:
//
//	CurrentEnergy - Primarily used as a cost resource for Abilities.
//	MaximumEnergy - The maximum amount of Energy the Character can have.
//	EnergyRegeneration - How much Energy is gained per period of Regeneration.
UCLASS()
class GAS_EXAMPLE_API UEnergyAttributeSet : public UAttributeSetBase
{
	GENERATED_BODY()
	
public:
	UEnergyAttributeSet();

	// Attribute Set Overrides.
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	// Set Attributes to replicate.
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// Holds the current value for Energy.
	UPROPERTY(BlueprintReadOnly, Category = "Energy Attribute Set", ReplicatedUsing = OnRep_CurrentEnergy)
	FGameplayAttributeData CurrentEnergy;
	ATTRIBUTE_ACCESSORS(UEnergyAttributeSet, CurrentEnergy)

	// Holds the value for Maximum Energy.
	UPROPERTY(BlueprintReadOnly, Category = "Energy Attribute Set", ReplicatedUsing = OnRep_MaximumEnergy)
	FGameplayAttributeData MaximumEnergy;
	ATTRIBUTE_ACCESSORS(UEnergyAttributeSet, MaximumEnergy)

	// Holds the current value for Energy Regeneration.
	UPROPERTY(BlueprintReadOnly, Category = "Energy Attribute Set", ReplicatedUsing = OnRep_EnergyRegeneration)
	FGameplayAttributeData EnergyRegeneration;
	ATTRIBUTE_ACCESSORS(UEnergyAttributeSet, EnergyRegeneration)

protected:
	
	UFUNCTION()
	virtual void OnRep_CurrentEnergy(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_MaximumEnergy(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_EnergyRegeneration(const FGameplayAttributeData& OldValue);
};
