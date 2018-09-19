// Fill out your copyright notice in the Description page of Project Settings.

#include "SStandardSlateWidget.h"
#include "SlateOptMacros.h"
#include "Engine.h"

#define LOCTEXT_NAMESPACE "SStandardSlateWidget"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

// acts as a constructor
void SStandardSlateWidget::Construct(const FArguments& InArgs) 
{

	// pass in our arguments
	OwnerHUD = InArgs._OwnerHUD;
	

		// onClicked takes (ptr to widget, delegate(pointer to method) 
		ChildSlot
		.VAlign(VAlign_Center)
		.HAlign(HAlign_Center)
		[
			SNew(SButton)
			.VAlign(VAlign_Center)
			.HAlign(HAlign_Center)
			.OnHovered_Raw(this, &SStandardSlateWidget::ButtonHovered)
			.ButtonColorAndOpacity(FSlateColor(FLinearColor(0.1f, 0.5f, 0.5f, 1.0f)))
			.Text(this->buttonLabel.FromString("Slate Button")).DesiredSizeScale(FVector2D(5.0f,5.0f))
			.OnClicked(this, &SStandardSlateWidget::ButtonClicked)
			.ToolTipText(this->buttonLabel.FromString("Tool Tip!"))
		];

}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

#undef LOCTEXT_NAMESPACE

FReply SStandardSlateWidget::ButtonClicked() {
	if (GEngine != NULL) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("You clicked a button!"));
	}

	// prevents the event from bubbling up the parent widget
	return FReply::Handled();
}

void SStandardSlateWidget::ButtonHovered() {
	if (GEngine != NULL) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Hovering"));
	}
}


