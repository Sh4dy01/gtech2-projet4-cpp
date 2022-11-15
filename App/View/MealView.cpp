#include "App/App.h"
#include "MealView.h"

#include "View/Button.h"
#include "View/Text.h"
#include "View/Forms.h"


MealView::MealView()
	: View(App::getSDLWindow(), App::getSDLRenderer())
{
	this->setBackgroundColor(82, 89, 92);
	this->setFont(App::getSDLDefaultFont());

	Rect* rectTitle = new Rect();
	{
		rectTitle->setPosition(0, 70);
		rectTitle->setSize(WINDOW_WIDTH, 110);
		rectTitle->setColor(245, 240, 187);
		this->addWidget(rectTitle);
	}

	Text* title = new Text();
	{
		title->setPosition(10, 75);
		title->setText("Meal insertion of the");
		title->setColor(0, 0, 0);
		this->addWidget(title);
		title->setHorizontallyCentered();
	}

	Button* returnBtn = new Button("Return");
	{
		returnBtn->setPosition(50, 700);
		returnBtn->setSize(BUTTON_WIDTH, BUTTON_HEIGHT);
		returnBtn->setColor(220, 220, 220);
		returnBtn->setOnClickCallback([]() {
			App::setCurrentView(App::getViewMainMenu());
			});
		this->addWidget(returnBtn);
		returnBtn->setHorizontallyCentered();
	}
}
