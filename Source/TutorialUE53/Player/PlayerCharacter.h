#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class TUTORIALUE53_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:

	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* SwordMesh;

	UPROPERTY(EditAnywhere)
	class UAnimSequence* AttackAnimaton;

	void MoveForward(float InputValue);
	void MoveRight(float InputValue);

	void Turn(float InputValue);
	void LookUp(float InputValue);

	// Attack
	UPROPERTY(EditAnywhere)
	int Damage;

	void StartAttack();

public:

	UFUNCTION(BlueprintCallable)
	void LineTrace();

	UPROPERTY(BlueprintReadWrite)
	bool bIsAttacking;

};
