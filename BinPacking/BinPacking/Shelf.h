// Holds, creates, prints and manages a collection of bins

// Meghan Haukaas
// Chris Ruiz
// Stephen Belden

// 2015-Oct-25

#pragma once

#include "Bin.h"
#include <vector>
#include <iostream>
using std::vector;
using std::ostream;

class Shelf {
public:
	Shelf();
	void insertFirstFit(const vector<double> & list);
	void insertBestFit(const vector<double> & list);
	int getNumBins() const;
	void Shelf::print() const;

private:
	vector<Bin> _shelf;
};

ostream& operator<<(ostream& os, const Shelf& obj);