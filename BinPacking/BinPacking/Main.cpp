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
	string command;
	int toGenerate = 0;
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
		cout << "This would test many input sizes and time the code." << endl;
		// TODO
	}
	else if(command.substr(0, 1) == string("e")) exit(0);
	else cout << "Unrecognized command." << endl;
	cout << endl;
}

void generateRandom(int numGenerate) {
	vector<double> generated;
	randomizeSeed();
	for(int i = 0; i < numGenerate; i++) generated.push_back(randUniform());
	cout << "Generated " << generated.size() << " random input objects." << endl;
	runTest("Test on Randomly Generated Input", generated);
}