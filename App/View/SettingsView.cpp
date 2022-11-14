#include "App/App.h"
#include "SettingsView.h"

#include "View/Button.h"
#include "View/Text.h"

#include <iostream>


SettingsView::SettingsView()
	: View(App::getSDLWindow(), App::getSDLRenderer())
{
	this->setBackgroundColor(240, 240, 240);
	this->setFont(App::getSDLDefaultFont());
	
	Button* button1 = new Button("Menu");
	{
		button1->setPosition(10, 400);
		button1->setSize(180, 50);
		button1->setOnClickCallback([]() {
			App::setCurrentView(App::getViewMainMenu());
			});
		this->addWidget(button1);
	}
}
