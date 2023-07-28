// Breadth First Search
// Start at the root node
// Go left to to right at each level
// Uses more memory to track each node in each level
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



// How to implement:
// #1 Start from the root Node;
// #2 Go to the left
// #3 Visit all the nodes on that level.

// It uses a lot of memory because every node it visits it grabs a reference for thei leafs so we can then go to them.
// Use a queue to store the nodes to visit

#include <iostream>
#include <vector>
#include <queue>


class Node {
    public:
        int value;
        Node* left;
        Node* right;
    
    // Constructor
    Node(int value) {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }

};


class BinarySearchTree {
    public:
        Node* root;
        BinarySearchTree (){
            this->root=nullptr;
        }

        void insert(Node* node, int value) {
            // if root is empty
            if (this->root == nullptr) {
                this->root = new Node(value);
                return;
            }

            // Insert on the left
            if(value < node->value) {
                if (node->left == nullptr) {
                    node->left = new Node(value);
                    return;
                }
                return insert(node->left,value);
            }
            // Insert on the right
            if(value > node->value) {
                if(node->right == nullptr ) {
                    node->right = new Node(value);
                    return;
                }
                return insert(node->right, value);

            }
        }

        bool lookup(Node* node, int value) {
            if (node == nullptr) {
                return false;
            }

            if (value > node->value) {
                return lookup(node->right, value);
            } else if (value < node->value) {
                return lookup(node->left,value);
            } else {
                return true;
            }
        }

        std::vector<int> breadthFirstSearch(Node* node) {
            std::vector<int> list;
            std::queue<Node*> queue;

            if (node != nullptr) {
                queue.push(node);
            }

            while (!queue.empty()) {
                Node* currentNode = queue.front();
                queue.pop();
                list.push_back(currentNode->value);

                if (currentNode->left != nullptr) {
                    queue.push(currentNode->left);
                }

                if (currentNode->right != nullptr) {
                    queue.push(currentNode->right);
                }
            }
            return list;
        }


        std::vector<int> breadthFirstSearchRecursive(std::queue<Node*> queue, std::vector<int> list) {
            // Base case: the queue is empty
            if (queue.empty()) {
                return list;
            }

            // Get the next node from the queue
            Node* currentNode = queue.front();
            queue.pop();
            list.push_back(currentNode->value);

            // Add the left and right child nodes to the queue, if they exist
            if (currentNode->left != nullptr) {
                queue.push(currentNode->left);
            }
            if (currentNode->right != nullptr) {
                queue.push(currentNode->right);
            }

            // Recursively call the function with the updated queue and list
            return breadthFirstSearchRecursive(queue, list);
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




    std::vector<int> result = tree->breadthFirstSearch(tree->root);

    for (auto& n : result) {
        std::cout << n << "->";
    } 


    std::cout << std::endl << "Recursive call: " << std::endl;
    
    std::queue<Node*> queue;
    queue.push(tree->root);
    std::vector<int> list;
    std::vector<int> result2 = tree->breadthFirstSearchRecursive(queue, list);

    // Print the result
    for (auto& n : result2) {
        std::cout << n << "->";
    }
    std::cout << std::endl;
    return 0;
}