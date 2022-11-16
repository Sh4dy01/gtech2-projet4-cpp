#include "bib.h";

Bib::Bib() {
	maxBib = 330;
	actualQty = maxBib;
	minFeed = 55;

	Feed startFeed{};
	startFeed.feedQty = 20;
	startFeed.IsRegurgitated = false;
	startFeed.takenTime = NULL;
	startFeed.reminder = 10;

	feedArray.push_back(startFeed);
}

void Bib::Refill() {
	this->actualQty = maxBib;
}

void Bib::BibReduction(int qtyToReduce) {
	this->actualQty -= qtyToReduce;
}

void Bib::ReminderReduction() {
	int reminder = feedArray.back().reminder;

	if (reminder > 0) reminder--;

	feedArray.back().reminder = reminder;
}

void Bib::ApplySettings(int maxBib, int minFeed) {
	this->maxBib = maxBib;
	this->minFeed = minFeed;
}

void Bib::AddFeed(Feed feed) {
	feedArray.push_back(feed);
}