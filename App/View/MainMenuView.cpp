#include "App/App.h"
#include "MainMenuView.h"
#include "SettingsView.h"
#include "MealView.h"
#include "../bib.h"

#include "View/Button.h"
#include "View/Text.h"
#include "View/Image.h"
#include "View/Shapes.h"


#include <iostream>
#include <SDL_image.h>

const int BIBI_INDICATOR_START = 123;
const int BIBI_WIDTH = 176;

const int INDICATOR_OFFSET_X = 11;
const int INDICATOR_OFFSET_Y = 120;
const int INDICATOR_FULL_OFFSET = 234;

const int LIMIT_INDICATOR_OFFSET_X = 12;
const int LIMIT_INDICATOR_FULL = 352;
const float LIMIT_INDICATOR_Y_STEP = (LIMIT_INDICATOR_FULL - (float)BIBI_INDICATOR_START) / 100;
const float LIMIT_INDICATOR_WIDTH_RATIO = 0.866;

static char buffer[30];

MainMenuView::MainMenuView()
	: View(App::getSDLWindow(), App::getSDLRenderer())
{
	Bib* bib = App::GetBibi();
	currentQty = ((float)bib->GetBibQty() / bib->GetMaxBib()) * 100;

	this->setBackgroundColor(82, 89, 92);
	this->setFont(App::getSDLDefaultFont());

	Rect* rectTitle = new Rect();
	{
		rectTitle->setPosition(0,70);
		rectTitle->setSize(WINDOW_WIDTH,110);
		rectTitle->setColor(245, 195, 194);
		this->addWidget(rectTitle);
	}

	date = new Text();
	{
		App::GetCurrentTime(buffer);

		date->setPosition(10, rectTitle->getPositionY()+60);
		date->setColor(0, 0, 0);
		this->addWidget(date);
		date->setText(buffer);
		date->setFont(App::GetTitleFont());
	}

	timer = new Text();
	{
		std::string timerText = "No Timer";

		if (bib->GetReminder())
		{
			int seconds = bib->GetReminder();
			int minutes = seconds / 60;
			int hours = minutes / 60;
			timerText = std::to_string(int(hours)) + ":" + std::to_string(int(minutes % 60)) + ":" + std::to_string(int(seconds % 60));
		}
		

		timer->setColor(0, 0, 0);
		this->addWidget(timer);
		timer->setText(timerText.c_str());
		timer->setFont(App::getBoldFont());
		timer->setPosition(WINDOW_WIDTH - timer->getWidth() - 53, rectTitle->getPositionY() + 50);
	}

	Text* nextMealText = new Text();
	{
		nextMealText->setColor(0, 0, 0);
		this->addWidget(nextMealText);
		nextMealText->setText("before next meal");
		nextMealText->setFont(App::getSmallLightFont());
		nextMealText->setPosition(WINDOW_WIDTH - nextMealText->getWidth() - 20, timer->getPositionY() + timer->getHeight());
	}

	bibiActualIndicator = new Rect();
	{
		bibiActualIndicator->setColor(246, 239, 220);
		this->addWidget(bibiActualIndicator);
	}

	bibiMinLimitIndicator = new Rect();
	{
		bibiMinLimitIndicator->setColor(255, 175, 175);
		this->addWidget(bibiMinLimitIndicator);
	}

	bibActLine = new Rect();
	{
		bibActLine->setColor(150, 255, 150);
		this->addWidget(bibActLine);
	}

	bibiMinText = new Text();
	{
		bibiMinText->setColor(255, 175, 175);
		bibiMinText->setText(std::to_string(bib->GetMinFeed()).c_str());
		bibiMinText->setFont(App::getLightFont());
		this->addWidget(bibiMinText);
	}

	Image* bibiPNG = new Image("Assets/Biberon.png");
	{
		bibiPNG->setPosition(0, 0);
		this->addWidget(bibiPNG);
		bibiPNG->setHorizontallyCentered();
		bibiPNG->setVerticallyCentered(-50);
	}

	bibiMaxText = new Text();
	{
		bibiMaxText->setColor(181, 222, 255);
		bibiMaxText->setText(std::to_string(bib->GetMaxBib()).c_str());
		bibiMaxText->setFont(App::getLightFont());
		this->addWidget(bibiMaxText);
	}

	bibiActText = new Text();
	{
		bibiActText->setColor(150, 255, 150);
		bibiActText->setText(std::to_string(bib->GetBibQty()).c_str());
		bibiActText->setFont(App::getLightFont());
		this->addWidget(bibiActText);
	}

	Button* fillButton = new Button("Fill");
	{
		fillButton->setPosition(bibiPNG->getPositionX() + bibiPNG->getWidth() + 4, bibiPNG->getPositionY() + 80);
		fillButton->setSize(28, 28);
		fillButton->setFont(App::getSmallLightFont());
		fillButton->setColor(181, 222, 255);
		this->addWidget(fillButton);
		fillButton->setOnClickCallback([]() {
			((Bib*)App::GetBibi())->Refill();
			((MainMenuView*)App::getViewMainMenu())->UpdateBibVisual();
		});
	}

	// OFFSETs
	{
		bibiActualIndicator->setPosition(
			bibiPNG->getPositionX() + INDICATOR_OFFSET_X,
			bibiPNG->getPositionY() + LIMIT_INDICATOR_FULL
		);

		bibiMinLimitIndicator->setSize(bibiPNG->getWidth(), 3);
		bibiMinLimitIndicator->setPosition(
			bibiPNG->getPositionX() - LIMIT_INDICATOR_OFFSET_X,
			bibiPNG->getPositionY() + LIMIT_INDICATOR_FULL - (bibiMinLimitIndicator->getHeight() / (float)2) - LIMIT_INDICATOR_Y_STEP * (((float)bib->GetMinFeed() / bib->GetMaxBib()) * 100)
		);

		bibiMaxText->setPosition(
			bibiPNG->getPositionX() + bibiPNG->getWidth(),
			bibiPNG->getPositionY() + LIMIT_INDICATOR_FULL - (bibiMaxText->getHeight() / (float)2) - LIMIT_INDICATOR_Y_STEP * 100
		);

		bibActLine->setSize(
			bibiMinLimitIndicator->getWidth() + bibiMinText->getWidth(),
			3
		);

		UpdateBibVisual();
	}

	Text* title = new Text();
	{
		title->setPosition(10, 75);
		title->setColor(0, 0, 0);
		this->addWidget(title);
		title->setText("Bib.io");
		title->setHorizontallyCentered();
	}

	errorFeedFirst = new Text();
	{
		errorFeedFirst->setColor(255, 140, 140);
		errorFeedFirst->setPosition(10, RENDER_HEIGHT - 24 - 10);
		errorFeedFirst->setVisible(false);
		errorFeedFirst->setFont(App::getSmallFont());
		errorFeedFirst->setText("You must fill the bottle first!");
		this->addWidget(errorFeedFirst);
	}

	//button part
	{
		Button* button3 = new Button("New meal");
		{
			button3->setPosition(0, 640);
			button3->setSize(BUTTON_WIDTH, BUTTON_HEIGHT);
			button3->setColor(245, 240, 187);
			button3->setOnClickCallback([]() {
				if (App::GetBibi()->GetBibQty() > App::GetBibi()->GetMinFeed())
				{
					// Clear error.
					((MainMenuView*) App::getViewMainMenu())->errorFeedFirst->setVisible(false);

					((MealView*)App::getViewMeal())->SetFullDate(App::GetCurrentTime(buffer));
					((MealView*)App::getViewMeal())->getDateWidget()->setText(buffer);
					((MealView*)App::getViewMeal())->ResetInputs();
					App::setCurrentView(App::getViewMeal());
				}
				else
				{
					// Set error.
					((MainMenuView*)App::getViewMainMenu())->errorFeedFirst->setVisible(true);
				}
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
				((SettingsView*)App::getViewSettings())->SetActQtyInput(App::GetBibi()->GetBibQty());
				App::setCurrentView(App::getViewSettings());
			});
			this->addWidget(button1);
			button1->setHorizontallyCentered();
		}
	}
}

