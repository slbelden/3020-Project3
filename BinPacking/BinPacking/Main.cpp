// Stephen Belden

// 2015-Oct-20

#include <iostream>
#include <string>
#include <vector>
#include "Bin.h"
#include "Tests.h"
#include "Shelf.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::vector;

// Global Function Declarations
void generateRandom(unsigned int numGenerate);

int main() {
	cout << "This is my bin:" << endl << endl
		<< " ____#____" << endl;
	for(int i = 0; i < 7; i++) {
		cout << " |       |" << endl;
	}
	cout << " ---------" << endl
		<< endl << "There are many like it, but mine is well-packed."
		<< endl << endl;

	string command;
	unsigned int toGenerate = 0;
	cout << "Enter a command (tests, random, complexity): ";
	getline(cin, command);
	if(command.substr(0, 1) == string("t")) {
		cout << "Starting tests..." << endl;
		runTests();
	}
	else if(command.substr(0, 1) == string("r")) {
		cout << "Generate how many random objects? ";
		cin >> toGenerate;
		generateRandom(toGenerate);
	}
	else if(command.substr(0, 1) == string("c")) {
		cout << "This would test many input sizes and time the code." << endl;
	}
	else cout << "Unrecognized command." << endl;
	cout << endl << endl;
}

void generateRandom(unsigned int numGenerate) {
	vector<double> generated;
	cout << "This would generate " << numGenerate << " objects."
		<< endl;
	Shelf first = Shelf();
	Shelf best = Shelf();
	first.insertFirstFit(generated);
	best.insertBestFit(generated);
}