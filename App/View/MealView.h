#pragma once

#include "View/View.h"

class Text;



class MealView : public View
{
public:

	MealView();
	void update();

	Text* getDateWidget() const { return date; }

private:

	Text* date;

};
