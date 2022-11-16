#include "bib.h";
#include "App.h";
#include <iostream>

Bib::Bib() {
	maxBib = 330;
	actualQty = maxBib;
	minFeed = 55;
}

void Bib::Refill() {
	this->actualQty = maxBib;
}

void Bib::BibReduction(int qtyToReduce) {
	this->actualQty -= qtyToReduce;
}

void Bib::ReminderReduction() {
	const int currentTime = int(App::GetCurrentTime());
	const int reminderTotal = lastMeal.reminderTotal;
	const int reminderStartTime = lastMeal.fullDate;

	int actualReminder = reminderStartTime + reminderTotal - currentTime;

	if (actualReminder > 0) {
		actualReminder--;
		lastMeal.actualReminder = actualReminder;
	}
}

void Bib::ApplySettings(int maxBib, int minFeed) {
	this->maxBib = maxBib;
	this->minFeed = minFeed;
}

void Bib::AddMeal(Meal meal) {
	mealArray.push_back(meal);
	lastMeal = meal;
}