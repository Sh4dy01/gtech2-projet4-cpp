#pragma once

#include "View/View.h"
#include "View/InputText.h"


class SettingsView : public View
{
public:

	SettingsView();
	void ApplySettingsToBib();
	void ResetInputsText();
	bool IsInputsLogical();

	InputText** getInputsNumWidget() { return inputsNumCheck; }
	InputText** getInputsMoreThanZeroWidget() { return inputsMoreThanZeroCheck; }

private:
 
	InputText* maxBibInput;
	InputText* actualQtyInput;
	InputText* minFeedVolInput;

	InputText* inputsNumCheck[3];
	InputText* inputsMoreThanZeroCheck[2];
};
