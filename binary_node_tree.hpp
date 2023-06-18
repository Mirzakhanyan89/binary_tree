/*	binary_node_tree.hpp	
	ADT binary tree: Link-based implementation.*/

#include <algorithm>
#include "binary_tree_interface.h"
#include "binary_node.h"


template <typename ItemType>
bool BinaryNodeTree<ItemType>::addHelper(BinaryNode<ItemType>* newNode, BinaryNode<ItemType>* subTreePtr) {
	bool flag;
	if (!subTreePtr) {
		return false;
		}
	else if (!subTreePtr-> getLeftChildPtr()) {
		subTreePtr-> setLeftChildPtr(newNode);
		return true;
		}
	else if (!subTreePtr-> getRightChildPtr()) {
		subTreePtr-> setRightChildPtr(newNode);
		return true;
		} else {
			flag = addHelper(newNode, subTreePtr-> getLeftChildPtr());
			if (!flag) {
				flag = addHelper(newNode, subTreePtr-> getRightChildPtr());
				}
			}
	return flag;
}

template <typename ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::removeHelper(BinaryNode<ItemType>* nodePtr, const ItemType& data, bool& success) {
    if (nodePtr == nullptr) {
        success = false;
        return nullptr;
    }

    if (data < nodePtr->getItem()) {
        BinaryNode<ItemType>* newLeft = removeHelper(nodePtr->getLeftChildPtr(), data, success);
        nodePtr->setLeftChildPtr(newLeft);
        return nodePtr;
    } else if (data > nodePtr->getItem()) {
        BinaryNode<ItemType>* newRight = removeHelper(nodePtr->getRightChildPtr(), data, success);
        nodePtr->setRightChildPtr(newRight);
        return nodePtr;
    } else {
        // Node to be removed found
        success = true;

        // Case 1: Node has no children
        if (nodePtr->isLeaf()) {
            delete nodePtr;
            nodePtr = nullptr;
            return nullptr;
        }

        // Case 2: Node has one child
        if (nodePtr->getLeftChildPtr() == nullptr) {
            BinaryNode<ItemType>* temp = nodePtr->getRightChildPtr();
            delete nodePtr;
            nodePtr = nullptr;
            return temp;
        } else if (nodePtr->getRightChildPtr() == nullptr) {
            BinaryNode<ItemType>* temp = nodePtr->getLeftChildPtr();
            delete nodePtr;
            nodePtr = nullptr;
            return temp;
        }

        // Case 3: Node has two children
        BinaryNode<ItemType>* inorderSuccessor = nodePtr->getRightChildPtr();
        while (inorderSuccessor->getLeftChildPtr() != nullptr) {
            inorderSuccessor = inorderSuccessor->getLeftChildPtr();
        }
        nodePtr->setItem(inorderSuccessor->getItem());
        BinaryNode<ItemType>* newRight = removeHelper(nodePtr->getRightChildPtr(), inorderSuccessor->getItem(), success);
        nodePtr->setRightChildPtr(newRight);
        return nodePtr;
    }
}

template <typename ItemType>
int BinaryNodeTree<ItemType>::getHeightHelper(BinaryNode<ItemType>* subTreePtr) const {
	if (!subTreePtr) {
		return 0;
	} 
	int leftHeight = getHeightHelper(subTreePtr-> getLeftChildPtr());
	int rightHeight = getHeightHelper(subTreePtr-> getRightChildPtr());
	return 1 + std::max(leftHeight, rightHeight);
}

template <typename ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const {
	if (!subTreePtr) {
		return 0;
		}
	int leftNode = getNumberOfNodesHelper(subTreePtr-> getLeftChildPtr());
	int rightNode = getNumberOfNodesHelper(subTreePtr-> getRightChildPtr());
	return 1 + leftNode + rightNode;
}


// Recursively deletes all nodes from the tree.
template <typename ItemType>
void BinaryNodeTree<ItemType>::destroyTree(BinaryNode<ItemType>*& treePtr) {
    if (treePtr != nullptr) {
        // Recursively destroy the left and right subtrees
        BinaryNode<ItemType>* newLeft = treePtr->getLeftChildPtr();
        destroyTree(newLeft);
        BinaryNode<ItemType>* newRight = treePtr->getRightChildPtr();
        destroyTree(newRight);
        // Delete the current node
        delete treePtr;
        treePtr = nullptr;
    }
}

