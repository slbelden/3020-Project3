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

Shelf::Shelf() {}

void Shelf::insertFirstFit(const vector<double> & list) {
	// TODO
}

void Shelf::insertBestFit(const vector<double> & list) {
	// TODO
}

int Shelf::getNumBins() const {
	return _shelf.size();
}

void Shelf::print() const {
	for each(Bin b in _shelf) {
		cout << "{" << b.getFilled() << "}, ";
	}
}

ostream& operator<<(ostream& os, const Shelf& obj) {
	obj.print();
	return os;
}