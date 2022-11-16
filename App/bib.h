#pragma once

#include <ctime>
#include <vector>

struct Feed {
    int feedQty;
    time_t takenTime;
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
    void AddFeed(Feed);

    inline int GetBibQty() { return actualQty; }
    inline int GetMaxBib() { return maxBib; }
    inline int GetMinFeed() { return minFeed; }
    inline int GetReminder() { return feedArray.back().reminder; }

private:
    int actualQty, maxBib, minFeed;

    std::vector<Feed> feedArray;
};