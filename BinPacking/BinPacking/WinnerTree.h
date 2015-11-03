// WinnerTree.h
// Tournament Tree

// Meghan Haukaas
#pragma once
class WinnerTree {
public:
	WinnerTree(int root);
	WinnerTree(WinnerTree * left, WinnerTree * right, int root);
	WinnerTree getLeft();
	WinnerTree getRight();
	WinnerTree getParent();
	int getRoot();
	void insertNumber(int insert);
	void replay();
	void battle();
	void tournament(WinnerTree win);


private:
	int root_;
	WinnerTree * left_;
	WinnerTree * right_;
	WinnerTree * parent_;
};