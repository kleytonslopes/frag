// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(36.f, 99.f);

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetRelativeLocation(FVector(0.f, 0.f, 79.79));
	CameraComp->SetupAttachment(GetCapsuleComponent());
	CameraComp->bUsePawnControlRotation = true;
	
	TurnBase = 50.f;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis("TurnHorizontal", this, &APlayerCharacter::TurnHorizontal);
	PlayerInputComponent->BindAxis("TurnVertical", this, &APlayerCharacter::TurnVertical);
	
}

void APlayerCharacter::MoveForward(float value)
{
	if (value != 0.f)
	{
		AddMovementInput(GetActorForwardVector(), value);
	}
}

void APlayerCharacter::MoveRight(float value)
{
	if (value != 0.f)
	{
		AddMovementInput(GetActorRightVector(), value);
	}
}

void APlayerCharacter::TurnHorizontal(float value)
{
	if (value != 0.f)
	{
		AddControllerYawInput(value * TurnBase * GetWorld()->GetDeltaSeconds());
	}
}

void APlayerCharacter::TurnVertical(float value)
{
	if (value != 0.f)
	{
		AddControllerPitchInput(-value * TurnBase * GetWorld()->GetDeltaSeconds());
	}
}
