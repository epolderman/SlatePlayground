// Fill out your copyright notice in the Description page of Project Settings.

#include "SStandardSlateWidget.h"
#include "SlateOptMacros.h"
#include "Engine.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SStandardSlateWidget::Construct(const FArguments& InArgs)
{

	// ++ Assign the argument to our local variable
	// name will be _OwnerHUDArg instead of OwnerHUDArg, see comments about SLATE_ARGUMENT before
	OwnerHUD = InArgs._OwnerHUDArg;
	

	// onClicked takes (ptr to widget, delegate(pointer to method) 
		ChildSlot
		.VAlign(VAlign_Center)
		.HAlign(HAlign_Center)
		[
			SNew(SButton)
			.VAlign(VAlign_Center)
			.HAlign(HAlign_Center)
			.OnHovered_Raw(this, &SStandardSlateWidget::ButtonHovered)
			.ButtonColorAndOpacity(FSlateColor(FLinearColor(0.5f, 0.5f, 0.5f,1.0f)))
			.Text(FText::FromString("Slate Button")).DesiredSizeScale(FVector2D(5.0f,5.0f))
			.OnClicked(this, &SStandardSlateWidget::ButtonClicked)
		];

}

FReply SStandardSlateWidget::ButtonClicked() {
	if (GEngine != NULL) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Button Clicked!"));
	}

	// prevents the event from bubbling up the parent widget
	return FReply::Handled();
}

void SStandardSlateWidget::ButtonHovered() {
	if (GEngine != NULL) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Hovering"));
	}
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
