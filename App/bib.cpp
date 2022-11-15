#include "bib.h";

Bib::Bib() {
	maxBib = 330;
	actualQty = maxBib;
	minFeed = 55;
	takeTime = reminder = 0;
	feedArray.clear();
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
