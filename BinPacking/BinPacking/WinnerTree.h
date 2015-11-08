// WinnerTree.h
// Tournament Tree

// Meghan Haukaas

// 2015-Nov-03

#pragma once

class WinnerTree {
public:
	WinnerTree(int root);
	WinnerTree(WinnerTree * left, WinnerTree * right, int root);
	WinnerTree getLeft();
	WinnerTree getRight();
	WinnerTree getParent();
	WinnerTree * getCurrent();
	bool isLeaf();
	int getRoot();
	WinnerTree * insertNode(int root);
	void replay();
	void battle();
	void tournament();
	WinnerTree * fits(int test);
	void WinnerTree::print_inorder();
	void WinnerTree::inorder(WinnerTree* p);

private:
	int root_;
	WinnerTree * left_;
	WinnerTree * right_;
	WinnerTree * parent_;
	WinnerTree * current_;
};