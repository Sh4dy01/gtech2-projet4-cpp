#include "App/App.h"
#include "MainMenuView.h"

#include "View/Button.h"
#include "View/Text.h"

#include <iostream>
#include <SDL_image.h>



MainMenuView::MainMenuView()
	: View(App::getSDLWindow(), App::getSDLRenderer())
{
	this->setBackgroundColor(240, 240, 240);
	this->setFont(App::getSDLDefaultFont());

	Button* button = new Button("Exit");
	{
		button->setPosition(20, 60);
		button->setSize(80, 40);
		button->setOnClickCallback([]() {
			App::setShouldClose();
		});
		this->addWidget(button);
		button->setHorizontallyCentered();
	}

	Button* button0 = new Button("Press Me!");
	{
		button0->setPosition(10, 120);
		button0->setSize(180, 40);
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
	Button* button3= new Button("New meal");
	{
		button3->setPosition(50, 640);
		button3->setSize(380, 50);
		button3->setOnClickCallback([]() {
			App::setCurrentView(App::getViewMeal());
			});
		this->addWidget(button3);
	}

	Button* button2 = new Button("Shopping list");
	{
		button2->setPosition(50, 700);
		button2->setSize(380, 50);
		button2->setOnClickCallback([]() {
			App::setCurrentView(App::getViewShoppingList());
			});
		this->addWidget(button2);
	}

	Button* button1 = new Button("Settings");
	{
		button1->setPosition(50, 760);
		button1->setSize(380, 50);
		button1->setOnClickCallback([]() {
			App::setCurrentView(App::getViewSettings());
		});
		this->addWidget(button1);
	}
}