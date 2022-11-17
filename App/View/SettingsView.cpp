#include "App/App.h"
#include "App/bib.h"
#include "SettingsView.h"
#include "MainMenuView.h"

#include "View/InputText.h"
#include "View/Button.h"
#include "View/Text.h"
#include "View/Shapes.h"

#include <SDL_ttf.h>
#include <iostream>

Color* inputDefaultColor = new Color(245, 240, 187);

SettingsView::SettingsView()
	: View(App::getSDLWindow(), App::getSDLRenderer())
{
	this->setBackgroundColor(82, 89, 92);
	this->setFont(App::getSDLDefaultFont());

	Bib* bib = App::GetBibi();

	//title part
	{ 
		Rect* rectTitle = new Rect();
		{
			rectTitle->setPosition(0, 70);
			rectTitle->setSize(750, 110);
			rectTitle->setColor(220, 220, 220);
			this->addWidget(rectTitle);
		}

		Text* title = new Text();
		{
			title->setPosition(10, 105);
			title->setText("SETTINGS");
			title->setColor(0, 0, 0);
			this->addWidget(title);
			title->setHorizontallyCentered();
		}

	}

	//Body part
	{
		//Volume box
		{
			Rect* rect0 = new Rect();
			{
				rect0->setPosition(60, 240);
				rect0->setSize(360, 100);
				rect0->setColor(220, 220, 220);
				this->addWidget(rect0);
			}

			Text* textVolume = new Text();
			{
				textVolume->setPosition(0, 250);
				textVolume->setText("Total feeder capacity");
				textVolume->setIsUnderline();
				textVolume->setColor(0, 0, 0);
				textVolume->setFont(App::getSmallFont());
				this->addWidget(textVolume);
				textVolume->setHorizontallyCentered();
			}

			maxBibInput = new InputText(3);
			{
				maxBibInput->setSize(40, 25);
				maxBibInput->setPosition(0, textVolume->getPositionY()+maxBibInput->getHeight()+10);
				maxBibInput->setColor(inputDefaultColor->getR(), inputDefaultColor->getG(), inputDefaultColor->getB());
				maxBibInput->setFont(App::getSmallFont());
				maxBibInput->setText(std::to_string(bib->GetMaxBib()).c_str());
				maxBibInput->setPlaceholder(std::to_string(bib->GetMaxBib()).c_str());
				this->addWidget(maxBibInput);
				maxBibInput->setHorizontallyCentered();
			}

			Text* clText = new Text();
			{
				clText->setPosition(maxBibInput->getPositionX() + maxBibInput->getWidth() + 5, maxBibInput->getPositionY() + maxBibInput->getHeight() / 4);
				clText->setText("in cl");
				clText->setColor(0, 0, 0);
				clText->setFont(App::getSmallLightFont());
				this->addWidget(clText);
			}
		}

		//Minimum quantity box
		{
			Rect* rect1 = new Rect();
			{
				rect1->setPosition(60, 370);
				rect1->setSize(360, 100);
				rect1->setColor(220, 220, 220);
				this->addWidget(rect1);
			}

			Text* textQtyMin = new Text();
			{
				textQtyMin->setPosition(0, 380);
				textQtyMin->setText("Actual feeder volume");
				textQtyMin->setIsUnderline();
				textQtyMin->setColor(0, 0, 0);
				textQtyMin->setFont(App::getSmallFont());
				this->addWidget(textQtyMin);
				textQtyMin->setHorizontallyCentered();
			}

			actualQtyInput = new InputText(3);
			{
				actualQtyInput->setSize(40, 25);
				actualQtyInput->setPosition(0, textQtyMin->getPositionY() + textQtyMin->getHeight() + 10);
				actualQtyInput->setColor(inputDefaultColor->getR(), inputDefaultColor->getG(), inputDefaultColor->getB());
				actualQtyInput->setFont(App::getSmallFont());
				actualQtyInput->setText(std::to_string(bib->GetBibQty()).c_str());
				actualQtyInput->setPlaceholder(std::to_string(bib->GetBibQty()).c_str());
				this->addWidget(actualQtyInput);
				actualQtyInput->setHorizontallyCentered();
			}

			Text* clText = new Text();
			{
				clText->setPosition(actualQtyInput->getPositionX() + actualQtyInput->getWidth() + 5, actualQtyInput->getPositionY() + actualQtyInput->getHeight() / 4);
				clText->setText("in cl");
				clText->setColor(0, 0, 0);
				clText->setFont(App::getSmallLightFont());
				this->addWidget(clText);
			}
		}

		//Maximum quantity box
		{
			Rect* rect2 = new Rect();
			{
				rect2->setPosition(60, 500);
				rect2->setSize(360, 100);
				rect2->setColor(220, 220, 220);
				this->addWidget(rect2);
			}

			Text* textMinMeal = new Text();
			{
				textMinMeal->setPosition(0, 510);
				textMinMeal->setText("Minimum volume for meal");
				textMinMeal->setIsUnderline();
				textMinMeal->setColor(0, 0, 0);
				textMinMeal->setFont(App::getSmallFont());
				this->addWidget(textMinMeal);
				textMinMeal->setHorizontallyCentered();
			}

			minFeedVolInput = new InputText(3);
			{
				minFeedVolInput->setSize(40, 25);
				minFeedVolInput->setPosition(0, textMinMeal->getPositionY() + textMinMeal->getHeight() + 10);
				minFeedVolInput->setColor(inputDefaultColor->getR(), inputDefaultColor->getG(), inputDefaultColor->getB());
				minFeedVolInput->setFont(App::getSmallFont());
				minFeedVolInput->setText(std::to_string(bib->GetMinFeed()).c_str());
				minFeedVolInput->setPlaceholder(std::to_string(bib->GetMinFeed()).c_str());
				this->addWidget(minFeedVolInput);
				minFeedVolInput->setHorizontallyCentered();
			}

			Text* clText = new Text();
			{
				clText->setPosition(minFeedVolInput->getPositionX() + minFeedVolInput->getWidth() + 5, minFeedVolInput->getPositionY() + minFeedVolInput->getHeight() / 4);
				clText->setText("in cl");
				clText->setColor(0, 0, 0);
				clText->setFont(App::getSmallLightFont());
				this->addWidget(clText);
			}
		}
	}

	Button* applyBtn = new Button("Apply");
	{
		inputsNumCheck[0] = maxBibInput;
		inputsNumCheck[1] = actualQtyInput;
		inputsNumCheck[2] = minFeedVolInput;
		inputsMoreThanZeroCheck[0] = minFeedVolInput;
		inputsMoreThanZeroCheck[1] = maxBibInput;

		applyBtn->setPosition(0, 640);
		applyBtn->setSize(BUTTON_WIDTH, BUTTON_HEIGHT);
		applyBtn->setColor(245, 240, 187);
		applyBtn->setOnClickCallback([]() {
			if (((SettingsView*)App::getViewSettings())->IsInputsNumeric(((SettingsView*)App::getViewSettings())->getInputsNumWidget(), 3) && ((SettingsView*)App::getViewSettings())->IsInputsMoreThanZero(((SettingsView*)App::getViewSettings())->getInputsMoreThanZeroWidget(), 2) && ((SettingsView*)App::getViewSettings())->IsInputsLogical())
			{
				((SettingsView*)App::getViewSettings())->ApplySettingsToBib();
				((MainMenuView*)App::getViewMainMenu())->UpdateBibVisual();
				App::setCurrentView(App::getViewMainMenu());
			}
			});
		this->addWidget(applyBtn);
		applyBtn->setHorizontallyCentered();
	}

	Button* returnBtn = new Button("Return");
	{
		returnBtn->setPosition(50, 700);
		returnBtn->setSize(BUTTON_WIDTH, BUTTON_HEIGHT);
		returnBtn->setColor(220, 220, 220);
		returnBtn->setOnClickCallback([]() {
			App::setCurrentView(App::getViewMainMenu());
			App::getViewSettings()->ResetInputs(((SettingsView*)App::getViewSettings())->getInputsNumWidget(), 3, inputDefaultColor);
			});
		this->addWidget(returnBtn);
		returnBtn->setHorizontallyCentered();
	}
}

void SettingsView::ApplySettingsToBib() {
	App::GetBibi()->ApplySettings(
		std::stoi(maxBibInput->getText()), 
		std::stoi(actualQtyInput->getText()), 
		std::stoi(minFeedVolInput->getText())
	);

	ResetInputs(inputsNumCheck, 3, inputDefaultColor);
}

bool SettingsView::IsInputsLogical() {
	int maxBib = std::stoi(maxBibInput->getText());
	int actQty = std::stoi(actualQtyInput->getText());
	int minFeed = std::stoi(minFeedVolInput->getText());

	if (actQty > maxBib) { 
		actualQtyInput->setColor(255, 0, 0);

		return false; 
	}
	if (minFeed > maxBib) { 
		minFeedVolInput->setColor(255, 0, 0);
		
		return false; 
	}

	return true;
}