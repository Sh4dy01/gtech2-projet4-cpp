#include "App/App.h"
#include "ShoppingListView.h"

#include "View/Button.h"
#include "View/Text.h"
#include "View/Shapes.h"
#include "View/Image.h"

#include <iostream>
#include <string>
#include<sstream> 
using namespace std;

int contentOutset = 280;
int outsetBetweenElement = 75;

int ShoppingListView::getCountListElement(int i)
{
	return countList[i];
}

void ShoppingListView::setCountList(int i, int value)
{
	countList[i] = value;
}

void ShoppingListView::setButtonPlus(Button* btn)
{
	buttonPlus = btn;
}

Button* ShoppingListView::getButtonPlus()
{
	return buttonPlus;
}

void ShoppingListView::setList(const char* tab)
{
	lengthElementList += 1;
	elementList[lengthElementList] = tab;
}

void ShoppingListView::initWidgetLists()
{
	for (int i = 0; i < 15; i++) {
		widgetVisibleList[i] = 0;
	}

	for (int i = 0; i < 5; i++) {
		countList[i] = 0;
	}

	for (int i = 0; i < 5; i++) {
		for (int y = 0; y < 7; y++) {
			widgetsElementList[y][i] = 0;
		}
	}

	for (int i = 0; i < 5; i++) {
		numberWidgetsElementList[i] = 0;
	}

}

void ShoppingListView::initCountList()
{
	for (int i = 0; i < 5; i++) {
		countList[i] = 0;
	}
}

void ShoppingListView::addWigdetVisibleList(Widget* w)
{
	widgetVisibleList[lengthWidgetVisibleList] = w;
	lengthWidgetVisibleList += 1;
}

void ShoppingListView::addUpdateTextList(Text* t)
{
	updateTextList[lengthUpdateTextList] = t;
	lengthUpdateTextList += 1;
}

void ShoppingListView::addUpdateRectList(Rect* r)
{
	updateRectList[lengthUpdateRectList] = r;
	lengthUpdateRectList += 1;
}

void ShoppingListView::addWidgetsElementList(Widget* w, int index)
{
	widgetsElementList[numberWidgetsElementList[index]][index] = w;
	numberWidgetsElementList[index] += 1;
}

void ShoppingListView::activeUpdateTextList(int index)
{
	updateTextList[index]->setText(std::to_string(countList[index]).c_str());
}

void ShoppingListView::activeUpdateRectList(int index)
{
	if (countList[index] >= 5)		 updateRectList[index]->setColor(167, 233, 175);
	else if (countList[index] <= 2)	 updateRectList[index]->setColor(245, 195, 194);
	else                             updateRectList[index]->setColor(252, 251, 181);
}

void ShoppingListView::destroyElement(int index,Button* btn) {

	for (int i = 0; i < lenghtCountList - index - 1; i++) {
		countList[i + index] = countList[i + index + 1];
	}
	countList[lenghtCountList] = 0;
	lenghtCountList -= 1;

	for (int i = 0; i < lengthElementList - index - 1; i++) {
		elementList[i + index] = elementList[i + index + 1];
	}
	elementList[lengthElementList] = 0;

	for (int i = 0; i < lengthUpdateTextList - index - 1; i++) {
		updateTextList[i + index] = updateTextList[i + index + 1];
	}
	updateTextList[lengthUpdateTextList] = 0;
	lengthUpdateTextList -= 1;

	for (int i = 0; i < lengthUpdateRectList - index - 1; i++) {
		updateRectList[i + index] = updateRectList[i + index + 1];
	}
	updateRectList[lengthUpdateRectList] = 0;
	lengthUpdateRectList -= 1;

	for (int i = 0; i < lengthWidgetVisibleList - index - 1; i++) {
		for (int y = 0; y < 3; y++) {
			widgetVisibleList[y + index] = widgetVisibleList[y + index + 3];
		}
	}
	widgetVisibleList[lengthWidgetVisibleList] = 0;
	widgetVisibleList[lengthWidgetVisibleList+1] = 0;
	widgetVisibleList[lengthWidgetVisibleList+2] = 0;
	lengthWidgetVisibleList -= 3;

	for (int i = 0; i < 7; i++) {
		delete widgetsElementList[i][index];
		widgetsElementList[i][index] = 0;
	}

	for (int i = 0; i < lengthElementList - index - 1; i++) {
		for (int y = 0; y < 7; y++) {
			widgetsElementList[y][i + index + 1]->setPosition(widgetsElementList[y][i + index + 1]->getPositionX(), widgetsElementList[y][i + index + 1]->getPositionY() - outsetBetweenElement);
			widgetsElementList[y][i + index] = widgetsElementList[y][i + index + 1];
		}
	}

	for (int i = 0; i < 7; i++) {
		widgetsElementList[i][lengthElementList] = 0;
	}
	lengthElementList -= 1;

	this->buttonPlusUpdate(btn);
}

void ShoppingListView::buttonPlusUpdate(Button* btn)
{
	if (lengthElementList < 5) {
		if (!btn->isVisible()) btn->toggleVisibility();
		btn->setPosition(btn->getPositionX(), contentOutset + lengthElementList * outsetBetweenElement);
	}
	else
	{
		btn->toggleVisibility();
	}
}


