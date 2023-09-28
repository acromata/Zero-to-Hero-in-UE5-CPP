#include "TutorialUE53/Components/HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	bCanTakeDamage = true;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	
}


void UHealthComponent::Die()
{
	GetOwner()->Destroy();
}

void UHealthComponent::TakeDamage(int Damage)
{
	if (bCanTakeDamage)
	{
		Health -= Damage;
		bCanTakeDamage = false;

		// delay
		FTimerHandle InvincibilityDelay;
		GetWorld()->GetTimerManager().SetTimer(InvincibilityDelay, this, &UHealthComponent::AllowTakeDamage, 0.5f, false);

		// die function
		if (Health <= 0)
		{
			Die();
		}
	}
}

void UHealthComponent::AllowTakeDamage()
{
	bCanTakeDamage = true;
}