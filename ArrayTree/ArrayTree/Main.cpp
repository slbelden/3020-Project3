#include "arrayTree.h"
#include <iostream>
using namespace std;

int main() {
	ArrayTree A = ArrayTree(1.0);
	do {
		cout << "Enter a double 1 or less: ";
		double in;
		cin >> in;
		A.fit(in);
		A.print();
		cout << endl;
	} while(1);
}