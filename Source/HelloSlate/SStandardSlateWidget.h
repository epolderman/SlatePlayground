// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

class HELLOSLATE_API SStandardSlateWidget : public SCompoundWidget
{

	SLATE_BEGIN_ARGS(SStandardSlateWidget)
	{}
	SLATE_ARGUMENT(TWeakObjectPtr<class AStandardHUD>, OwnerHUDArg)
	SLATE_END_ARGS()

public:
	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	
	FReply ButtonClicked();

	void ButtonHovered();
private:
	// ++ Pointer to our parent HUD. To make sure HUD's lifetime is controlled elsewhere, use "weak" ptr. 
	// ++ HUD has a "strong" pointer to Widget, circular ownership would prevent/break self-destruction of hud/widget (cause a memory leak). 
	TWeakObjectPtr<class AStandardHUD> OwnerHUD;
	
};
