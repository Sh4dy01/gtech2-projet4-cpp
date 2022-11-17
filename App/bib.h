#pragma once

#include <string>
#include <ctime>
#include <vector>

struct Meal {
	int feedQty;
	time_t fullDate;
	std::string takenTime;
	bool IsRegurgitated;
	int reminderTotal;
	int actualReminder;
};

class Bib {
public:

	Bib();

	void Refill();
	void BibReduction(int);

	/// <summary>
	/// Reduce the reminder every second
	/// </summary>
	void ReminderReduction();

	/// <summary>
	/// Apply all the settings to the bib
	/// </summary>
	void ApplySettings(int maxBib, int actBib, int minFeed);
	void AddMeal(Meal);

	inline int GetBibQty() { return actualQty; }
	inline int GetMaxBib() { return maxBib; }
	inline int GetMinFeed() { return minFeed; }
	inline int GetReminder() { if (mealArray.size() > 0) return lastMeal.actualReminder; }

	void IncrementEasterEgg();

	void loadSettings();
	void saveSettings();


private:
	int actualQty, maxBib, minFeed;
	int easterEgg = 0;
	Meal lastMeal;
	std::vector<Meal> mealArray;
};