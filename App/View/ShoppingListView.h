#pragma once

#include "View/View.h"
#include "View/Widget.h"



class ShoppingListView : public View
{
public:

	ShoppingListView();
	void setList(const char* tab);
	void activeModify();
	void initWidgetLists();
	void addWigdetList(Widget* w);
	void addUpdateWidgetList(Widget* w, int i);

	int getCountListElement(int i);
	void setCountList(int i, int value);

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

	Widget* updateWidgetList[5][5];
	int lengthUpdateWidgetList;
};
