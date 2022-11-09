#pragma once

class Bib {
public:
    Bib();
    Bib(int take_time, int min_feed, int max_feed, int max_bib);

    void Refill();
    void BibReduction(int);
private:
    int max_bib;
    int actual_quantity;
    int max_feed;
    int min_feed;

    int reminder;
    int take_time;
    bool IsRegurgitated;
};