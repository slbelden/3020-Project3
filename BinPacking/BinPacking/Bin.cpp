// Meghan Haukaas
// Chris Ruiz
// Stephen Belden

// 2015-Oct-25

#pragma once

#include <iostream>
#include "Bin.h"
using std::cout;
using std::endl;

Bin::Bin() : filled(0) {}

double Bin::getFilled() const{
	return filled;
}

double Bin::getRoomLeft() const {
	return capacity - filled;
}

void Bin::insert(double object) {
	if(object > getRoomLeft()) {
		cout << "FATAL: Tried to insert an object into a bin with insufficent room."
			<< endl;
		exit(1);
	}
	else filled -= object;
}