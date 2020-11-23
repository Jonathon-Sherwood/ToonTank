// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerController_Base.h"


void APlayerController_Base::SetPlayerEnabledState(bool SetPlayerEnabled)
{
	if (SetPlayerEnabled)
	{
		GetPawn()->EnableInput(this);
	}
	else
	{
		GetPawn()->DisableInput(this);
	}
}