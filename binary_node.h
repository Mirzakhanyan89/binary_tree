/** binary_node.h 
	A class of nodes for a link-based binary tree. */

#ifndef _BINARY_NODE
#define _BINARY_NODE

template <typename ItemType>
class BinaryNode
{
private:
	ItemType item;
	// Data portion
	BinaryNode<ItemType>* leftChildPtr; // Pointer to left child
	BinaryNode<ItemType>* rightChildPtr; // Pointer to right child
public:
	BinaryNode();
	BinaryNode(const ItemType& anItem);
	BinaryNode(const ItemType& anItem, 
			BinaryNode<ItemType>* l,
			BinaryNode<ItemType>* r);
	void setItem(const ItemType& anItem);
	ItemType getItem() const;
	bool isLeaf() const;
	BinaryNode<ItemType>* getLeftChildPtr() const;
	BinaryNode<ItemType>* getRightChildPtr() const;
	void setLeftChildPtr(BinaryNode<ItemType>* l);
	void setRightChildPtr(BinaryNode<ItemType>* r);
};

#include "binary_node.hpp"
#endif	 // _BINARY_NODE