ShoppingListView::ShoppingListView()
	: View(App::getSDLWindow(), App::getSDLRenderer())
{
	this->initWidgetLists();
	this->initCountList();

	/// temp var
	this->elementList[0] = "lait";
	this->elementList[1] = "poudre";
	this->elementList[2] = "couches";
	this->countList[0] = 5;
	this->countList[1] = 3;
	this->countList[2] = 1;
	this->countList[3] = 0;
	this->countList[4] = 0;
	this->lengthElementList = 3;
	this->lenghtCountList = 3;


	this->lengthUpdateTextList = 0;
	this->lengthUpdateRectList = 0;
	this->lengthWidgetVisibleList = 0;
	this->buttonPlus = 0;


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

		for (int i = 0; i < lengthElementList; i++) {
			Rect* temp = new Rect();
			{
				temp->setPosition(0, contentOutset + outsetBetweenElement * i);
				temp->setSize(320, 60);
				temp->setColor(181, 222, 255);
				this->addWidget(temp);
				this->addWidgetsElementList(temp,i);
				temp->setHorizontallyCentered();
			}

			Rect* tempBanner = new Rect();
			{
				tempBanner->setPosition(350, contentOutset + outsetBetweenElement*i);
				tempBanner->setSize(40, 60);

				if      (countList[i] >= 5)	 tempBanner->setColor(167, 233, 175);
				else if (countList[i] <= 2)	 tempBanner->setColor(245, 195, 194);
				else                         tempBanner->setColor(252, 251, 181);

				this->addUpdateRectList(tempBanner);
				this->addWidgetsElementList(tempBanner, i);
				this->addWidget(tempBanner);
			}

			Text* tempQty = new Text();
			{
				stringstream ss;
				ss << countList[i];
				string test;
				ss >> test;

				tempQty->setPosition(363, contentOutset + outsetBetweenElement * i +15);
				tempQty->setFont(App::getSmallFont());
				tempQty->setText(test.c_str());
				tempQty->setColor(0, 0, 0);
				this->addUpdateTextList(tempQty);
				this->addWidgetsElementList(tempQty, i);
				this->addWidget(tempQty);
			}


			Text* tempText = new Text();
			{
				tempText->setPosition(95, contentOutset + outsetBetweenElement * i + 15);
				tempText->setFont(App::getSmallFont());
				tempText->setText(elementList[i]);
				tempText->setColor(0, 0, 0);
				this->addWidgetsElementList(tempText, i);
				this->addWidget(tempText);
			}

			Button* tempPlus = new Button("+");
			{
				tempPlus->setPosition(42, contentOutset + outsetBetweenElement * i);
				tempPlus->setSize(28, 28);
				tempPlus->setColor(240, 240, 240);
				tempPlus->toggleVisibility();
				tempPlus->setOnClickCallback([](int index) {
					((ShoppingListView*)App::getViewShoppingList())->setCountList(index, ((ShoppingListView*)App::getViewShoppingList())->getCountListElement(index) + 1);
					((ShoppingListView*)App::getViewShoppingList())->activeUpdateTextList(index);
					((ShoppingListView*)App::getViewShoppingList())->activeUpdateRectList(index);
					}, i);
				this->addWigdetVisibleList(tempPlus);
				this->addWidgetsElementList(tempPlus, i);
				this->addWidget(tempPlus);
			}
			Button* tempMinus = new Button("-");
			{
				tempMinus->setPosition(42, contentOutset + outsetBetweenElement * i + 32);
				tempMinus->setSize(28, 28);
				tempMinus->setColor(240, 240, 240);
				tempMinus->toggleVisibility();
				tempMinus->setOnClickCallback([](int index) {
					if (((ShoppingListView*)App::getViewShoppingList())->getCountListElement(index) > 0) {
						((ShoppingListView*)App::getViewShoppingList())->setCountList(index, ((ShoppingListView*)App::getViewShoppingList())->getCountListElement(index) - 1);
						((ShoppingListView*)App::getViewShoppingList())->activeUpdateTextList(index);
						((ShoppingListView*)App::getViewShoppingList())->activeUpdateRectList(index);
					}
					}, i);
					
				this->addWigdetVisibleList(tempMinus);
				this->addWidgetsElementList(tempMinus, i);
				this->addWidget(tempMinus);
			}

			Image* tempPNG = new Image("Assets/Trash.png");
			{
				tempPNG->setPosition(400, contentOutset + outsetBetweenElement * i + 10);
				tempPNG->setSize(30, 30);
				tempPNG->toggleVisibility();
				tempPNG->setOnClickCallback([](int index) {

					((ShoppingListView*)App::getViewShoppingList())->destroyElement(index,((ShoppingListView*)App::getViewShoppingList())->getButtonPlus());
					}, i);
				this->addWigdetVisibleList(tempPNG);
				this->addWidgetsElementList(tempPNG, i);
				this->addWidget(tempPNG);
			}
			
		}

		if (lengthElementList < 5)
		{
			Button* buttonPlus = new Button("+");
			{
				buttonPlus->setPosition(0, contentOutset + lengthElementList * outsetBetweenElement);
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
				((ShoppingListView*)App::getViewShoppingList())->activeModify();
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

void ShoppingListView::activeModify() {
	for (int i = 0; i < lengthWidgetVisibleList; i++) {
		widgetVisibleList[i]->toggleVisibility();
	}
}

void ShoppingListView::popInt(int i, int* tab)
{
	int tempTab[5];
	for (int y = 0; y < 5; y++) tempTab[y] = tab[y];

	for (int y = 0; y < 5; y++) tab[y] = 0;

	for (int y = 0; y < 4; y++) {
		if     (y < i) tab[y] = tempTab[y];
		else   tab[y] = tempTab[y + 1];

	}
}



