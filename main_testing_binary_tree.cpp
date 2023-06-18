/*	main_binary_tree	*/

#include <iostream>
#include "binary_node.h"
#include "binary_node_tree.h"
#include "binary_tree_interface.h"

int main() {
    BinaryNodeTree<int> tree;

    // Testing add() function
    tree.add(5);
    tree.add(3);
    tree.add(8);
    tree.add(2);
    tree.add(4);
    tree.add(7);
    tree.add(9);

    // Testing isEmpty() function
    std::cout << "Is tree empty? " << (tree.isEmpty() ? "Yes" : "No") << std::endl;

    // Testing getHeight() function
    std::cout << "Height of the tree: " << tree.getHeight() << std::endl;

    // Testing getNumberOfNodes() function
    std::cout << "Number of nodes in the tree: " << tree.getNumberOfNodes() << std::endl;

    // Testing getRootData() function
    std::cout << "Root data: " << tree.getRootData() << std::endl;

	// Testing remove() function
	tree.remove(2);
	tree.remove(3);

    // Testing preorder() function
    std::cout << "Preorder traversal: ";
    tree.preorder(tree.getRootPtr());
    std::cout << std::endl;

    // Testing inorder() function
    std::cout << "Inorder traversal: ";
    tree.inorder(tree.getRootPtr());
    std::cout << std::endl;

    // Testing postorder() function
    std::cout << "Postorder traversal: ";
    tree.postorder(tree.getRootPtr());
    std::cout << std::endl;

    // Testing setRootData() function
    tree.setRootData(10);
    std::cout << "New root data: " << tree.getRootData() << std::endl;

    // Testing clear() function
    tree.clear();
    std::cout << "Is tree empty after clear? " << (tree.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}



