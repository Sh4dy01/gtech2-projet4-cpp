#pragma once

#include "View/View.h"
#include "View/InputText.h"


class SettingsView : public View
{
public:

	SettingsView();

private:

	InputText* maxBibInput;
	InputText* actualQtyInput;
	InputText* minFeedVolInput;
};
