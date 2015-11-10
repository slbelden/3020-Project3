// arrayTree, an implementation of a Max Winner Tournament Tree
// using level-by-level arrays to store nodes.

// The tree is built upside-down, so that new layers can be added at the
// end (bottom) of the list of layers, which avoids the overhead of
// shifting every layer down by one when a new layer is needed.
// The 0th (top) layer contains the leaves of the tree.
// No other layers contain leaves, and the 0th layer never contains internal
// nodes. To achieve this, some leaves may be referenced by more than one
// internal node. This is fine, and does not affect this specific application
// of a Tournament Tree.

// Each layer has n/2 or n/2 + 1 elements where n is the number of elements in
// the layer above. This means there are log(N) layers for any N elements,
// just like any other binary tree structure.
// This allows O(log N) insertions and finds.

// Implemented as an array of arrays because fuck pointers.

// Stephen Belden
// 2015-Nov-09

#pragma once

#include <vector>
using namespace std;

class ArrayTree {
public:
	ArrayTree(double data);
	void insert(double data);
	void print() const;

private:
	vector<vector<double>> tree;
};