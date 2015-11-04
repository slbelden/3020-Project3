// WinnerTree.cpp
// Tournament Tree

// Meghan Haukaas

#include "WinnerTree.h"


//Creates a Leaf
WinnerTree::WinnerTree(int root)
{
	parent_ = nullptr;
	left_ = nullptr;
	right_ = nullptr;
	root_ = root;
	current_ = this;
}

// Creates an inner node
WinnerTree::WinnerTree(WinnerTree * left, WinnerTree * right, int root)
{
	left_ = left;
	right_ = right;
	root_ = root;
	parent_ = nullptr;
	current_ = this;
}

// retruns a pointer to the left tree
WinnerTree WinnerTree::getLeft()
{
	return *left_;
}

// returns a pointer to the right tree
WinnerTree WinnerTree::getRight()
{
	return *right_;
}

// returns a pointer to the parent tree
WinnerTree WinnerTree::getParent()
{
	return *parent_;
}

// returns the root value of a node
int WinnerTree::getRoot()
{
	return root_;
}

// returns a pointer to the current tree
WinnerTree * WinnerTree::getCurrent()
{
	return current_;
}

// Returns true if the node has null pointers for left
// and right trees (node is a leaf)
// Returns false if the left and right trees are nodes (node is full)
bool WinnerTree::isLeaf()
{
	if (left_ == nullptr)
	{
		return true;
	}
	return false;
}

// find the first node that had an internal node on the left
// and a leaf on the right
//creates a new node that replaces a leaf with a node
// with an internal node having the leaf on the left and the
// new leaf on the right
// returns a ponter to the new leaf
// insertNode reassigns parents
WinnerTree * WinnerTree::insertNode(int root)
{
	// a leaf
	WinnerTree leaf = WinnerTree(root);
	if (left_ == nullptr)
	{
		WinnerTree node = WinnerTree(current_, &leaf, 0);
		node.left_ = current_;
		node.right_ = &leaf;
		node.battle();
		leaf.parent_ = &node;
		parent_ = &node;
		return &leaf;
	}
	// a node on the left and a leaf on the right
	else if (!((*left_).isLeaf()) && (*right_).isLeaf())
	{
		WinnerTree node = WinnerTree(right_, &leaf, 0);
		node.parent_ = right_->parent_;
		right_ = &node;
		(*right_).parent_ = &node;
		leaf.parent_ = &node;
		node.battle();
		return &leaf;
	}
	// the left and right are nodes and
	// the left height is greater than the right height by 2
	else if (!((*(*left_).left_).isLeaf()) && (*(*right_).right_).isLeaf())
	{
		(*right_).insertNode(root);
	}
	// the left and right are both nodes
	else
	{
		(*left_).insertNode(root);
	}
}

// Adjusts the ansestors of a node to reflect the current winner
// Ideally applied to a newly created leaf
void WinnerTree::replay()
{
	if (parent_ != nullptr)
	{
		(*parent_).battle();
		(*parent_).replay();
	}
}

// set's the root of a node to the higher of its children's roots
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

// recursively calls battle to reflect the "winners" of each pair of nodes
// the highest value will be the root of the top node
//Tournament also assigns parents!
void WinnerTree::tournament()
{
	if (left_ != nullptr)
	{
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
WinnerTree * WinnerTree::fits(int test)
{
	if ((*current_).isLeaf())
	{
		if (root_ > test)
		{
			return current_;
		}
	}
	else if ((*left_).isLeaf())
	{
		(*left_).fits(test);
	}
	else if ((*right_).isLeaf())
	{
		(*right_).fits(test);
	}
	else
	{
		(*left_).fits(test);
		(*right_).fits(test);
	}
	return nullptr;
}