template <typename ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::findNode(BinaryNode<ItemType>* treePtr,
			const ItemType& target, bool& success) const {
	if (!treePtr) {
		success = false;
		return nullptr;
		}
	if (treePtr-> getItem() == target) {
		success = true;
		return treePtr;
		} else {
			BinaryNode<ItemType>* newNode = findNode(treePtr-> getLeftChildPtr(), target, success);
			if (!success) {
				newNode = findNode(treePtr-> getRightChildPtr(), target, success);
				}
			return newNode;
		}
	return treePtr;
}

template <typename ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::copyTree(const BinaryNode<ItemType>* treePtr) const {
	BinaryNode<ItemType>* newTreePtr = nullptr;
    // Perform a preorder traversal to copy each node
    if (treePtr != nullptr)
    {	// Copy the current node
        newTreePtr = new BinaryNode<ItemType>(treePtr->getItem(), nullptr, nullptr);
        // Copy the left and right subtrees recursively
        newTreePtr->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
        newTreePtr->setRightChildPtr(copyTree(treePtr->getRightChildPtr()));
    }
    return newTreePtr;
}

template <typename ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::getRootPtr() const {
	return rootPtr;
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::preorder(BinaryNode<ItemType>* treePtr) const {
	if (!treePtr) {
		return;
		}
	std::cout<< treePtr-> getItem() << ' ';
	preorder(treePtr-> getLeftChildPtr());
	preorder(treePtr-> getRightChildPtr());
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::inorder(BinaryNode<ItemType>* treePtr) const {
	if (!treePtr) {
		return;
		}
	inorder(treePtr-> getLeftChildPtr());
	std::cout<< treePtr-> getItem() << ' ';
	inorder(treePtr-> getLeftChildPtr());
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::postorder(BinaryNode<ItemType>* treePtr) const {
	if (!treePtr) {
		return;
		}
	postorder(treePtr-> getLeftChildPtr());
	postorder(treePtr-> getLeftChildPtr());
	std::cout<< treePtr-> getItem() << ' ';	
}

//public functions
// constructors and destructor

template <typename ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree() : rootPtr{nullptr} { }

template <typename ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem) { 
	rootPtr = new BinaryNode<ItemType> (rootItem, nullptr, nullptr);  
}

template <typename ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem, const BinaryNodeTree<ItemType>* leftTreePtr, 
	const BinaryNodeTree<ItemType>* rightTreePtr) {
	rootPtr = new BinaryNode<ItemType> (rootItem,
		copyTree(leftTreePtr-> rootPtr), copyTree(rightTreePtr-> rootPtr));
}

template <typename ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const BinaryNodeTree<ItemType>& tree) {
    rootPtr = copyTree(tree.rootPtr);
}

template <typename ItemType>
BinaryNodeTree<ItemType>::~BinaryNodeTree() {
    destroyTree(rootPtr);
}
	
template <typename ItemType>
bool BinaryNodeTree<ItemType>::isEmpty() const {
	return rootPtr == nullptr;
}

template <typename ItemType>
int BinaryNodeTree<ItemType>::getHeight() const {
	return getHeightHelper(rootPtr);
}

template <typename ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodes() const {
	return getNumberOfNodesHelper(rootPtr);
}

template <typename ItemType>
ItemType BinaryNodeTree<ItemType>::getRootData() const {
	return rootPtr-> getItem();
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::setRootData(const ItemType& newData) { 
	rootPtr-> setItem(newData);
}

template <typename ItemType>
bool BinaryNodeTree<ItemType>::add(const ItemType& newData) { 
	// Adds a node
	BinaryNode<ItemType>* newNode {new BinaryNode<ItemType> (newData)};
	if ( !rootPtr ) {
		rootPtr = newNode;
		return true;
		} else {
			return addHelper(newNode, rootPtr);
		}
	return true;
}	

template <typename ItemType>
bool BinaryNodeTree<ItemType>::remove(const ItemType& data) {
    bool success = false;
    rootPtr = removeHelper(rootPtr, data, success);
    return success;
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::clear() {
    destroyTree(rootPtr);	
}

