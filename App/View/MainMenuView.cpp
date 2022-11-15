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

	this->setBackgroundColor(240, 240, 240);
	this->setFont(App::getSDLDefaultFont());

	bibiActualIndicator = new Rect();
	{
		bibiActualIndicator->setColor(0, 239, 220);
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