#include "App/App.h"
#include "SettingsView.h"

#include "View/Button.h"
#include "View/Text.h"
#include "View/Forms.h"


SettingsView::SettingsView()
	: View(App::getSDLWindow(), App::getSDLRenderer())
{
	this->setBackgroundColor(82, 89, 92);
	this->setFont(App::getSDLDefaultFont());

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
				textVolume->setPosition(0, 245);
				textVolume->setText("Feeder volume (ml):");
				textVolume->setColor(0, 0, 0);
				this->addWidget(textVolume);
				textVolume->setHorizontallyCentered();
			}

			Button* dataBtn0 = new Button("Insert data");
			{
				dataBtn0->setPosition(0, 290);
				dataBtn0->setSize(300, 30);
				dataBtn0->setColor(245, 240, 187);
				dataBtn0->setOnClickCallback([]() {
					});
				this->addWidget(dataBtn0);
				dataBtn0->setHorizontallyCentered();
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
				textQtyMin->setPosition(0, 375);
				textQtyMin->setText("Minimum amount to eat (ml):");
				textQtyMin->setColor(0, 0, 0);
				this->addWidget(textQtyMin);
				textQtyMin->setHorizontallyCentered();
			}

			Button* dataBtn1 = new Button("Insert data");
			{
				dataBtn1->setPosition(0, 420);
				dataBtn1->setSize(300, 30);
				dataBtn1->setColor(245, 240, 187);
				dataBtn1->setOnClickCallback([]() {
					});
				this->addWidget(dataBtn1);
				dataBtn1->setHorizontallyCentered();
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

			Text* textQtyMax = new Text();
			{
				textQtyMax->setPosition(0, 505);
				textQtyMax->setText("Minimum amount to eat (ml):");
				textQtyMax->setColor(0, 0, 0);
				this->addWidget(textQtyMax);
				textQtyMax->setHorizontallyCentered();
			}

			Button* dataBtn2 = new Button("Insert data");
			{
				dataBtn2->setPosition(0, 550);
				dataBtn2->setSize(300, 30);
				dataBtn2->setColor(245, 240, 187);
				dataBtn2->setOnClickCallback([]() {
					});
				this->addWidget(dataBtn2);
				dataBtn2->setHorizontallyCentered();
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
