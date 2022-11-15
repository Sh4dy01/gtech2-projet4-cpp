#include "bib.h";

Bib::Bib() {
	maxBib = 330;
	actualQty = 100;
	minFeed = 50;
	maxFeed = 60;
	takeTime = reminder = 0;
	feedArray.clear();
}

void Bib::Refill() {
	this->actualQty = maxBib;
}

void Bib::BibReduction(int qtyToReduce) {
	this->actualQty -= qtyToReduce;
}

void Bib::ApplySettings(int maxBib, int maxFeed, int minFeed) {
	this->maxBib = maxBib;
	this->maxFeed = maxFeed;
	this->minFeed = minFeed;
}

void Bib::AddFeed(Feed feed) {
	feedArray.push_back(feed);
}
