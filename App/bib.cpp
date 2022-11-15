#include "bib.h";

Bib::Bib() {
	maxBib = 330;
	actualQty = maxBib;
	minFeed = 55;
	takeTime = 0;
	reminder = 6000; // in seconds

	Feed startFeed{};
	startFeed.feedQty = 20;
	startFeed.IsRegurgitated = false;
	startFeed.takenTime = NULL;
	startFeed.reminder = 1000;

	feedArray.push_back(startFeed);
}

void Bib::Refill() {
	this->actualQty = maxBib;
}

void Bib::BibReduction(int qtyToReduce) {
	this->actualQty -= qtyToReduce;
}

void Bib::ApplySettings(int maxBib, int minFeed) {
	this->maxBib = maxBib;
	this->minFeed = minFeed;
}

void Bib::AddFeed(Feed feed) {
	feedArray.push_back(feed);
}