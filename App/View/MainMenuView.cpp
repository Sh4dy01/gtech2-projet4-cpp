#include "App/App.h"
#include "MainMenuView.h"

#include "View/Button.h"
#include "View/Text.h"

#include <iostream>



MainMenuView::MainMenuView()
	: View(App::getSDLWindow(), App::getSDLRenderer())
{
	this->setBackgroundColor(240, 240, 240);
	this->setFont(App::getSDLDefaultFont());

	Button* button = new Button("Exit");
	{
		button->setPosition(20, 60);
		button->setSize(80, 0);
		button->setOnClickCallback([]() {
			App::setShouldClose();
		});
		this->addWidget(button);
		button->setHorizontallyCentered();
	}

	Button* button0 = new Button("Press Me!");
	{
		button0->setPosition(10, 120);
		button0->setSize(180, 0);
		button0->setOnClickCallback([]() {
			std::cout << "I have been pressed!" << std::endl;
		});
		this->addWidget(button0);
	}

	Text* title = new Text();
	{
		title->setPosition(10, 10);
		title->setColor(0, 127, 127);
		title->setText("Bib.io");
		this->addWidget(title);
		title->setHorizontallyCentered();
	}

	Button* button2 = new Button("Liste de course");
	{
		button2->setPosition(40, 700);
		button2->setSize(400, 0);
		button2->setOnClickCallback([]() {
			App::setCurrentView(App::getViewSettings());
			});
		this->addWidget(button2);
	}

	Button* button1 = new Button("Settings");
	{
		button1->setPosition(40, 760);
		button1->setSize(400, 0);
		button1->setOnClickCallback([]() {
			App::setCurrentView(App::getViewSettings());
		});
		this->addWidget(button1);
	}
}
