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
	void insertNode(int root);
	void replay();
	void battle();
	void tournament();
	WinnerTree * fits(int test);
	bool isPerm();
	void WinnerTree::print_inorder();
	void WinnerTree::inorder(WinnerTree* p);
	int maxHeight() const;

private:
	int root_;
	WinnerTree * left_;
	WinnerTree * right_;
	WinnerTree * parent_;
	WinnerTree * current_;
	bool perm;

	int calcHeight(WinnerTree* node) const;
};