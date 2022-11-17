#pragma once

#include "View/View.h"
#include "View/InputText.h"


class SettingsView : public View
{
public:

	SettingsView();
	void ApplySettingsToBib();
	bool IsInputsLogical();

	InputText** getInputsNumWidget() { return inputsNumCheck; }
	InputText** getInputsMoreThanZeroWidget() { return inputsMoreThanZeroCheck; }

	void inline SetActQtyInput(int value) { actualQtyInput->setText(std::to_string(value).c_str()); };

private:
 
	InputText* maxBibInput;
	InputText* actualQtyInput;
	InputText* minFeedVolInput;

	InputText* inputsNumCheck[3];
	InputText* inputsMoreThanZeroCheck[2];
};
