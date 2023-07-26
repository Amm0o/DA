#include <iostream>

class BinaryTree {
    public:
        int value;
        BinaryTree* left;
        BinaryTree* right;

    BinaryTree(int value) {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

int main() {

    BinaryTree* root = new BinaryTree(1);
    root->left = new BinaryTree(2);
    root->right = new BinaryTree(3);
    root->left->left = new BinaryTree(4);
    root->left->right = new BinaryTree(5);
    root->right->left = new BinaryTree(6);
    root->right->right = new BinaryTree(7);

    // Now you have a binary tree with the following structure: which is a perfect binary tree
    //       1
    //      / \
    //     2   3
    //    / \ / \
    //   4  5 6  7

    // This would be a full binary tree
    //       1
    //      / \
    //     2   3
    //    / \ / \
    //   4  5 6  7
    //  / \
    // 8   9

    // When a tree is perfect the summ of all the leaves on the same level will be =
    // the summ of the nodes beofre that level + 1
    // Example = 4 + 5 + 6 + 7 = 4 and the summ of all the nodes above is 2 + 3 + 1 + 1(VALUE ADDED) = 4
 
    // This means that half of the nodes are on the bottom level and the other half are on the top level
    // This means the summ of the bottom level is one less than the summ of the top level


    // Binary Tree notation: O(logN) -> Lookup, insert, delete
    

    // How to calculate the number of nodes in each level 2^level = level 0 = 2^0 = 1, 
    // level 1 = 2^1 = 2, level 2 = 2^2 = 4; etc...

    // Total number of nodes = 2^h(height) - 1 -> -1 due to the root node
    // log of nodes = height
    // log 100 = 2 -> 10^2 = 100
    
    return 0;
}