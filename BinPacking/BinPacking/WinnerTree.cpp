// WinnerTree.cpp
// Tournament Tree

// Meghan Haukaas

// 2015-Nov-03

#include <iostream>
using std::cout;
#include "WinnerTree.h"

//Creates a Leaf
WinnerTree::WinnerTree(int root) {
	parent_ = nullptr;
	left_ = nullptr;
	right_ = nullptr;
	root_ = root;
	current_ = this;
}

// Creates an inner node
WinnerTree::WinnerTree(WinnerTree * left, WinnerTree * right, int root) {
	left_ = left;
	right_ = right;
	root_ = root;
	parent_ = nullptr;
	current_ = this;
}

// retruns a pointer to the left tree
WinnerTree WinnerTree::getLeft() {
	return *left_;
}

// returns a pointer to the right tree
WinnerTree WinnerTree::getRight() {
	return *right_;
}

// returns a pointer to the parent tree
WinnerTree WinnerTree::getParent() {
	return *parent_;
}

// returns the root value of a node
int WinnerTree::getRoot() {
	return root_;
}

// returns a pointer to the current tree
WinnerTree * WinnerTree::getCurrent() {
	return current_;
}

// Returns true if the node has null pointers for left
// and right trees (node is a leaf)
// Returns false if the left and right trees are nodes (node is full)
bool WinnerTree::isLeaf() {
	if(left_ == nullptr) {
		return true;
	}
	return false;
}

// find the first node that had an internal node on the left
// and a leaf on the right
// creates a new node that replaces a leaf with a node
// with an internal node having the leaf on the left and the
// new leaf on the right
// returns a ponter to the new leaf
// insertNode reassigns parents
void WinnerTree::insertNode(int root) {
	WinnerTree* leaf = new WinnerTree(root);
	WinnerTree* original = new WinnerTree(root_);

	// base case
	if(left_ == nullptr) {
		left_ = original;
		right_ = leaf;
		leaf->parent_ = current_;
		original->parent_ = current_;
		leaf->replay();
	}

	// height case
	else {
		// get heights
		int rightHeight = 1, leftHeight = 1;
		WinnerTree* temp = left_;
		while(temp != nullptr) {
			leftHeight++;
			temp = temp->left_;
		}
		temp = right_;
		while(temp != nullptr) {
			rightHeight++;
			temp = temp->left_;
		}

		// chose direction
		if(rightHeight > leftHeight) {
			(*left_).insertNode(root);
		}
		else {
			(*right_).insertNode(root);
		}
	}


	/*
	// a node on the right and a leaf on the left
	else if(!((*right_).isLeaf()) && (*left_).isLeaf()) {
		(*left_).insertNode(root);
	}
	else if (!((*right_).isLeaf()) && (*left_).isLeaf())
	{
		left_ = original;
		right_ = leaf;
		original->parent_ = current_;
		leaf->parent_ = current_;
		leaf->replay();
	}
	// the left and right are nodes and
	// the left height is greater than the right height by 2
	else if (!((*(*left_).right_).isLeaf()) && (*(*right_).right_).isLeaf())
	{
		(*right_).insertNode(root);
	}
	// the left and right are both nodes
	else
	{
		(*left_).insertNode(root);
	}
	*/
}

// Adjusts the ansestors of a node to reflect the current winner
// Ideally applied to a newly created leaf
void WinnerTree::replay() {
	if(parent_ != nullptr) {
		(*parent_).battle();
		(*parent_).replay();
	}
}

// set's the root of a node to the higher of its children's roots
void WinnerTree::battle() {
	if(left_->root_ >= right_->root_) {
		root_ = left_->root_;
	}
	else {
		root_ = right_->root_;
	}
}

// recursively calls battle to reflect the "winners" of each pair of nodes
// the highest value will be the root of the top node
// Tournament also assigns parents!
void WinnerTree::tournament() {
	if(left_ != nullptr) {
		(*current_).battle();
		WinnerTree * left = left_;
		(*left).battle();
		WinnerTree * right = right_;
		(*right).battle();
		right_->parent_ = current_;
		left_->parent_ = current_;
	}
}

// returns a pointer to the first node with a root larger
// than the input
// if the input is larger than any roots, nullptr is returned
WinnerTree * WinnerTree::fits(int test) {
	if((*current_).isLeaf()) {
		if(root_ > test) {
			return current_;
		}
	}
	else if((*left_).isLeaf()) {
		(*left_).fits(test);
	}
	else if((*right_).isLeaf()) {
		(*right_).fits(test);
	}
	else {
		(*left_).fits(test);
		(*right_).fits(test);
	}
	return nullptr;
}

void WinnerTree::print_inorder() {
	inorder(current_);
}

void WinnerTree::inorder(WinnerTree* p) {
	if(p != nullptr) {
		if(p->left_) inorder(p->left_);
		cout << " " << p->root_ << " ";
		if(p->right_) inorder(p->right_);
	}
}