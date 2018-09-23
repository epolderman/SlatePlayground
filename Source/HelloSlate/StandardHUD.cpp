// Fill out your copyright notice in the Description page of Project Settings.

#include "StandardHUD.h"
#include "SStandardSlateWidget.h"

// ++ The SWeakWidget we are using
#include "Widgets/SWeakWidget.h" 

// ++ To use GEngine. You can also import just "Engine.h" but some people mention this compiles slower than this header.
#include "Engine.h" 
#include <DeclarativeSyntaxSupport.h>
#include <Attribute.h>


// HUD that owns the widget

// answer these questions!
// should the HUD act as a central controller to the widgets and pass polling data to the components?
// can I pass in arguments through the HUD to my widgets?
// are the massive macro's for slate arguments passed in as construction?

void AStandardHUD::BeginPlay()
{
	// So far only TSharedPtr<SMyUIWidget> has been created, now create the actual object.
	// Create a SMyUIWidget on heap, our MyUIWidget shared pointer provides handle to object
	// Widget will not self-destruct unless the HUD's SharedPtr (and all other SharedPtrs) are destroyed first.
	MyUIWidget = SNew(SStandardSlateWidget);
	// MyUIWidget = SNew(SStandardSlateWidget).OwnerHUD(this);

	// Pass our viewport a weak ptr to our widget
	// View port's weak ptr will not give Viewport ownership of Widget
	if (GEngine != NULL) {
		GEngine->GameViewport->AddViewportWidgetContent(
			SNew(SWeakWidget)
			.PossiblyNullContent(MyUIWidget.ToSharedRef())
		);
	}

	// Set widget's properties as visible (sets child widget's properties recursively)
	MyUIWidget->SetVisibility(EVisibility::Visible);
}

void AStandardHUD::getPlayerHealth() {
	const FString pHealth = " " + this->playerHealth;
	if (GEngine != NULL) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, pHealth);
	}
}

FReply AStandardHUD::handleButton() {
	if (GEngine != NULL) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("HUD: You clicked a button!"));
	}

	// prevents the event from bubbling up the parent widget
	return FReply::Handled();
}
