#pragma once

#include "View/View.h"



class ShoppingListView : public View
{
public:

	ShoppingListView();
	void setList(const char* tab);
	void setIsModify();

private:

	const char* list[5];
	int lengthList = 2;
	bool isModify;
};
