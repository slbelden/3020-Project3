// BinarySearch.h
// Meghan Haukaas
// 2015-Nov-10

#pragma once
using namespace std;
#include <iostream>

class BinarySearch {
public:
	BinarySearch(double data);
	void addNode(double data);
	void insert(double object);
	void moveNode();
	bool isLeaf();
	void print();

private:
	BinarySearch* left_;
	BinarySearch* right_;
	BinarySearch* current_;
	double data_;
};