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
    void ApplySettings(int, int, int);
    void AddFeed(Feed);

    inline int GetBibQty() { return actualQty; }
    inline int GetMaxBib() { return maxBib; }
    inline int GetMaxFeed() { return maxFeed; }
    inline int GetMinFeed() { return minFeed; }
    inline int GetReminder() { return reminder; }

private:
    int actualQty, maxBib;
    int maxFeed, minFeed;

    int reminder;
    int takeTime;
    std::vector<Feed> feedArray;
};