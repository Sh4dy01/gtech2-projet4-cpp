#pragma once

#include "View/View.h"
#include "View/Forms.h"

class Text;


class MainMenuView : public View
{
public:

	MainMenuView();
	virtual void update() override;

private:

	Text* date;
	Text* timer;
};