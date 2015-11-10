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
	if (isLeaf()) {
		if (newNode->data_ > data_) {
			right_ = newNode;
		}
		else {
			left_ = newNode;
		}
	}
	else if (newNode->data_ > data_) {
		(*right_).addNode(data);
	}
	else {
		(*left_).addNode(data);
	}
}

void BinarySearch::insert(double object)
{ 
	if (object == data_) {
		data_ -= object;
		moveNode();
	}
	else if (object > data_) {
		if (right_ == nullptr) {
			addNode(1.0 - object);
		}
		else{
			(*right_).insert(object);
		}
	}
	else {
		if (left_ == nullptr) {
				data_ -= object;
				moveNode();
			}
			else {
				(*left_).insert(object);
			}
	}
}

void BinarySearch::moveNode() {
	if(!isLeaf()) {
		if(left_->data_ > data_) {
			BinarySearch* temp = left_;
			left_ = current_;
			current_ = temp;
			moveNode();
		}
	}
	else {
		if(!isLeaf()) {
			if(right_->data_ < data_) {
				BinarySearch* temp = right_;
				right_ = current_;
				current_ = temp;
				moveNode();
			}
		}
	}
}

bool BinarySearch::isLeaf() const{
	if (left_ == nullptr && right_ == nullptr) {
		return true;
	}
	return false;
}

void BinarySearch::printAll() const{
	cout << data_ << " ";
	if (left_ != nullptr) {
		(*left_).printAll();
	}
	if (right_ != nullptr) {
		(*right_).printAll();
	}
}

void BinarySearch::printBins() const{
	if(isLeaf()) cout << data_ << " ";
	if(left_ != nullptr) {
		(*left_).printBins();
	}
	if(right_ != nullptr) {
		(*right_).printBins();
	}
}