#include "App/App.h"
#include "ShoppingListView.h"

#include "View/Button.h"
#include "View/Text.h"
#include "View/Forms.h"

ShoppingListView::ShoppingListView()
	: View(App::getSDLWindow(), App::getSDLRenderer())
{
	this->setBackgroundColor(82, 89, 92);
	this->setFont(App::getSDLDefaultFont());

	Rect* rectTitle = new Rect();
	{
		rectTitle->setPosition(0, 70);
		rectTitle->setSize(750, 110);
		rectTitle->setColor(181, 222, 255);
		this->addWidget(rectTitle);
	}

	Text* title = new Text();
	{
		title->setPosition(10, 105);
		title->setText("SHOPPING LIST");
		title->setColor(0, 0, 0);
		this->addWidget(title);
		title->setHorizontallyCentered();
	}

	Button* returnBtn = new Button("Return");
	{
		returnBtn->setPosition(40, 700);
		returnBtn->setSize(BUTTON_WIDTH, BUTTON_HEIGHT);
		returnBtn->setColor(220, 220, 220);
		returnBtn->setOnClickCallback([]() {
			App::setCurrentView(App::getViewMainMenu());
			});
		this->addWidget(returnBtn);
		returnBtn->setHorizontallyCentered();
	}
}
