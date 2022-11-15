#pragma once

#include <ctime>
#include <vector>

struct Feed {
    int feedQty;
    time_t takenTime;
    bool IsRegurgitated;
};

class Bib {
public:
    Bib();

    void Refill();
    void BibReduction(int);
    void ApplySettings(int, int);
    void AddFeed(Feed);

    inline int GetBibQty() { return actualQty; }
    inline int GetMaxBib() { return maxBib; }
    inline int GetMinFeed() { return minFeed; }
    inline int GetReminder() { return reminder; }

private:
    int actualQty, maxBib, minFeed;
    int reminder, takeTime;

    std::vector<Feed> feedArray;
};