#pragma once

#include "View/View.h"
#include "View/Widget.h"
#include "View/Text.h"

class Rect;



class ShoppingListView : public View
{
public:

	ShoppingListView();
	void setList(const char* tab);
	void initWidgetLists();
	
	void addWigdetList(Widget* w);
	void addUpdateTextList(Text* t);
	void addUpdateRectList(Rect* r);

	void activeModify();
	void activeUpdateTextList(int index);
	void activeUpdateRectList(int index);

	void popInt(int i, int* tab);

	int getCountListElement(int i);
	void setCountList(int i, int value);

	void initCountList();
	void destroyElement(int index);


private:

	/// temp list of elements to shop
	const char* list[5];
	int lengthList;

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




};