void MainMenuView::UpdateBibVisual() {
	Bib* bib = App::GetBibi();

	currentQty = ((float)bib->GetBibQty() /bib->GetMaxBib()) * 100;

	bibiActualIndicator->setSize(
		BIBI_WIDTH - INDICATOR_OFFSET_X * 2,
		-LIMIT_INDICATOR_Y_STEP * currentQty
	);

	bibiActText->setText(std::to_string(bib->GetBibQty()).c_str());
	bibiActText->setPosition(
		bibiActualIndicator->getPositionX() - bibiActText->getWidth() - 20,
		bibiActualIndicator->getPositionY() - LIMIT_INDICATOR_Y_STEP * currentQty - bibiActText->getHeight() / (float)(2)
	);

	bibiMaxText->setText(std::to_string(bib->GetMaxBib()).c_str());

	bibiMinText->setPosition(
		bibiActText->getPositionX(),
		bibiMinLimitIndicator->getPositionY() - bibiMinText->getHeight() / (float)2
	);

	bibActLine->setPosition(
		bibiActText->getPositionX() + bibiActText->getWidth() - bibiMinText->getWidth(),
		bibiActText->getPositionY() + bibiActText->getHeight() / (float)2 - 2
	);

	bibiActText->setPosition(
		bibiActualIndicator->getPositionX() - bibiActText->getWidth()*2.7,
		bibiActualIndicator->getPositionY() - LIMIT_INDICATOR_Y_STEP * currentQty - bibiActText->getHeight() / (float)(2)
	);
}

void MainMenuView::update()  {
	App::GetCurrentTime(buffer);
	date->setText(buffer);

	// Timer part
	if (App::GetBibi()->GetReminder())
	{
		App::GetBibi()->ReminderReduction();

		int seconds = App::GetBibi()->GetReminder();
		int minutes = seconds / 60;
		int hours = minutes / 60;
		std::string timerText =
			std::to_string(int(hours)) + ":" +
			std::to_string(int(minutes % 60)) + ":" +
			std::to_string(int(seconds % 60));
		timer->setText(timerText.c_str());

	}
}