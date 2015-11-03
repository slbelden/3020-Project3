// WinnerTree.cpp
// Tournament Tree

// Meghan Haukaas

#include "WinnerTree.h"

WinnerTree::WinnerTree(int root)
{
	parent_ = nullptr;
	left_ = nullptr;
	right_ = nullptr;
	root_ = root;
}
WinnerTree::WinnerTree(WinnerTree * left, WinnerTree * right, int root)
{
	left_ = left;
	right_ = right;
	root_ = root;
}

WinnerTree WinnerTree::getLeft()
{
	return *left_;
}

WinnerTree WinnerTree::getRight()
{
	return *right_;
}

WinnerTree WinnerTree::getParent()
{
	return *parent_;
}

int WinnerTree::getRoot()
{
	return root_;
}

void WinnerTree::insertNumber(int insert)
{

}

void WinnerTree::replay()
{

}

void WinnerTree::battle()
{
	if (left_->root_ >= right_->root_)
	{
		root_ = left_->root_;
	}
	else
	{
		root_ = right_->root_;
	}
}


void WinnerTree::tournament(WinnerTree win)
{
	/*
	if (left_ != nullptr)
	{
		win.battle();
		WinnerTree * left = win.left_;
		*left.battle();
		WinnerTree * right = win.right_;
		*right.battle();
		right_->parent_ = &win;
		left_->parent_ = &win;
	}
	*/
}