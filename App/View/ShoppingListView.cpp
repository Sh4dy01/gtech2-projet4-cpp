#include "App/App.h"
#include "ShoppingListView.h"

#include "View/Button.h"
#include "View/Text.h"
#include "View/Forms.h"
#include "View/Image.h"

void ShoppingListView::setList(const char* tab)
{
	lengthList += 1;
	list[lengthList] = tab;
}

void ShoppingListView::setIsModify()
{
	isModify = !isModify;
}

ShoppingListView::ShoppingListView()
	: View(App::getSDLWindow(), App::getSDLRenderer())
{
	this->isModify = false;
	this->setBackgroundColor(82, 89, 92);
	this->setFont(App::getSDLDefaultFont());

	//title part
	{
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
	}

	//body part
	{
		Rect* rectBody = new Rect();
		{
			rectBody->setPosition(60, 220);
			rectBody->setSize(360, 440);
			rectBody->setColor(220, 220, 220);
			this->addWidget(rectBody);
		}

		Text* titleBody = new Text();
		{
			titleBody->setPosition(10, 230);
			titleBody->setText("List");
			titleBody->setColor(0, 0, 0);
			titleBody->setIsUnderline();
			this->addWidget(titleBody);
			titleBody->setHorizontallyCentered();
		}

		int contentOutset = 280;

		for (int i = 0; i < lengthList; i++) {
			Rect* temp = new Rect();
			{
				temp->setPosition(0, contentOutset);
				temp->setSize(320, 60);
				temp->setColor(181, 222, 255);
				this->addWidget(temp);
				temp->setHorizontallyCentered();
			}

			Rect* tempBanner = new Rect();
			{
				tempBanner->setPosition(350, contentOutset);
				tempBanner->setSize(40, 60);
				tempBanner->setColor(255, 255, 255);
				this->addWidget(tempBanner);
			}

			Text* tempQty = new Text();
			{
				tempQty->setPosition(363, contentOutset+15);
				tempQty->setFont(App::getSmallFont());
				tempQty->setText("5");
				tempQty->setColor(0, 0, 0);
				this->addWidget(tempQty);
			}


			Text* tempText = new Text();
			{
				tempText->setPosition(95, contentOutset + 15);
				tempText->setFont(App::getSmallFont());
				tempText->setText("test");
				tempText->setColor(0, 0, 0);
				this->addWidget(tempText);
			}

			if (isModify)
			{
				Button* tempPlus = new Button("+");
				{
					tempPlus->setPosition(42, contentOutset);
					tempPlus->setSize(28, 28);
					tempPlus->setColor(240, 240, 240);
					this->addWidget(tempPlus);
				}
				Button* tempMinus = new Button("-");
				{
					tempMinus->setPosition(42, contentOutset + 32);
					tempMinus->setSize(28, 28);
					tempMinus->setColor(240, 240, 240);
					this->addWidget(tempMinus);
				}

				Image* tempPNG = new Image("Assets/Trash.png");
				{
					tempPNG->setPosition(400, contentOutset + 10);
					tempPNG->setSize(30, 30);
					this->addWidget(tempPNG);
				}
			}


			contentOutset += 75;
		}

		if (lengthList < 5)
		{
			Button* buttonPlus = new Button("+");
			{
				buttonPlus->setPosition(0, contentOutset);
				buttonPlus->setSize(320, 60);
				buttonPlus->setColor(240, 240, 240);
				this->addWidget(buttonPlus);
				buttonPlus->setHorizontallyCentered();
			}
		}
	}

	//button part
	{

		Button* modifyBtn = new Button("Modify");
		{
			modifyBtn->setPosition(245, 700);
			modifyBtn->setSize(BUTTON_WIDTH, BUTTON_HEIGHT);
			modifyBtn->setColor(181, 222, 255);
			modifyBtn->setOnClickCallback([]() {
				((ShoppingListView*)App::getViewShoppingList())->setIsModify();
				});
			this->addWidget(modifyBtn);
			modifyBtn->setHorizontallyCentered();
		}

		Button* returnBtn = new Button("Return");
		{
			returnBtn->setPosition(40, 760);
			returnBtn->setSize(BUTTON_WIDTH, BUTTON_HEIGHT);
			returnBtn->setColor(220, 220, 220);
			returnBtn->setOnClickCallback([]() {
				App::setCurrentView(App::getViewMainMenu());
				});
			this->addWidget(returnBtn);
			returnBtn->setHorizontallyCentered();
		}
	}
};


