#pragma once

#include "View/View.h"
#include "View/InputText.h"
#include "View/Button.h"

class Text;
class InputText;
class Button;


class MealView : public View
{
public:

	MealView();
	void ResetInputs();
	void CreateMeal();
	void SwitchButtonColor();

	const char* GetQuantityFromInput() const { return quantityInput->getText(); }
	const char* GetReminderFromInput() const { return reminderInput->getText(); }

	Text* getDateWidget() const { return date; }
	InputText** getInputsNumWidget() { return inputsNumCheck; }
	InputText** getInputsMoreThanZeroWidget() { return inputsMoreThanZeroCheck; }

	void SetFullDate(time_t fullDate) { this->fullDate = fullDate; };
	void SetIsRegurgitated(bool state) { isRegurgitated = state; };


private:
	bool isRegurgitated = false;

	Text* date;
	time_t fullDate;

	Button* noButton;
	Button* yesButton;

	InputText* quantityInput;
	InputText* reminderInput;

	InputText* inputsNumCheck[2];
	InputText* inputsMoreThanZeroCheck[1];

};
