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

	const char* GetQuantityFromInput() const { return quantityInput->getText(); }
	const char* GetReminderFromInput() const { return reminderInput->getText(); }
	Text* getDateWidget() const { return date; }

	void SetFullDate(time_t fullDate) { this->fullDate = fullDate; };


private:

	Text* date;
	time_t fullDate;
	InputText* quantityInput;
	InputText* reminderInput;

};
