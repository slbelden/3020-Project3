// Bin.cpp
// Contains a specific amount of things.
// Meghan Haukaas
// Chris Ruiz
// Stephen Belden
// 2015-Oct-25

#pragma once

#include "Bin.h"


Bin::Bin() {
	// _size can be whatever we decide
	_size = 10;
	howFull = 0;
	roomLeft = _size;
}

Bin::Bin(int size) {
	_size = size;
	howFull = 0;
	roomLeft = _size;
}

void Bin::addObject(int object)
{
	if (object <= roomLeft)
	{
		howFull+=object;
		roomLeft -= object;
	}
}