#pragma once

#include <string>
#include <ctime>
#include <vector>

struct Meal {
    int feedQty;
    std::string takenTime;
    bool IsRegurgitated;
    int reminder;
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
    /// <param name=""></param>
    /// <param name=""></param>
    void ApplySettings(int, int);
    void AddMeal(Meal);

    inline int GetBibQty() { return actualQty; }
    inline int GetMaxBib() { return maxBib; }
    inline int GetMinFeed() { return minFeed; }
    inline int GetReminder() { return mealArray.back().reminder; }

private:
    int actualQty, maxBib, minFeed;

    std::vector<Meal> mealArray;
};