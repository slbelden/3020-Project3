// Methods for testing bin packing algorithms

// Meghan Haukaas
// Chris Ruiz
// Stephen Belden

// 2015-Oct-25

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include "Shelf.h"
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::stack;

// Test a specific input on both algorithms
void runTest(string msg, vector<double> input) {
	cout << endl << msg << endl
		<< "Input: ";
	if(input.size() >= 20) {
		cout << "Input size greater than 20, skipping printing";
	}
	else {
		for each (double n in input) cout << n << ", ";
	}
	cout << endl;
	Shelf A, B = Shelf();
	A.insertFirstFit(input);
	cout << "First Fit Output: " << A << endl;
	B.insertBestFit(input);
	cout << "Best Fit Output:  " << B << endl;
}

// Runs all tests
void runAllTestCases() {
	runTest("Test 1 - Inserting Nothing", {});
	runTest("Test 2 - Inserting 1 element equal to the bin size", {0.1});
	// TODO
}