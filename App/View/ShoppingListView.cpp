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

void ShoppingListView::setProduct(std::string str, int num)
{
	elementList[lengthElementList] = str;
	lengthElementList += 1;

	countList[lenghtCountList] = num;
	lenghtCountList += 1;
}

std::string* ShoppingListView::getElementList()
{
	return elementList;
}

int* ShoppingListView::getCountList()
{
	return countList;
}

int ShoppingListView::getLengthElementList()
{
	return lengthElementList;
}

int ShoppingListView::getCountListElement(int i)
{
	return countList[i];
}

void ShoppingListView::setCountList(int i, int value)
{
	countList[i] = value;
}

void ShoppingListView::setInputTextPlus(InputText* ipt)
{
	ElementInput = ipt;
}

InputText* ShoppingListView::getInputTextPlus()
{
	return ElementInput;
}

void ShoppingListView::setList(std::string tab)
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

	for (int i = 0; i < 5; i++) {
		updateRectList[i] = 0;
	}

	for (int i = 0; i < 5; i++) {
		updateTextList[i] = 0;
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

void ShoppingListView::destroyElement(int index, InputText* ipt) {

	// std::string elementList[5]; ex [gui,hug,dav,..,..]
	// int lengthElementList; ex: 3

	// int countList[5];
	// lenghtCountList;

	// Text* updateTextList[5];
	// int lengthUpdateTextList;

	// Rect* updateRectList[5];
	// int lengthUpdateRectList;

	// Widget* widgetVisibleList[15];
	// int lengthWidgetVisibleList;

	// Widget* widgetsElementList[7][5];
	// int numberWidgetsElementList[5];

	// remove element of elementList at the index
	{
		for (int i = 0; i < (lengthElementList-index-1); i++)

		{
			elementList[index + i] = elementList[index + i + 1];
		}

		elementList[lengthElementList - 1] = "";
	}

	// remove element of countList at the index
	{
		for (int i = 0; i < (lenghtCountList - index - 1); i++)

		{
			countList[index + i] = countList[index + i + 1];
		}

		countList[lenghtCountList - 1] = 0;
		lenghtCountList -= 1;
	}

	// remove element of updateTextList at the index
	{
		for (int i = 0; i < (lengthUpdateTextList - index - 1); i++)

		{
			updateTextList[index + i] = updateTextList[index + i + 1];
		}

		updateTextList[lengthUpdateTextList - 1] = 0;
		lengthUpdateTextList -= 1;
	}

	// remove element of updateRectList at the index
	{
		for (int i = 0; i < (lengthUpdateRectList - index - 1); i++)

		{
			updateRectList[index + i] = updateRectList[index + i + 1];
		}

		updateRectList[lengthUpdateRectList - 1] = 0;
		lengthUpdateRectList -= 1;
	}

	// remove element of widgetVisibleList at the index
	{
		for (int i = 0; i < (lengthWidgetVisibleList - index*3 - 3); i++)

		{
			widgetVisibleList[index*3 + i] = widgetVisibleList[index*3 + i + 3];
		}

		widgetVisibleList[lengthWidgetVisibleList - 3] = 0;
		widgetVisibleList[lengthWidgetVisibleList - 2] = 0;
		widgetVisibleList[lengthWidgetVisibleList - 1] = 0;
		lengthWidgetVisibleList -= 3;
	}

	// destroy and remove all the widget link to a element
	{
		for (int i = 0; i < 7; i++)
		{
			this->removeWidget(widgetsElementList[i][index]);
			widgetsElementList[i][index] = 0;
		}

		for (int i = 0; i < (lengthElementList - index - 1); i++)
		{
			for (int y = 0; y < 7; y++)
			{
				//change image onClick index to the good one
				if (y == 6)
				{
					((Image*)widgetsElementList[y][index + i + 1])->setCallbackUserData(
						((Image*)widgetsElementList[y][index + i + 1])->getCallbackUserData() - 1
					);
				}
				
				//move all widget to the next emplacement 
				widgetsElementList[y][index + i + 1]->setPosition(
					widgetsElementList[y][index + i + 1]->getPositionX(),
					widgetsElementList[y][index + i + 1]->getPositionY() - outsetBetweenElement
				);

				//remplace actual widget with the one of the next column
				widgetsElementList[y][index + i] = widgetsElementList[y][index + i + 1];
			}
		}

		for (int i = 0; i < 7; i++)
		{
			widgetsElementList[i][lengthElementList-1] = 0;
		}

		lengthElementList -= 1;
		numberWidgetsElementList[lengthElementList] = 0;
	}

	this->inputTextPlusUpdate(ipt);
}

void ShoppingListView::addElement(InputText* ipt)
{
	if (lengthElementList < 5) {
		elementList[lengthElementList] = ElementInput->getText();
		ElementInput->setText("");

		Rect* temp = new Rect();
		{
			temp->setPosition(0, contentOutset + outsetBetweenElement * lengthElementList);
			temp->setSize(320, 60);
			temp->setColor(181, 222, 255);
			this->addWidget(temp);
			this->addWidgetsElementList(temp, lengthElementList);
			temp->setHorizontallyCentered();
		}

		Rect* tempBanner = new Rect();
		{
			tempBanner->setPosition(350, contentOutset + outsetBetweenElement * lengthElementList);
			tempBanner->setSize(40, 60);

			if (countList[lengthElementList] >= 5)	     tempBanner->setColor(167, 233, 175);
			else if (countList[lengthElementList] <= 2)	 tempBanner->setColor(245, 195, 194);
			else                                         tempBanner->setColor(252, 251, 181);

			this->addUpdateRectList(tempBanner);
			this->addWidgetsElementList(tempBanner, lengthElementList);
			this->addWidget(tempBanner);
		}

		Text* tempQty = new Text();
		{
			stringstream ss;
			ss << countList[lengthElementList];
			string test;
			ss >> test;

			tempQty->setPosition(363, contentOutset + outsetBetweenElement * lengthElementList + 15);
			tempQty->setFont(App::getSmallFont());
			tempQty->setText(test.c_str());
			tempQty->setColor(0, 0, 0);
			this->addUpdateTextList(tempQty);
			this->addWidgetsElementList(tempQty, lengthElementList);
			this->addWidget(tempQty);

			lenghtCountList += 1;
		}


		Text* tempText = new Text();
		{
			tempText->setPosition(95, contentOutset + outsetBetweenElement * lengthElementList + 15);
			tempText->setFont(App::getSmallFont());
			tempText->setText(elementList[lengthElementList].c_str());
			tempText->setColor(0, 0, 0);
			this->addWidgetsElementList(tempText, lengthElementList);
			this->addWidget(tempText);
		}

		Button* tempPlus = new Button("+");
		{
			tempPlus->setPosition(42, contentOutset + outsetBetweenElement * lengthElementList);
			tempPlus->setSize(28, 28);
			tempPlus->setColor(240, 240, 240);
			tempPlus->setOnClickCallback([](int index) {
				((ShoppingListView*)App::getViewShoppingList())->setCountList(index, ((ShoppingListView*)App::getViewShoppingList())->getCountListElement(index) + 1);
			((ShoppingListView*)App::getViewShoppingList())->activeUpdateTextList(index);
			((ShoppingListView*)App::getViewShoppingList())->activeUpdateRectList(index);
				}, lengthElementList);
			this->addWigdetVisibleList(tempPlus);
			this->addWidgetsElementList(tempPlus, lengthElementList);
			this->addWidget(tempPlus);
		}
		Button* tempMinus = new Button("-");
		{
			tempMinus->setPosition(42, contentOutset + outsetBetweenElement * lengthElementList + 32);
			tempMinus->setSize(28, 28);
			tempMinus->setColor(240, 240, 240);
			tempMinus->setOnClickCallback([](int index) {
				if (((ShoppingListView*)App::getViewShoppingList())->getCountListElement(index) > 0) {
					((ShoppingListView*)App::getViewShoppingList())->setCountList(index, ((ShoppingListView*)App::getViewShoppingList())->getCountListElement(index) - 1);
					((ShoppingListView*)App::getViewShoppingList())->activeUpdateTextList(index);
					((ShoppingListView*)App::getViewShoppingList())->activeUpdateRectList(index);
				}
				}, lengthElementList);

			this->addWigdetVisibleList(tempMinus);
			this->addWidgetsElementList(tempMinus, lengthElementList);
			this->addWidget(tempMinus);
		}

		Image* tempPNG = new Image("Assets/Trash.png");
		{
			tempPNG->setPosition(400, contentOutset + outsetBetweenElement * lengthElementList + 10);
			tempPNG->setSize(30, 30);
			tempPNG->setOnClickCallback([](int index) {

				((ShoppingListView*)App::getViewShoppingList())->destroyElement(index, ((ShoppingListView*)App::getViewShoppingList())->getInputTextPlus());
				}, lengthElementList);
			this->addWigdetVisibleList(tempPNG);
			this->addWidgetsElementList(tempPNG, lengthElementList);
			this->addWidget(tempPNG);
		}

		lengthElementList += 1;
		this->inputTextPlusUpdate(ipt);
	}
}

void ShoppingListView::inputTextPlusUpdate(InputText* btn)
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

	this->lengthElementList = 0;
	this->lenghtCountList = 0;


	this->lengthUpdateTextList = 0;
	this->lengthUpdateRectList = 0;
	this->lengthWidgetVisibleList = 0;
	this->ElementInput = 0;
	this->applyBtn = 0;


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

		
		
		ElementInput = new InputText(15);
		{
			ElementInput->setPosition(0, contentOutset + lengthElementList * outsetBetweenElement);
			ElementInput->setSize(320, 60);
			ElementInput->setColor(240, 240, 240);
			ElementInput->setVisible(false);
			ElementInput->setFont(App::getSmallFont());
			ElementInput->setPlaceholder("Add a new element");
			this->addWidget(ElementInput);
			if (lengthElementList >= 5) ElementInput->setVisible(false);
			this->setInputTextPlus(ElementInput);
			ElementInput->setHorizontallyCentered();
		}


		

		this->loadProducts();

		
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
				if (((ShoppingListView*)App::getViewShoppingList())->getLengthElementList() < 5) {
					((ShoppingListView*)App::getViewShoppingList())->getInputTextPlus()->toggleVisibility();
				}
				});
			this->addWidget(modifyBtn);
			modifyBtn->setHorizontallyCentered();
		}

		Button* returnBtn = new Button("Return");
		{
			returnBtn->setPosition(0, 760);
			returnBtn->setSize(BUTTON_WIDTH, BUTTON_HEIGHT);
			returnBtn->setColor(220, 220, 220);
			returnBtn->setOnClickCallback([]() {
				App::setCurrentView(App::getViewMainMenu());
				});
			this->addWidget(returnBtn);
			returnBtn->setHorizontallyCentered();
		}
		Button* applyBtn = new Button("Apply");
		{
			applyBtn->setPosition(0, 820);
			applyBtn->setSize(BUTTON_WIDTH, BUTTON_HEIGHT);
			applyBtn->setColor(181, 222, 255);
			applyBtn->setVisible(false);
			applyBtn->setOnClickCallback([]() {
				((ShoppingListView*)App::getViewShoppingList())->addElement(((ShoppingListView*)App::getViewShoppingList())->getInputTextPlus());
				});
			this->addWidget(applyBtn);
			applyBtn->setHorizontallyCentered();
			this->applyBtn = applyBtn;
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

void ShoppingListView::update()
{
	const char* text = ElementInput->getText();
	if (text[0] != 0) applyBtn->setVisible(true);
	else applyBtn->setVisible(false);
}

void ShoppingListView::loadProducts()
{
	for (int i = 0; i < lengthElementList; i++) {
		Rect* temp = new Rect();
		{
			temp->setPosition(0, contentOutset + outsetBetweenElement * i);
			temp->setSize(320, 60);
			temp->setColor(181, 222, 255);
			this->addWidget(temp);
			this->addWidgetsElementList(temp, i);
			temp->setHorizontallyCentered();
		}

		Rect* tempBanner = new Rect();
		{
			tempBanner->setPosition(350, contentOutset + outsetBetweenElement * i);
			tempBanner->setSize(40, 60);

			if (countList[i] >= 5)	 tempBanner->setColor(167, 233, 175);
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

			tempQty->setPosition(363, contentOutset + outsetBetweenElement * i + 15);
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
			tempText->setText(elementList[i].c_str());
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

				((ShoppingListView*)App::getViewShoppingList())->destroyElement(index, ((ShoppingListView*)App::getViewShoppingList())->getInputTextPlus());
				}, i);
			this->addWigdetVisibleList(tempPNG);
			this->addWidgetsElementList(tempPNG, i);
			this->addWidget(tempPNG);
		}

	}

	this->activeModify();
	this->inputTextPlusUpdate(this->getInputTextPlus());
}
