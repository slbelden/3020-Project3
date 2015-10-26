// Has a capacity; can hold any number of objects as long as
// their combined size is less than the bin's capacity.

// Meghan Haukaas
// Chris Ruiz
// Stephen Belden

// 2015-Oct-25

#pragma once

class Bin {
public:
	double capacity = 1.0;

	Bin();
	double getFilled() const;
	double getRoomLeft() const;
	void insert(double object);

private:
	double filled;
};
