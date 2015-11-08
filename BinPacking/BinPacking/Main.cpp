// Meghan Haukaas
// Chris Ruiz
// Stephen Belden

// 2015-Oct-25

#include <iostream>
#include <string>
#include <vector>
#include "Bin.h"
#include "Tests.h"
#include "Shelf.h"
#include "WinnerTree.h"
#include "RandomUtilities.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::vector;

// Global Function Declarations
void generateRandom(int numGenerate);

int main() {
	WinnerTree T = WinnerTree(1);
	cout << "At Construction:" << endl;
	T.print_inorder();
	cout << endl;

	T.insertNode(2);
	T.print_inorder();
	cout << endl;

	T.insertNode(3);
	T.print_inorder();
	cout << endl;

	T.insertNode(4);
	T.print_inorder();
	cout << endl;

	/*
	string command;
	int toGenerate;
	cout << "Enter a command (tests, random, complexity, exit): ";
	getline(cin, command);
	if(command.substr(0, 1) == string("t")) {
		cout << "Running All Test Casses..." << endl;
		runAllTestCases();
	}
	else if(command.substr(0, 1) == string("r")) {
		cout << "Generate how many random objects? ";
		cin >> toGenerate;
		generateRandom(toGenerate);
	}
	else if(command.substr(0, 1) == string("c")) {
		cout << endl << "This code will run unill an insert call takes longer than 10 seconds"
			<< endl << endl;
		for(int twice = 0; twice < 2; twice++) {
			double previousTime = 0.0;
			cout << ((twice == 0) ? "Best Fit:" : "First Fit:") << endl;
			for(int i = 1; previousTime < 10.0; i *= 2) {
				Shelf a = Shelf();
				vector<double> generated;
				for(int j = 0; j < i; j++) generated.push_back(randUniform());
				((twice == 0) ? a.insertBestFit(generated) : a.insertFirstFit(generated));
				// Make sure everything is lined up by inserting tabs only when the
				// int to be printed is short:
				cout << "Inserting " << generated.size() << ((i < 100000) ? "\t\t" : "\t")
					<< "elements using " << ((twice == 0) ? "best fit" : "first fit:")
					<< " took " << a.getTime() << " seconds." << endl;
				previousTime = a.getTime();
			}
			previousTime = 0.0;
			cout << endl << endl;
		}
	}
	else if(command.substr(0, 1) == string("e")) exit(0);
	else cout << "Unrecognized command." << endl << endl;
	*/
}

void generateRandom(int numGenerate) {
	vector<double> generated;
	randomizeSeed();
	for(int i = 0; i < numGenerate; i++) generated.push_back(randUniform());
	cout << "Generated " << generated.size() << " random input objects." << endl;
	runTest("Test on Randomly Generated Input", generated);
}