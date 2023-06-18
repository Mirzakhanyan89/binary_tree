/* binary_tree_interface.h	*/

#ifndef _BINARY_TREE_INTERFACE
#define _BINARY_TREE_INTERFACE

template <typename ItemType>
class BinaryTreeInterface
{
public:
/** Tests whether this binary tree is empty.
@return True if the binary tree is empty, or false if not. */
virtual bool isEmpty() const = 0;
/** Gets the height of this binary tree.
@return The height of the binary tree. */
virtual int getHeight() const = 0;
/** Gets the number of nodes in this binary tree.
@return The number of nodes in the binary tree. */
virtual int getNumberOfNodes() const = 0;
/** Gets the data that is in the root of this binary tree.
@pre The binary tree is not empty.
@post The root’s data has been returned, and the binary tree is unchanged.
@return The data in the root of the binary tree. */
virtual ItemType getRootData() const = 0; 
/** Replaces the data item in the root of this binary tree
with the given data, if the tree is not empty. However, if (continues)
Using ADT binary tree operations to build a binary tree
the tree is empty, inserts a new root node containing the
given data into the tree.
@post The data in the root of the binary tree is as given.
@param newData The data for the root. */
virtual void setRootData(const ItemType& newData) = 0;
/** Adds a new node containing the given data to this binary tree.
@param newData The data for the new node. 
@post The binary tree contains a new node.
@return True if the addition is successful, or false not. */
virtual bool add(const ItemType& newData) = 0;
/** Removes the node containing the given data item from this binary tree.
@param data The data value to remove from the binary tree. 
@return True if the removal is successful, or false not. */
virtual bool remove(const ItemType& data) = 0;
/** Removes all nodes from this binary tree. */
virtual void clear() = 0;
};


#endif  // _BINARY_TREE_INTERFACE

