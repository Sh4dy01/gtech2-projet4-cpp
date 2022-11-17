#pragma once

#include "View/View.h"
#include "View/Widget.h"
#include "View/Text.h"
#include "View/Button.h"
#include "View/InputText.h"

class Rect;



class ShoppingListView : public View
{
public:

	ShoppingListView();
	int getLengthElementList();
	void setList(std::string tab);
	void initWidgetLists();

	
	void addWigdetVisibleList(Widget* w);
	void addUpdateTextList(Text* t);
	void addUpdateRectList(Rect* r);
	void addWidgetsElementList(Widget* w, int index);

	void activeModify();
	void activeUpdateTextList(int index);
	void activeUpdateRectList(int index);
	void inputTextPlusUpdate(InputText* btn);

	void popInt(int i, int* tab);

	int getCountListElement(int i);
	void setCountList(int i, int value);

	void initCountList();
	void destroyElement(int index, InputText* btn);
	void addElement(InputText* ipt);

	void setInputTextPlus(InputText* btn);
	InputText* getInputTextPlus();

	virtual void update() override;


private:

	InputText* ElementInput;

	/// temp list of elements to shop
	std::string elementList[5];
	int lengthElementList;

	/// temp list of count
	int countList[5];
	int lenghtCountList;

	/// manage modify mode
	Widget* widgetVisibleList[15];
	int lengthWidgetVisibleList;

	/// manage count of element
	Text* updateTextList[5];
	int lengthUpdateTextList;

	Rect* updateRectList[5];
	int lengthUpdateRectList;

	/// All 7 widget of each elements are contains here, used for remove an elements and move other accordingly
	Widget* widgetsElementList[7][5];
	int numberWidgetsElementList[5];

	Button* applyBtn;
};
