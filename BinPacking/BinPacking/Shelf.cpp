// Meghan Haukaas
// Chris Ruiz
// Stephen Belden

// 2015-Oct-25

#pragma once

#include "Shelf.h"
#include <vector>
#include <iostream>
using std::cout;
using std::vector;
using std::ostream;

Shelf::Shelf() {
	// Test constructor
	_shelf.push_back(Bin());
}

void Shelf::insertFirstFit(const vector<double> & list) {
	// TODO
}

void Shelf::insertBestFit(const vector<double> & list) {
	// TODO
}

int Shelf::getNumBins() const {
	return _shelf.size();
}

ostream& operator<<(ostream& os, const Shelf& obj) {
	for each(Bin b in obj._shelf) {
		os << "{" << b.getFilled() << "}, ";
	}
	os << "\b\b"; // two backspaces, removes the ending ", " in the stream
	return os;
}