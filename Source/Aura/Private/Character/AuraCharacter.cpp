// Copyright Studio3F


#include "Character/AuraCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"


AAuraCharacter::AAuraCharacter()
{

}

void AAuraCharacter::BeginPlay()
{
	Super::BeginPlay();
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}