#include "arrayTree.h"
#include <iostream>
using namespace std;

int main() {
	ArrayTree A = ArrayTree(1.0);
	for(double i = 2.0; i <= 20.0; i += 1.0) {
		A.insert(i);
		A.print();
		cout << endl << endl;
	}
}