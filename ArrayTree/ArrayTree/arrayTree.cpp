// arrayTree

// Stephen Belden

// 2015-Nov-09

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#include "arrayTree.h"

// initial constructor, tree must be initialized with 1 leaf
// and an initial internal node that holds the first winner
ArrayTree::ArrayTree(double data) {
	tree.push_back(vector<double>{data});
	tree.push_back(vector<double>{data});
}

void ArrayTree::insert(double data) {
	// Add the data to the leaf level
	tree[0].push_back(data);

	// Replay the inner nodes below the inserted node
	unsigned int level = 0;
	do {
		unsigned int numThisLevel = tree[level].size();
		// If there are an odd number of leaves in this level
		// add one to the num of leaves before devision,
		// so we still reach the correct node
		if(tree[level].size() % 2 == 1) numThisLevel++;

		// The node we need to update is always the n/2th (or n/2 + 1)th node
		// in the level below
		unsigned int nodeToChange = numThisLevel / 2;

		// Because we're dealing with vectors, wich start at 0, but doing math
		// with counting numbers, which start at 1, we need to subtract one.
		nodeToChange--;

		// If the node to change doesn't exist in the level below,
		// create it, and fill it with junk data
		// If the entire level below doesn't exist, well then we should
		// probably create that too.
		// Again we convert from counting numbers given by size()
		// to array locations by subtracting 1.
		if(tree.size() <= level + 1) tree.push_back(vector<double>{0.0});
		if(tree[level + 1].size() - 1 < nodeToChange) {
			tree[level + 1].push_back(0.0);
		}

		// Because this is an insertion, the elements to compare will always
		// be the last and second to last element in this level.
		// Find the max, and put the winner in the inner node.
		tree[level + 1][nodeToChange]
			= max(tree[level][tree[level].size() - 1],
				tree[level][tree[level].size() - 2]);

		level++;
	} while(tree[level].size() > 1);
}

void ArrayTree::print() const {
	for(unsigned int row = 0; row < tree.size(); row++) {
		for(unsigned int element = 0; element < tree[row].size(); element++) {
			cout << tree[row][element];
			for(unsigned int i = 0; i < row+1; i++) {
				cout << " ";
			}
		}
		cout << endl;
	}
}