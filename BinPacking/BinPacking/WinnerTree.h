// WinnerTree.h
// Tournament Tree

// Meghan Haukaas

// 2015-Nov-03

#pragma once
#include "Bin.h"

class WinnerTree {
public:
	WinnerTree(double root);
	WinnerTree(WinnerTree * left, WinnerTree * right, double root);
	WinnerTree getLeft();
	WinnerTree getRight();
	WinnerTree getParent();
	WinnerTree * getCurrent();
	bool isLeaf();
	int getRoot();
	void insertNode(double root);
	void replay();
	void battle();
	void tournament();
	WinnerTree * fits(double test);
	bool isPerm();
	void WinnerTree::print_inorder();
	void WinnerTree::inorder(WinnerTree* p);
	int maxHeight() const;
	void insertObject(double object);

private:
	double root_;
	WinnerTree * left_;
	WinnerTree * right_;
	WinnerTree * parent_;
	WinnerTree * current_;
	bool perm_;
	Bin * bin_;

	int calcHeight(WinnerTree* node) const;
};