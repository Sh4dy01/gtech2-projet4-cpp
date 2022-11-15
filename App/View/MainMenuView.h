#pragma once

#include "View/View.h"
#include "View/Forms.h"


class MainMenuView : public View
{
public:

	MainMenuView();

private:

	Rect* bibiActualIndicator;
	Rect* bibiMinLimitIndicator;
};