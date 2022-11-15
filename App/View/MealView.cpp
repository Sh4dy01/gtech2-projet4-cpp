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

	//Title part
	{
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
			title->setFont(App::getSmallFont());
			title->setColor(0, 0, 0);
			title->setIsUnderline();
			this->addWidget(title);
			title->setHorizontallyCentered();
		}
	}

	//body part
	{
		Rect* rect0 = new Rect();
		{
			rect0->setPosition(60, 210);
			rect0->setSize(360, 270);
			rect0->setColor(245, 240, 187);
			this->addWidget(rect0);
		}

		//free quantity
		{
			Text* textFreeQty = new Text();
			{
				textFreeQty->setPosition(0, 220);
				textFreeQty->setText("Remaining amount of feeder:");
				textFreeQty->setColor(0, 0, 0);
				textFreeQty->setFont(App::getSmallFont());
				this->addWidget(textFreeQty);
				textFreeQty->setHorizontallyCentered();
			}

			Button* dataBtn0 = new Button("Insert data");
			{
				dataBtn0->setPosition(0, 250);
				dataBtn0->setSize(300, 30);
				dataBtn0->setColor(255, 255, 255);
				dataBtn0->setFont(App::getSmallFont());
				dataBtn0->setOnClickCallback([]() {
					});
				this->addWidget(dataBtn0);
				dataBtn0->setHorizontallyCentered();
			}
		}

		//Next meal reminder
		{
			Text* textReminder = new Text();
			{
				textReminder->setPosition(0, 310);
				textReminder->setText("Next meal reminder:");
				textReminder->setColor(0, 0, 0);
				textReminder->setFont(App::getSmallFont());
				this->addWidget(textReminder);
				textReminder->setHorizontallyCentered();
			}

			Button* dataBtn1 = new Button("Insert data");
			{
				dataBtn1->setPosition(0, 340);
				dataBtn1->setSize(300, 30);
				dataBtn1->setColor(255, 255, 255);
				dataBtn1->setFont(App::getSmallFont());
				dataBtn1->setOnClickCallback([]() {
					});
				this->addWidget(dataBtn1);
				dataBtn1->setHorizontallyCentered();
			}
		}

		//Regurgitated ?
		{
			Text* textRegu = new Text();
			{
				textRegu->setPosition(0, 400);
				textRegu->setText("regurgitated ?");
				textRegu->setColor(0, 0, 0);
				textRegu->setFont(App::getSmallFont());
				this->addWidget(textRegu);
				textRegu->setHorizontallyCentered();
			}

			Button* dataBtn2 = new Button("Insert data");
			{
				dataBtn2->setPosition(0, 430);
				dataBtn2->setSize(300, 30);
				dataBtn2->setColor(255, 255, 255);
				dataBtn2->setFont(App::getSmallFont());
				dataBtn2->setOnClickCallback([]() {
					});
				this->addWidget(dataBtn2);
				dataBtn2->setHorizontallyCentered();
			}
		}

		//Result of quantity drink
		{
			Rect* rect1 = new Rect();
			{
				rect1->setPosition(60, 510);
				rect1->setSize(360, 100);
				rect1->setColor(245, 240, 187);
				this->addWidget(rect1);
			}

			Text* textQtyDrinked = new Text();
			{
				textQtyDrinked->setPosition(0, 520);
				textQtyDrinked->setText("Quantity drinked:");
				textQtyDrinked->setColor(0, 0, 0);
				textQtyDrinked->setFont(App::getSmallFont());
				textQtyDrinked->setIsUnderline();
				this->addWidget(textQtyDrinked);
				textQtyDrinked->setHorizontallyCentered();
			}

			Text* textResult = new Text();
			{
				textResult->setPosition(0, 560);
				textResult->setText("Undefied");
				textResult->setColor(0, 0, 0);
				textResult->setFont(App::getSmallFont());
				this->addWidget(textResult);
				textResult->setHorizontallyCentered();
			}
		}
	}

	//Buttons part
	{
		Button* applyBtn = new Button("Apply");
		{
			applyBtn->setPosition(0, 640);
			applyBtn->setSize(BUTTON_WIDTH, BUTTON_HEIGHT);
			applyBtn->setColor(245, 240, 187);
			applyBtn->setOnClickCallback([]() {
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
				});
			this->addWidget(returnBtn);
			returnBtn->setHorizontallyCentered();
		}
	}
}
