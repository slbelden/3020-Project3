// Stephen Belden
// Meghang Haukaas

// 2015-Oct-25

#pragma once

#include "Bin.h"
#include <vector>
using std::vector;

// Holds, creates, prints and manages a collection of bins
class Shelf {
public:
	Shelf();
	void insertFirstFit(const vector<double> & list);
	void insertBestFit(const vector<double> & list);

private:
	vector<Bin> _shelf;
};
