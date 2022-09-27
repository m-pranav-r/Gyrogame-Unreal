#include "PlayerPawn.h"
// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	/*Super::BeginPlay();
	
	HUDObj = Cast<AFinalHUD>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());

	if (HUDObj == nullptr) return;

	UE_LOG(LogTemp, Warning, TEXT("PlayerPawn has caught HUD."));

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATestActor::StaticClass(), ActorArray);*/
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	/*Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveReticleX", this, &APlayerPawn::MoveCrosshairX);

	InputComponent->BindAxis("MoveReticleY", this, &APlayerPawn::MoveCrosshairY);

	InputComponent->BindAction("TestReticle", IE_Pressed, this, &APlayerPawn::SendHitRay);

	UE_LOG(LogTemp, Warning, TEXT("Bindings complete."));*/

}


void APlayerPawn::SendHitRay()
{
	FVector2D HitLoc = HUDObj->GetImageCoords();

	for (AActor* ActorIter : ActorArray)
	{
		FVector2D ScreenPos;

		UGameplayStatics::ProjectWorldToScreen(UGameplayStatics::GetPlayerController(GetWorld(), 0), ActorIter->GetActorLocation(), ScreenPos);

		if (ScreenPos.Distance(ScreenPos, HitLoc) <= Hit_Dist)
		{
			ATestActor* TempActor = Cast<ATestActor>(ActorIter);

			TempActor->Register_Hit();

			UE_LOG(LogTemp, Warning, TEXT("Hit Registered."));
		}

		else
		{
			UGameplayStatics::ProjectWorldToScreen(UGameplayStatics::GetPlayerController(GetWorld(), 0), ActorIter->GetActorLocation(), ScreenPos);

			UE_LOG(LogTemp, Warning, TEXT("Dist = %i"), ScreenPos.Distance(ScreenPos, HitLoc));

		}
	}
}