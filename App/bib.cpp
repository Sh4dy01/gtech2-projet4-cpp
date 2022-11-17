#include "bib.h"
#include "App.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


static const char* const SETTINGS_FILENAME = "settings.txt";


Bib::Bib() {
	// Set default values in case settings file does not exist.
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

	std::cout << actualReminder << std::endl;

	if (actualReminder > 0) {
		actualReminder--;
	}
	else {
		actualReminder = 0;
	}

	lastMeal.actualReminder = actualReminder;
	mealArray.back().actualReminder = actualReminder;
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

	// If settings file does not exist yet, save default values.
	if (!f) {
		this->saveSettings();
		return;
	}

	string line, id;
	while (!f.eof())
	{
		// Get line.
		getline(f, line);

		// Ignore empty line.
		if (line.empty()) {
			continue;
		}

		// Formatted reading.
		stringstream ss(line);
		ss >> id;

		if      (id == "feedCapacity") ss >> this->maxBib;
		else if (id == "remainingVol") ss >> this->actualQty;
		else if (id == "minimumFeed")  ss >> this->minFeed;

		else if (id == "meal") {

			Meal m;
			ss
				>> m.feedQty >> m.IsRegurgitated
				>> m.reminderTotal >> m.actualReminder
				>> m.fullDate;

			std::cout << "loaded : " << m.reminderTotal << ", " << m.actualReminder << std::endl;

			mealArray.push_back(m);
		}
	}

	if (mealArray.size() > 0) { lastMeal = mealArray.back(); }

	f.close();
}

void Bib::saveSettings()
{
	ofstream f(SETTINGS_FILENAME);

	f << "feedCapacity " << this->maxBib << endl;
	f << "remainingVol " << this->actualQty << endl;
	f << "minimumFeed "  << this->minFeed << endl;

	for (Meal& m : mealArray) {
		std::cout << "saved : " << m.reminderTotal << ", " << m.actualReminder << std::endl;

		f << "meal "
			<< m.feedQty << ' ' << (m.IsRegurgitated ? 1 : 0) << ' '
			<< m.reminderTotal << ' ' << m.actualReminder << ' '
			<< m.fullDate
			<< endl;
	}

	f.close();
}
