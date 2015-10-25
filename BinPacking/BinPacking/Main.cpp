// Stephen Belden

// 2015-Oct-20

#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::vector;

// Global Function Declarations
void generateRandom(unsigned int numGenerate);
void insertFirstFit(const vector<double> & list);
void insertBestFit(const vector<double> & list);

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
	cout << "Enter a command (tests, random): ";
	getline(cin, command);
	if(command.substr(0, 1) == string("t")) {
		cout << "This would run the tests if the tests existed." << endl;
	}
	else if(command.substr(0, 1) == string("r")) {
		cout << "Generate how many random objects? ";
		cin >> toGenerate;
		generateRandom(toGenerate);
	}
	else cout << "Unrecognized command." << endl;
	cout << endl << endl;
}

void generateRandom(unsigned int numGenerate) {
	vector<double> generated;
	cout << "This would generate " << numGenerate << " objects."
		<< endl;
	insertBestFit(generated);
	insertFirstFit(generated);
}

void insertFirstFit(const vector<double> & list) {
	// TODO
}

void insertBestFit(const vector<double> & list) {
	// TODO
}