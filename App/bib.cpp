#include "bib.h";

Bib::Bib() {
	maxBib = 330;
	actualQty = maxBib;
	minFeed = 55;

	Meal startFeed{};
	startFeed.feedQty = 20;
	startFeed.IsRegurgitated = false;
	startFeed.takenTime = "";
	startFeed.reminder = 10;
	startFeed.reminderReducted = startFeed.reminder;

	mealArray.push_back(startFeed);
}

void Bib::Refill() {
	this->actualQty = maxBib;
}

void Bib::BibReduction(int qtyToReduce) {
	this->actualQty -= qtyToReduce;
}

void Bib::ReminderReduction() {
	int reminder = mealArray.back().reminder;
	int fullTimeInSeconds = mealArray.back().fullDate;
	int reminderReducted = reminder + fullTimeInSeconds;

	if (reminderReducted > fullTimeInSeconds) {
		reminderReducted--;
		mealArray.back().reminderReducted = reminderReducted;
	}
}

void Bib::ApplySettings(int maxBib, int minFeed) {
	this->maxBib = maxBib;
	this->minFeed = minFeed;
}

void Bib::AddMeal(Meal meal) {
	mealArray.push_back(meal);
}