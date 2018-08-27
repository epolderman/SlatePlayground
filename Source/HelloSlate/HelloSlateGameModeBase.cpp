// Fill out your copyright notice in the Description page of Project Settings.

#include "HelloSlateGameModeBase.h"
#include "StandardHUD.h"


// attach hud to our game mode


AHelloSlateGameModeBase::AHelloSlateGameModeBase() : Super() 
{ 
	HUDClass = AStandardHUD::StaticClass(); 
}