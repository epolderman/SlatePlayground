// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "StandardHUD.h"



class HELLOSLATE_API SStandardSlateWidget : public SCompoundWidget
{
	// find out what these are
	SLATE_BEGIN_ARGS(SStandardSlateWidget)
	{}
	// slate arguments (type, name of type) => passing args to widgets constructing function
	SLATE_ARGUMENT(class AStandardHUD*, hudController)
	
	SLATE_END_ARGS()

public:
	/** Constructs this widget with InArgs */
	/* Acts as a constructor */
	void Construct(const FArguments & InArgs);
	// action/delegate for clicking
	FReply ButtonClicked();
	// why does this have to void, and not FReply?
	void ButtonHovered();
private:

	// Pointer to our parent HUD. To make sure HUD's lifetime is controlled elsewhere, use "weak" ptr. 
	// HUD has a "strong" pointer to Widget, circular ownership would prevent/break self-destruction of hud/widget (cause a memory leak). 
	// Is there a better way to handle this? Why must we pass the HUD as an argument to the widget?
	TWeakObjectPtr<class AStandardHUD> HUD;
	FText buttonLabel;
};
