// Binary Search Tree (BST)
// A binary search tree is a binary tree where the nodes are ordered in a specific way.
// BST preserves relationships between nodes.
// Rules:
// 1. All values on the left of the root node must be less than the root node
// 2. All values on the right of the root node must be greater than the root node
// BST is O(log N) -> Lookup, Insert, Delete
// Look Up > Iterate --> Look up does not gor through the entire data set.
// Insert and Delete --> Figure out where to delete or insert  
// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Balanced vs Unbalanced BST
// Unbalanced BST O(n) -> Lookup, Insert, Delete
// Example of unbalanced BST:
//       1
//      / \
//     2   3
//    / 
//   4 
//  /
// 8
//
// There are ways to balance a BST --> AVL Tree, Red Black Tree, etc... (Advanced)
// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// BST Pros and Cons:
// Pros:
// 1. Better than O(n)
// 2. Ordered
// 3. Flexible Size
// Cons:
// 1. No O(1) operations --> We always have to traverse the tree


// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// BTS Implementation

#include <iostream>

class Node {
    public:
        int value;
        Node* left;
        Node* right;
    
    Node(int value) {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};



class BinarySearchTree {
    public:
        Node* root;
        BinarySearchTree() {
            this->root = nullptr;
        }

        
        void insert(Node* node, int value) {

            // If root is empty
            if(this->root == nullptr) {
                this->root = new Node(value);
                return;
            }
            // Insert to the left
            if (value < node->value) {
                if (node->left == nullptr) {
                    node->left = new Node(value);
                    return;
                }
                insert(node->left,value);
            }

            // Insert to the right
            if (value > node->value) {
                if (node->right == nullptr) {
                    node->right = new Node(value);
                    return;
                }
                insert(node->right,value);

            }
        }

        // Lookup method

        bool lookup(Node* node, int value) {
            if (node == nullptr) {
                return false;
            }
            if (value < node->value) {
                return lookup(node->left,value);
            } else if (value > node ->value) {
                return lookup(node->right, value);
            } else {
                return true;
            }
        }
};

// Traverse function
void traverse(Node* node){
    if (node == nullptr) {
        return;
    }
    std::cout << node->value << std::endl;
    traverse(node->left);
    traverse(node->right);
}


int main () {

    int arr[] = {9,4,6,20,170,15,1};

    BinarySearchTree* tree = new BinarySearchTree();

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        tree->insert(tree->root, arr[i]);
    }

    traverse(tree->root);

    std::cout << tree->lookup(tree->root, 44) << std::endl;
    std::cout << tree->lookup(tree->root, 20) << std::endl;
    std::cout << tree->lookup(tree->root, 9) << std::endl;

    return 0;
}