#pragma once

#include "View/View.h"
#include "View/Shapes.h"
#include "View/Image.h"

class Text;
class Image;


class MainMenuView : public View
{
public:

	MainMenuView();
	void UpdateBibVisual();
	virtual void update() override;

private:

	int currentQty;

	Rect* bibiActualIndicator;
	Rect* bibiMinLimitIndicator;
	Rect* bibActLine;
	Text* bibiActText;
	Text* bibiMinText;
	Text* bibiMaxText;

	Image* bibiPNG;

	Text* date;
	Text* timer;

	Text* errorFeedFirst;
};