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
	while(1) {
		string command;
		unsigned int toGenerate = 0;
		cout << "Enter a command (tests, random, exit): ";
		char commandLetter;
		cin >> commandLetter;
		switch(commandLetter) {
		case 't':
			cout << "This would run the tests if the tests existed."
				<< endl;
			break;
		case 'r':
			cout << "Generate how many random objects? ";
			cin >> toGenerate;
			generateRandom(toGenerate);
			break;
		case 'e': exit(0);
		default:
			cout << "Unrecognized command." << endl;
		};
		cout << endl << endl;
	}
}

void generateRandom(unsigned int numGenerate) {
	cout << "This would generate " << numGenerate << " objects."
		<< endl;
}