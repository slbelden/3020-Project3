// BinarySearch.cpp
// Meghan Haukaas
// 2015-Nov-09

#include "BinarySearch.h"

BinarySearch::BinarySearch(double data) {
	data_ = data;
	left_ = nullptr;
	right_ = nullptr;
	current_ = this;
}

void BinarySearch::addNode(double data) {
	BinarySearch* newNode = new BinarySearch(data);
	if(left_ == nullptr || right_ == nullptr) {
		if(newNode->data_ > data_) {
			right_ = newNode;
		}
		else {
			left_ = newNode;
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
			data_ -= object;
			moveNode();
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
			if(left_ == nullptr) {
				data_ -= object;
				moveNode();
			}
			else {
				(*left_).insert(object);
			}
		}
	}
}

void BinarySearch::moveNode() {
	if(left_ != nullptr && right_ != nullptr) {
		if(left_->data_ > data_) {
			BinarySearch* temp = left_;
			left_ = current_;
			current_ = temp;
			moveNode();
		}
	}
	else {
		if(left_ != nullptr && right_ != nullptr) {
			if(right_->data_ < data_) {
				BinarySearch* temp = right_;
				right_ = current_;
				current_ = temp;
				moveNode();
			}
		}
	}
}

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