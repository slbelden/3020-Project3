// Bin.h
// Contains a specific amount of things.
// Meghan Haukaas
// Chris Ruiz
// Stephen Belden
// 2015-Oct-25

#pragma once

class Bin {
public:
	Bin();
	Bin(int size);
	void addObject(int object);

private:
	int _size;
	int howFull;
	int roomLeft;
};
