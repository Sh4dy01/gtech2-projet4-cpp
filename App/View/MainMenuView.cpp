#include "App/App.h"
#include "MainMenuView.h"
#include "../bib.h"

#include "View/Button.h"
#include "View/Text.h"
#include "View/Image.h"
#include "View/Forms.h"


#include <iostream>
#include <SDL_image.h>

static int BIBI_INDICATOR_START = 123;

static int INDICATOR_OFFSET_X = 11;
static int INDICATOR_OFFSET_Y = 120;
static int INDICATOR_FULL_OFFSET = 234;

static int LIMIT_INDICATOR_OFFSET_X = 12;
static int LIMIT_INDICATOR_FULL = 352;
static float LIMIT_INDICATOR_Y_STEP = (LIMIT_INDICATOR_FULL - (float)BIBI_INDICATOR_START) / 100;
static float LIMIT_INDICATOR_WIDTH_RATIO = 0.866;

MainMenuView::MainMenuView()
	: View(App::getSDLWindow(), App::getSDLRenderer())
{
	Bib* bib = App::GetBibi();
	int currentQuantity = ((float)bib->GetBibQty() / bib->GetMaxBib()) * 100;

	this->setBackgroundColor(82, 89, 92);
	this->setFont(App::getSDLDefaultFont());

	Rect* rectTitle = new Rect();
	{
		rectTitle->setPosition(0,70);
		rectTitle->setSize(WINDOW_WIDTH,110);
		rectTitle->setColor(245, 195, 194);
		this->addWidget(rectTitle);
	}

	bibiActualIndicator = new Rect();
	{
		bibiActualIndicator->setColor(246, 239, 220);
		this->addWidget(bibiActualIndicator);
	}

	bibiMinLimitIndicator = new Rect();
	{
		bibiMinLimitIndicator->setColor(255, 0, 0);
		this->addWidget(bibiMinLimitIndicator);
	}

	Image* bibiPNG = new Image("Assets/Biberon.png");
	{
		bibiPNG->setPosition(0, 0);
		this->addWidget(bibiPNG);
		bibiPNG->setHorizontallyCentered();
		bibiPNG->setVerticallyCentered(-50);
	}

	// OFFSETs
	{
		bibiActualIndicator->setPosition(
			bibiPNG->getPositionX() + INDICATOR_OFFSET_X,
			bibiPNG->getPositionY() + LIMIT_INDICATOR_FULL
		);
		bibiActualIndicator->setSize(
			bibiPNG->getWidth() - INDICATOR_OFFSET_X * 2,
			-LIMIT_INDICATOR_Y_STEP * currentQuantity
		);

		bibiMinLimitIndicator->setSize(bibiPNG->getWidth() * LIMIT_INDICATOR_WIDTH_RATIO, 3);
		bibiMinLimitIndicator->setPosition(
			bibiPNG->getPositionX() + LIMIT_INDICATOR_OFFSET_X,
			bibiPNG->getPositionY() + LIMIT_INDICATOR_FULL - (bibiMinLimitIndicator->getHeight() / (float)2) - LIMIT_INDICATOR_Y_STEP * (((float)bib->GetMinFeed() / bib->GetMaxBib()) * 100)
		);
	}



	Text* title = new Text();
	{
		title->setPosition(10, 75);
		title->setText("Bib.io");
		title->setColor(0, 0, 0);
		this->addWidget(title);
		title->setHorizontallyCentered();
	}
	Button* button3= new Button("New meal");
	{
		button3->setPosition(0, 640);
		button3->setSize(BUTTON_WIDTH, BUTTON_HEIGHT);
		button3->setColor(245, 240, 187);
		button3->setOnClickCallback([]() {
			App::setCurrentView(App::getViewMeal());
			});
		this->addWidget(button3);
		button3->setHorizontallyCentered();
	}

	Button* button2 = new Button("Shopping list");
	{
		button2->setPosition(0, 700);
		button2->setSize(BUTTON_WIDTH, BUTTON_HEIGHT);
		button2->setColor(181, 222, 255);
		button2->setOnClickCallback([]() {
			App::setCurrentView(App::getViewShoppingList());
			});
		this->addWidget(button2);
		button2->setHorizontallyCentered();
	}

	Button* button1 = new Button("Settings");
	{
		button1->setPosition(0, 760);
		button1->setSize(BUTTON_WIDTH, BUTTON_HEIGHT);
		button1->setColor(220, 220, 220);
		button1->setOnClickCallback([]() {
			App::setCurrentView(App::getViewSettings());
		});
		this->addWidget(button1);
		button1->setHorizontallyCentered();
	}
}