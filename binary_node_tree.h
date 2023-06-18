/*	binary_node_tree.h	
	ADT binary tree: Link-based implementation.*/

#ifndef _BINARY_NODE_TREE
#define _BINARY_NODE_TREE

#include "binary_tree_interface.h"
#include "binary_node.h"

template <typename ItemType>
class BinaryNodeTree : public BinaryTreeInterface<ItemType> {
private:
	BinaryNode<ItemType>* rootPtr;
protected:
	bool addHelper(BinaryNode<ItemType>* newNode, BinaryNode<ItemType>* subTreePtr); 
	int getHeightHelper(BinaryNode<ItemType>* subTreePtr) const;
	int getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const;
	void destroyTree(BinaryNode<ItemType>*& subTreePtr);
	BinaryNode<ItemType>* removeHelper(BinaryNode<ItemType>* nodePtr, const ItemType& data, bool& success); 
	BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* treePtr,
			const ItemType& target, bool& success) const;
	BinaryNode<ItemType>* copyTree(const BinaryNode<ItemType>* treePtr) const;
public:
	BinaryNode<ItemType>* getRootPtr() const;
	void preorder(BinaryNode<ItemType>* treePtr) const;
	void inorder(BinaryNode<ItemType>* treePtr) const;
	void postorder(BinaryNode<ItemType>* treePtr) const;
	BinaryNodeTree();
	BinaryNodeTree(const ItemType& rootItem);
	BinaryNodeTree(const ItemType& rootItem,
			const BinaryNodeTree<ItemType>* leftTreePtr,
			const BinaryNodeTree<ItemType>* rightTreePtr);
	BinaryNodeTree(const BinaryNodeTree<ItemType>& tree);
	virtual ~BinaryNodeTree();

//	Public BinaryTreeInterface Methods Section.
	bool isEmpty() const;
	int getHeight() const;
	int getNumberOfNodes() const;
	ItemType getRootData() const;
	void setRootData(const ItemType& newData);
	bool add(const ItemType& newData); // Adds a node
	bool remove(const ItemType& data); // Removes a node
	void clear();
}; // end BinaryNodeTree

#include "binary_node_tree.hpp"
#endif	// _BINARY_NODE_TREE



