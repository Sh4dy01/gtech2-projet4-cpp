#include "App/App.h"
#include "App/bib.h"
#include "SettingsView.h"

#include "View/InputText.h"
#include "View/Button.h"
#include "View/Text.h"
#include "View/Shapes.h"

#include <SDL_ttf.h>
#include <iostream>

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
				maxBibInput->setColor(245, 240, 187);
				maxBibInput->setPlaceholder(std::to_string(bib->GetMaxBib()).c_str());
				maxBibInput->setFont(App::getSmallFont());
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
				actualQtyInput->setColor(245, 240, 187);
				actualQtyInput->setPlaceholder(std::to_string(bib->GetBibQty()).c_str());
				actualQtyInput->setFont(App::getSmallFont());
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
				minFeedVolInput->setColor(245, 240, 187);
				minFeedVolInput->setPlaceholder(std::to_string(bib->GetMinFeed()).c_str());
				minFeedVolInput->setFont(App::getSmallFont());
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
