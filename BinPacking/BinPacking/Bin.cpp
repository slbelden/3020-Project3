// Bin.cpp
// 
// Meghan Haukaas
// Chris Ruiz
// Stephen Belden
// 2015-Oct-25

#pragma once

#include "Bin.h"


Bin::Bin() {
	_size = 10;
	howFull = 0;
}

Bin::Bin(int size) {
	_size = size;
	howFull = 0;
}
