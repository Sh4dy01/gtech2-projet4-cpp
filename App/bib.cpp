#include "bib.h"
#include "App.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


static const char* const SETTINGS_FILENAME = "settings.txt";


Bib::Bib() {
	maxBib = 330;
	actualQty = 120;
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

void Bib::ApplySettings(int maxBib, int actBib, int minFeed) {
	this->maxBib = maxBib;
	this->actualQty = actBib;
	this->minFeed = minFeed;
}

void Bib::AddMeal(Meal meal) {
	mealArray.push_back(meal);
	lastMeal = meal;
}

void Bib::loadSettings()
{
	ifstream f(SETTINGS_FILENAME);

	string line, id;
	while (!f.eof())
	{
		// Get line.
		getline(f, line);

		// Ignore empty line.
		if (line.empty()) {
			continue;
		}

		stringstream ss(line);
		ss >> id;
	}

	f.close();
}

void Bib::saveSettings()
{
	ofstream f(SETTINGS_FILENAME);

	f << "feedCapacity " << this->maxBib << endl;
	f << "remainingVol " << this->actualQty << endl;
	f << "minimumFeed "  << this->minFeed << endl;

	f.close();
}
