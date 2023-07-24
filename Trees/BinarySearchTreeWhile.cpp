 // include output stream
#include <iostream>

// Create node
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

// Class for binary search tree

class BinarySearchTree {
    public:
        Node* root;
        BinarySearchTree() {
            this->root = nullptr;
        }

    // Insert Method
    void insert(Node* node, int value) {
        // If root is empty
        if (this->root == nullptr) {
            this->root = new Node(value);
            return;
        }
        else {
            Node* currentNode = this->root;
            while(true) {
                // Insert to left
                if (value < currentNode->value) {
                    if (currentNode->left == nullptr) {
                        currentNode->left = new Node(value);
                        return;
                    }
                    currentNode = currentNode->left;
                } else {
                    // Insert to right                  
                        if (currentNode->right == nullptr) {
                            currentNode->right = new Node(value);
                            return;
                        }
                        currentNode = currentNode->right;

                }
            }
        }
    }

    // Lookup Method
    int lookup(Node* node, int value) {

        Node* currentNode = this->root;

        while (currentNode != nullptr) {
            if (currentNode->value == value) {
                return currentNode->value;
            } else if (value < currentNode->value) {
                currentNode = currentNode->left;
            } else {
                currentNode = currentNode->right;
            }

        }

        return -1;
    }

    // Remove Method
    bool remove(Node*& node, int value) {
        if (node == nullptr) {
            return false;      
        } else if (value < node->value) {
            return remove(node->left, value);
        } else if (value > node->value) {
            return remove(node->right, value);
        } else { // Node to be deleted is found
            // Case 1: Node to be deleted has no children 
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                node = nullptr;
            }
            // Case 2: Node to be deleted has one child 
            else if (node->left == nullptr) {
                Node* temp = node;
                node = node->right;
                delete temp;
            } else if (node->right == nullptr) {
                Node* temp = node;
                node = node->left;
                delete temp;
            }
            // Case 3: Node to be deleted has two children 
            else {
                Node* temp = getMinimumValueNode(node->right);
                node->value = temp->value;
                return remove(node->right, temp->value);
            }
            return true;
        }
    }

    Node* getMinimumValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }


};

// Traverse function
void traverse(Node* node) {
    if (node == nullptr) {
        return;
    }
    std::cout << node->value << std::endl;
    traverse(node->left);
    traverse(node->right);

}

int main() {


    BinarySearchTree* tree = new BinarySearchTree();

    int arr[] = {9,4,6,20,170,15,1};

    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
        tree->insert(tree->root,arr[i]);
    }


    traverse(tree->root);

    std::cout << "Found number 9: " << tree->lookup(tree->root,4) << std::endl;

    tree->remove(tree->root, 170);
    tree->remove(tree->root, 15);
    tree->remove(tree->root, 1);
    tree->remove(tree->root, 9);

    std::cout << "After removals" << std::endl;

    traverse(tree->root);
    return 0;
}
