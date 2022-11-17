#include "MealView.h"
#include "MainMenuView.h"

#include "App/App.h"
#include "App/bib.h"

#include "View/Button.h"
#include "View/InputText.h"
#include "View/Text.h"
#include "View/Shapes.h"

#include <iostream>


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

		date = new Text();
		{
			char buffer[30];
			App::GetCurrentTime(buffer);

			date->setPosition(0, rectTitle->getPositionY() + 50);
			date->setColor(0, 0, 0);
			date->setText(buffer);
			date->setFont(App::getBoldFont());
			this->addWidget(date);
			date->setHorizontallyCentered();
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
				textFreeQty->setText("Remaining amount in feeder");
				textFreeQty->setIsUnderline();
				textFreeQty->setColor(0, 0, 0);
				textFreeQty->setFont(App::getSmallFont());
				this->addWidget(textFreeQty);
				textFreeQty->setHorizontallyCentered();
			}

			quantityInput = new InputText(3);
			{
				quantityInput->setPosition(0, textFreeQty->getPositionY()+30);
				quantityInput->setSize(40, 25);
				quantityInput->setColor(255, 255, 255);
				quantityInput->setPlaceholder("000");
				quantityInput->setFont(App::getSmallFont());
				this->addWidget(quantityInput);
				quantityInput->setHorizontallyCentered();
			}

			Text* clText = new Text();
			{
				clText->setPosition(quantityInput->getPositionX() + quantityInput->getWidth()+5, quantityInput->getPositionY() + quantityInput->getHeight()/4);
				clText->setText("in cl");
				clText->setColor(0, 0, 0);
				clText->setFont(App::getSmallLightFont());
				this->addWidget(clText);
			}
		}

		//Next meal reminder
		{
			Text* textReminder = new Text();
			{
				textReminder->setPosition(0, 310);
				textReminder->setText("Next meal reminder");
				textReminder->setIsUnderline();
				textReminder->setColor(0, 0, 0);
				textReminder->setFont(App::getSmallFont());
				this->addWidget(textReminder);
				textReminder->setHorizontallyCentered();
			}

			reminderInput = new InputText(3);
			{
				reminderInput->setPosition(0, textReminder->getPositionY()+30);
				reminderInput->setSize(40, 25);
				reminderInput->setColor(255, 255, 255);
				reminderInput->setPlaceholder("000");
				reminderInput->setFont(App::getSmallFont());
				this->addWidget(reminderInput);
				reminderInput->setHorizontallyCentered();
			}

			Text* minText = new Text();
			{
				minText->setPosition(reminderInput->getPositionX() + reminderInput->getWidth() + 5, reminderInput->getPositionY() + reminderInput->getHeight() / 4);
				minText->setText("in minutes");
				minText->setColor(0, 0, 0);
				minText->setFont(App::getSmallLightFont());
				this->addWidget(minText);
			}
		}

		//Regurgitated ?
		{
			Text* textRegu = new Text();
			{
				textRegu->setPosition(0, 400);
				textRegu->setText("Regurgitated ?");
				textRegu->setColor(0, 0, 0);
				textRegu->setFont(App::getSmallFont());
				this->addWidget(textRegu);
				textRegu->setHorizontallyCentered();
			}

			InputText* dataBtn2 = new InputText();
			{
				dataBtn2->setPosition(0, 430);
				dataBtn2->setPlaceholder("Insert data");
				dataBtn2->setSize(300, 30);
				dataBtn2->setColor(255, 255, 255);
				dataBtn2->setFont(App::getSmallFont());
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
			inputsNumCheck[0] = quantityInput;
			inputsNumCheck[1] = reminderInput;
			inputsMoreThanZeroCheck[0] = reminderInput;

			applyBtn->setPosition(0, 640);
			applyBtn->setSize(BUTTON_WIDTH, BUTTON_HEIGHT);
			applyBtn->setColor(245, 240, 187);
			applyBtn->setOnClickCallback([]() {
				if (((MealView*)App::getViewMeal())->IsInputsNumeric(((MealView*)App::getViewMeal())->getInputsNumWidget(), 2) && ((MealView*)App::getViewMeal())->IsInputsMoreThanZero(((MealView*)App::getViewMeal())->getInputsMoreThanZeroWidget(), 1))
				{
					((MealView*)App::getViewMeal())->CreateMeal();
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
				});
			this->addWidget(returnBtn);
			returnBtn->setHorizontallyCentered();
		}
	}
}

void MealView::CreateMeal() {	
	Meal meal;
	meal.feedQty = App::GetBibi()->GetBibQty() - std::stoi(GetQuantityFromInput());
	meal.reminderTotal = std::stoi(GetReminderFromInput())*60; //Convert into seconds
	meal.actualReminder = meal.reminderTotal;
	meal.IsRegurgitated = false;
	meal.takenTime = date->GetText();
	meal.fullDate = fullDate;

	std::cout << "Before: " << App::GetBibi()->GetBibQty() << std::endl;
	App::GetBibi()->BibReduction(meal.feedQty);
	std::cout << "After: " << App::GetBibi()->GetBibQty() << std::endl;
	App::GetBibi()->AddMeal(meal);
}

void MealView::ResetInputs() {
	quantityInput->setText("");
	reminderInput->setText("");
}

