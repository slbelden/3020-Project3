// Bin.cpp
// Contains a specific amount of things.
// Meghan Haukaas
// Chris Ruiz
// Stephen Belden
// 2015-Oct-25

#pragma once

#include "Bin.h"


Bin::Bin() {
	// _size can be whatever default we decide
	_size = 10;
	howFull = 0;
	roomLeft = _size;
}

Bin::Bin(int size) {
	_size = size;
	howFull = 0;
	roomLeft = _size;
}

int Bin::getSize()
{
	return _size;
}

int Bin::getHowFull()
{
	return howFull;
}

int Bin::getRoomLeft()
{
	return roomLeft;
}

void Bin::addObject(int object)
{
	if (object <= roomLeft)
	{
		howFull+=object;
		roomLeft -= object;
	}
}