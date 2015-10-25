// Stephen Belden
// Meghang Haukaas

// 2015-Oct-25

#pragma once

#include <iostream>
#include <vector>
#include "Shelf.h"

using std::cout;
using std::endl;
using std::vector;

// Runs all tests, prints output
void runTests() {
	cout << endl
		<< "Test 1: Inserting Nothing" << endl
		<< "Input:" << endl
		<< "Expected Output: bin1{}" << endl;
	vector<double> test1;
	Shelf A = Shelf();
	A.insertBestFit(test1);
	cout << "Best Fit output:" << endl;
	Shelf B = Shelf();
	B.insertFirstFit(test1);
	cout << "First Fit output:" << endl;
}