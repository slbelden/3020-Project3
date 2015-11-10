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
#include <algorithm>
#include "RandomUtilities.h"
#include "winTimer.h"
using std::cout;
using std::cin;
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
	ArrayTree A = ArrayTree(1.0);
	Timer T = Timer();
	T.start();
	for each (double n in input) A.fit(n);
	T.stop();
	cout << "First Fit Output: " << endl;
	A.printBins();
	cout << endl << "First Fit - Elapsed time: " << T() << " seconds." << endl;
}

// Runs all tests
void runAllTestCases() {
	// Test 1
	runTest("Test 1 - Inserting Nothing", { });
	
	// Test 2
	runTest("Test 2 - Inserting 1 element equal to the bin size", { 1.0 });
	
	// Test 3
	runTest("Test 3 - Inserting 1 element larger than the bin size", { 5.0 });
	
	// Test 4
	double n;
	cout << endl << "Provide an n-value (n > 0) for Test 4: ";
	cin >> n;
	vector<double> collection;
	if (n > 0) {
		for (int i = 0; i < n; i++) {
			collection.push_back((double)(1.0 / n));
		}
	}
	runTest("Test 4 - Inserting n elements of size 1/n bin", collection);
	collection.clear();

	// Test 5
	cout << endl << "Provide an n-value (n > 0) for Test 5: ";
	cin >> n;
	if (n > 0) {
		for (int i = 0; i < n; i++) {
			collection.push_back((double)(2.0 / n));
		}
	}
	runTest("Test 5 - Inserting n elements of size 2/n bin", collection);
	collection.clear();

	// Test 6
	runTest("Test 6 - Inserting unequal objects adding up to size 1 bin", { 0.5, 0.3, 0.2 });

	// Test 7
	// Utilizes custom "bloating" algorithm to create large amounts of input data
	cout << endl << "Provide an n-value (n > 0) for Test 7: ";
	cin >> n;
	if (n > 0) {
		stack<double> splittingStack;

		// Step 1: Throw two initial double values onto the stack for every requested bin.
		//         The stack values should sum to n (1.0 for each 1 bin, or a perfect fit).
		for (int i = 0; i < n; i++) {
			double start = randUniform();
			splittingStack.push(start);
			splittingStack.push(1.0 - start);
		}	

		// Step 2: "Bloat" the values.
		//         We will only accept the values if they are less than or equal to 0.2.
		//         Collect acceptable values, or create one acceptable value and another value to bloat.
		//         Repeat the process as necessary until all values have been reduced to acceptable levels.
		while (!(splittingStack.empty())) {
			if (splittingStack.top() > 0.2) {
				double temp = splittingStack.top();
				splittingStack.pop();
				splittingStack.push(temp * 0.2);
				splittingStack.push(temp * 0.8);
			}
			else {
				collection.push_back(splittingStack.top());
				splittingStack.pop();
			}
		}
	}

	// Step 3: Shuffle the collection
	random_shuffle(collection.begin(), collection.end());
	runTest("Test 7 - Inserting large set of perfectly fitting objects into n bins", collection);
	collection.clear();

	// Test 8
	cout << endl << "Provide an n-value (n > 0) for Test 8: ";
	cin >> n;
	if (n > 0) {
		for (int i = 0; i < n; i++) {
			collection.push_back(randUniform());
		}
	}
	runTest("Test 8 - Inserting n objects of size k", collection);
	collection.clear();

	// Edge Case Test 1
	runTest("Edge Case Test 1", { 0.6, 0.6, 0.4 });

	// Edge Case Test 2
	runTest("Edge Case Test 2", { 0.5, 0.6, 0.3, 0.4 });

	// Edge Case Test 3
	runTest("Edge Case Test 3", { 0.5, 0.6, 0.3, 0.1, 0.5 });

	// Edge Case Test 4
	runTest("Edge Case Test 4", { 0.5, 0.6, 0.3, 0.4, 0.2 });

}