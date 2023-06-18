/** binary_node.hpp */

#include "binary_node.h"

template <typename ItemType>
BinaryNode<ItemType>::BinaryNode() : 
	leftChildPtr{nullptr}, rightChildPtr{nullptr} { }

template <typename ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem) :
	item{anItem}, leftChildPtr{nullptr}, rightChildPtr{nullptr} { }

template <typename ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem,
	 BinaryNode<ItemType>* l, BinaryNode<ItemType>* r) :
	 item{anItem}, leftChildPtr{l}, rightChildPtr{r} { }

template <typename ItemType>
void BinaryNode<ItemType>::setItem(const ItemType& anItem) {
	item = anItem;
}

template <typename ItemType>
ItemType BinaryNode<ItemType>::getItem() const {
	 return item;
}

template <typename ItemType>
bool BinaryNode<ItemType>::isLeaf() const {
	return (rightChildPtr == nullptr) and (leftChildPtr == nullptr);
}

template <typename ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getLeftChildPtr() const {
	return leftChildPtr;
}

template <typename ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getRightChildPtr() const {
	return rightChildPtr;
}

template <typename ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(BinaryNode<ItemType>* l) {
	leftChildPtr = l;
}

template <typename ItemType>
void BinaryNode<ItemType>::setRightChildPtr(BinaryNode<ItemType>* r) {
	rightChildPtr = r;
}



