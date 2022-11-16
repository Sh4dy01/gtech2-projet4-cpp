#pragma once

#include "View/View.h"
#include "View/Shapes.h"

class Text;


class MainMenuView : public View
{
public:

	MainMenuView();
	void UpdateBibVisual();
	virtual void update() override;

private:

	int currentQty;
	Rect* bibiActualIndicator;
	Text* date;
	Text* timer;
};