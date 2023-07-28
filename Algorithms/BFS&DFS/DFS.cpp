// The Searches follows a branch of the Tree until down until it finds the value or has no where else to go
// Then we go back a and go to the next node that has no been explored and goes down through that node's leafs 
// O(n)

// BFS vs DFS:
// Both are traversals
// BFS and DFS time complexity is the same O(n)
//  
// BFS:
// Very good to find the shortest path.
// Closer Nodes
// More memory usage
//
// DFS:
// If we know the node will be lower on the tree (Deeper)
// Less memory use
// It can get slow if the Tree or Graph is really deep
// It also is bad to find the shortest PATH.

// Examples:
// #1 If you know a solution is not far from the root of the tree:
// BFS
// #2 If the tree is very deep and solutions are rare:
// BFS (DFS will take too long)
// #3 If the tree is very wide:
// DFS (BFS will need too much memory)
// #4 If solutions are frequent but located deep in the tree:
// DFS
// #5 Determining whether a path exists between two nodes:
// DFS
// #6 Finding the shortest path:
// BFS

// 3 ways to implement:
// --> Inorder EX:
//          Tree:
//              9
//             / \
//            4   20
//           / \  / \
//          1   6 15  170
//          Inorder: [1,4,6,9,15,20,170]
// --> PostOrder:
//          Tree:
//              9
//             / \
//            4   20
//           / \  / \
//          1   6 15  170
//          PostOrder: [1,6,4,15,170,20,9]
// --> Preorder (Usefull to recreate a tree):
//          Tree:
//              9
//             / \
//            4   20
//           / \  / \
//          1   6 15  170
//          Preorder: [9,4,1,6,20,15,170]
//
// Memory usage is the height of the tree O(h)

#include <iostream>
#include <vector>
#include <queue>

class Node {
    public:
        int value;
        Node* left;
        Node* right;

        Node(int value){
            this->value = value;
            this->right = nullptr;
            this->left = nullptr;
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

        bool lookup (Node* node, int value) {
            if (this->root == nullptr) {
                return false;
            } 

            if (node->value == value) {
                return true;
            } else if(value < node->value) {
                return lookup(node->left, value);
            } else {
                return lookup(node->right, value);
            }

            return false;
        }


        std::vector<int> traverseInOrder(Node* node, std::vector<int>& list) {
            if (node != nullptr) {
                if (node->left != nullptr) {
                    traverseInOrder(node->left, list);
                }
                list.push_back(node->value);
                if (node->right != nullptr) {
                    traverseInOrder(node->right, list);
                }
            }

            return list;
        }

        std::vector<int> traversePreOrder(Node* node, std::vector<int>& list) {
            if (node != nullptr) {
                // Push each node from the root downwards.
                list.push_back(node->value);
                if (node->left != nullptr) {
                    traversePreOrder(node->left, list);
                }
                if (node->right != nullptr) {
                    traversePreOrder(node->right, list);
                }
            }

            return list;
        }

        std::vector<int> traversePostOrder(Node* node, std::vector<int>& list) {
            if (node != nullptr) {
                // Push each node from the root downwards.
                if (node->left != nullptr) {
                    traversePostOrder(node->left, list);
                }
                if (node->right != nullptr) {
                    traversePostOrder(node->right, list);
                }
                list.push_back(node->value);
            }

            return list;
        }

        // Using recursion
        std::vector<int> DFSInOrder() {
            std::vector<int> list;
            traverseInOrder(this->root, list);
            return list;
        }

        std::vector<int> DFSPreOrder() {
            std::vector<int> list;
            traversePreOrder(this->root, list);
            return list;
        }

        std::vector<int> DFSPostOrder() {
            std::vector<int> list;
            traversePostOrder(this->root, list);
            return list;
        }

};


int main() {
    
    BinarySearchTree* tree = new BinarySearchTree();


    tree->insert(tree->root, 9);
    tree->insert(tree->root, 4);
    tree->insert(tree->root, 6);
    tree->insert(tree->root, 20);
    tree->insert(tree->root, 170);
    tree->insert(tree->root, 15);
    tree->insert(tree->root, 1);


    std::cout << "In order :\n";

    std::vector<int> result = tree->DFSInOrder();
    for (auto& n : result) {
        std::cout << n << "->";
    }

    std::cout << "\nPre order :\n";

    std::vector<int> result2 = tree->DFSPreOrder();
    for (auto& n : result2) {
        std::cout << n << "->";
    }

    std::cout << "\nPost order :\n";

    std::vector<int> result3 = tree->DFSPostOrder();
    for (auto& n : result3) {
        std::cout << n << "->";
    }


    delete tree;
    std::cout << std::endl;
    return 0;
}