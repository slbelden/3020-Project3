// Meghan Haukaas
// Chris Ruiz
// Stephen Belden

// 2015-Oct-25

#pragma once

#include "Shelf.h"
#include "winTimer.h"
#include <vector>
#include <iostream>
#include <algorithm> // Just for bogus code, remove later
using std::cout;
using std::endl;
using std::vector;
using std::ostream;

Shelf::Shelf() {
	// Test constructor
	_shelf.push_back(Bin());
}

void Shelf::insertFirstFit(const vector<double> & list) {
	Timer timer;
	timer.start();

	// TODO - Implement algorithm

	// Bogus code just so time complexity isn't always 0
	// Using an algorithm known to be O(N log N)
	vector<double> nonConstList = list;
	std::sort(nonConstList.begin(), nonConstList.end());

	timer.stop();
	_time = timer();
}

void Shelf::insertBestFit(const vector<double> & list) {
	Timer timer;
	timer.start();

	// Bogus code just so time complexity isn't always 0
	// Using an algorithm known to be O(N log N)
	vector<double> nonConstList = list;
	std::sort(nonConstList.begin(), nonConstList.end());

	timer.stop();
	_time = timer();
}

int Shelf::getNumBins() const {
	return _shelf.size();
}

double Shelf::getTime() const {
	return _time;
}

ostream& operator<<(ostream& os, const Shelf& obj) {
	for each(Bin b in obj._shelf) {
		os << "{" << b.getFilled() << "}, ";
	}
	os << "\b\b"; // "\b\b" just moves the cursor back two spots,
	os << "  "; // so we also have to overwrite those spots with something.
	return os;
}