// Bin.h
// Contains a specific amount of things.
// Meghan Haukaas
// Chris Ruiz
// Stephen Belden
// 2015-Oct-25

#pragma once

class Bin {
public:
	static const unsigned int capacity = 1000000;

	Bin();
	unsigned int getFilled() const;
	unsigned int getRoomLeft() const;
	void insert(unsigned int object);

private:
	unsigned int filled;
};
