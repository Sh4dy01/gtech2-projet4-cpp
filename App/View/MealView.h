#pragma once

#include "View/View.h"
#include "View/InputText.h"

class Text;
class InputText;


class MealView : public View
{
public:

	MealView();
	void ResetInputs();
	void CreateMeal();

	bool IsInputsNumeric();

	Text* getDateWidget() const { return date; }
	const char* GetQuantityFromInput() const { return quantityInput->getText(); }
	const char* GetReminderFromInput() const { return reminderInput->getText(); }


private:

	Text* date;
	InputText* quantityInput;
	InputText* reminderInput;

};
