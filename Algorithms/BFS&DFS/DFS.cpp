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




class Node {
    public:
        int value;
        Node* left;
        Node* right;

        Node(int value){
            this->value = value;
            this->right = nullptr;
            this->left = nullptr
        }
};


class BinarySearchTree {
    public:
        Node* root;
        BinarySearchTree() {
            this->root = nullptr;
        }

        void insert(Node* node, int value) {
            if (this->root == nullptr) {
                this->root = new Node(value);
                return;
            } else if (value < node->value) {
                if (node->left == nullptr) {
                    node->left = new Node(value);
                    return;
                }
                return insert(node->left, value);
            } else if (value > node->value) {
                if (node->right == nullptr) {
                    nnode->right = new Node(value);
                    return;
                }
                return insert(node->right, value);
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
};