// BinarySearch.cpp
// Meghan Haukaas
// 2015-Nov-09

#include "BinarySearch.h"

BinarySearch::BinarySearch(double data) {
	data_ = data;
	left_ = nullptr;
	right_ = nullptr;
	current_ = this;
	parent_ = nullptr;
}

void BinarySearch::addNode(double data) {
	BinarySearch* newNode = new BinarySearch(data);
	if(left_ == nullptr || right_ == nullptr) {
		if(newNode->data_ > data_) {
			right_ = newNode;
			right_->parent_ = current_;
		}
		else {
			left_ = newNode;
			left_->parent_ = current_;
		}
	}
	else if(newNode->data_ > data_) {
		(*right_).addNode(data);
	}
	else {
		(*left_).addNode(data);
	}
}

void BinarySearch::insert(double object) {
	if(object > 1.0 || object < 0.0) {
		cout << "Tried to insert an object larger than 1.0 or smaller than 0.0" << endl
			<< "Nothing was inserted." << endl;
	}
	else {
		object -= 0.00000000001; // Double precision fudge
		if(object == data_) {
			if (parent_ == nullptr && isLeaf()) {
				data_ -= object;
			}
			// *****CHANGED	
			else {
				BinarySearch* tmp = parent_;
				double temp = data_;
				deleteNode();
				(*tmp).addNode(temp - object);
				
			}
		}
		else if(object > data_) {
			if(right_ == nullptr) {
				addNode(1.0 - object);
			}
			else {
				(*right_).insert(object);
			}
		}
		else {
			if (left_ == nullptr) {
				if (parent_ == nullptr && isLeaf()) {
					data_ -= object;
				}
				//******CHANGED
				else {
					BinarySearch* tmp = parent_;
					double temp = data_;
					deleteNode();
					(*tmp).addNode(temp - object);
					

				}
			}
			else {
				(*left_).insert(object);
			}
		}
	}
}

void BinarySearch::deleteNode() {
	// node to be deleted is a leaf
	if (isLeaf()) {
		// node is to the left of parent
		if (parent_->left_ == current_) {
			parent_->left_ = nullptr;
			current_->parent_ = nullptr;
			//delete current_;
		}
		// node is to the right of parent
		else {
			parent_->right_ = nullptr;
			current_->parent_ = nullptr;
			//delete current_;
		}
	}
	//node to be deleted has one child
	else if (left_ == nullptr || right == nullptr) {
		// child is on the left of node
		if (left_ != nullptr) {
			// current is the root
			if (parent_ == nullptr) {
				BinarySearch* temp = current_;
				current_ = left_;
				temp->left_ = nullptr;
				//delete temp;
			}
			else if (parent_->left_ == current_) {
				parent_->left_ = left_;
			}
			else {
				parent_->right_ = left_;
			}
		}
		// child is on the right of node
		else {
			// current is the root
			if (parent_ == nullptr) {
				BinarySearch* temp = current_;
				current_ = right_;
				temp->right_ = nullptr;
				//delete temp;
			}
			else if (parent_->left_ == current_) {
				parent_->left_ = right_;
			}
			else {
				parent_->right_ = right_;
			}
		}
	}
	// node has two children
	else {
		BinarySearch* temp = (*right_).findMin();
		data_ = temp->data_;
		(*temp).deleteNode();
	}
}

BinarySearch* BinarySearch::findMin() {
	if (isLeaf() || left_ == nullptr) {
		return current_;
	}
	else {
		(*left_).findMin();
	}
}

/*void BinarySearch::moveNode() {
	if(left_ != nullptr) {
		if(left_->data_ > data_) {
			BinarySearch* temp = left_;
			left_ = current_;
			current_ = temp;
			moveNode();
		}
	}
	else if (right_ != nullptr) {
			if(right_->data_ < data_) {
				BinarySearch* temp = right_;
				right_ = current_;
				current_ = temp;
				moveNode();
			}
	}
}*/

bool BinarySearch::isLeaf() const {
	if(left_ == nullptr && right_ == nullptr) {
		return true;
	}
	return false;
}

void BinarySearch::print() const {
	cout << data_ << " ";
	if(left_ != nullptr) {
		(*left_).print();
	}
	if(right_ != nullptr) {
		(*right_).print();
	}
}