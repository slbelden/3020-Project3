// Bin.cpp
// Contains a specific amount of things.
// Meghan Haukaas
// Chris Ruiz
// Stephen Belden
// 2015-Oct-25

#pragma once

#include <iostream>
#include "Bin.h"

Bin::Bin() : filled(0) {}

unsigned int Bin::getFilled() const{
	return filled;
}

unsigned int Bin::getRoomLeft() const {
	return capacity - filled;
}

void Bin::insert(unsigned int object) {
	if(object > getRoomLeft()) {
		std::cout << "FATAL: Tried to insert an object into a bin with insufficent room."
			<< std::endl;
		exit(1);
	}
	else filled -= object;
}