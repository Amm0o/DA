// Description: Implementation of graph algorithms
// How can we implement Graphs?
// 1. Edge List -> An array that contains multiple arrays that contain the edges EX: 
//              -> int edges[4][2] = {{0,2},{2,3},{2,1},{1,3}};
//              -> This is a directed graph that has 4 edges
//              -> Each pair value represents the connections between the nodes
// -------------------------------
// 2. Adjacency List -> An array where each index represents a node and the value at that index 
//                   -> is a list of all the nodes that node is connected to EX:
//                   -> vector<vector<int>> adj = {{2}, {2,3}, {0,1,3}, {1,2}};
// -------------------------------
// 3. Adjacency Matrix -> A 2D array of size VxV where V is the number of vertices
//                     -> If adj[i][j] = w, then there is an edge from vertex i to vertex j with weight w EX:
//                     -> int adj[4][4] = {{0,0,1,0}, {0,0,1,1}, {1,1,0,1}, {0,1,1,0}};
//                     -> This means {0,0,1,0} = 0 has a connection with 2:  0 -> 2
// NOTE: All of the above examples represent the same graph.


// Use flag -std=c++14 to compile

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>


class Graph {
    public:
        int numberOfNodes;
        std::unordered_map<std::string, std::vector<std::string> > adjacentList;
        
        Graph() {
            this->numberOfNodes = 0;
        }

        void addVertex(std::string node) {
            // check if Vertex already exists
            if (this->adjacentList.find(node) == this->adjacentList.end()) {
                this->adjacentList[node] = std::vector<std::string>();
                this->numberOfNodes++;
            } else {
                std::cout << "Node: " << node << " already exists in the graph\n" << std::endl;  
            }

        }

        void addEdge(std::string node, std::vector<std::string> nodes) {
            // check if the Vertex exist
            if (this->adjacentList.find(node) == this->adjacentList.end()) {
                std::cout << "Vertex: " << node << " does not exist in the graph\n";
            } else {
                for (std::string n : nodes) {
                    if (this->adjacentList.find(n) == this->adjacentList.end()) {
                        std::cout << "Vertex: " << n << " does not exist in the graph, please use method addVertex to create it\n";
                    } else {
                        for (std::string n : nodes ) {
                            if (std::find(this->adjacentList[node].begin(), this->adjacentList[node].end(), n) == this->adjacentList[node].end()) {
                                this->adjacentList[node].push_back(n);
                                this->adjacentList[n].push_back(node);
                            } else {
                                std::cout << "Edge: " << node << " -> " << n << " already exists in the graph\n";
                            }
                        }
                    }
                }
            }
        }

        void showConnections() {
            for (auto node : this->adjacentList) {
                std::string vertex = node.first;
                std::vector<std::string> edges = node.second;
                std::cout << vertex << "-->";
                for (std::string edge : edges) {
                    std::cout << edge << " ";
                }
                std::cout << "\n";
            }
        }


};




int main () {



    // Create a pointer to a Graph object
    Graph* myGraph = new Graph();

    // Declare all vertices

    myGraph->addVertex("0");
    myGraph->addVertex("1");
    myGraph->addVertex("2");
    myGraph->addVertex("3");
    myGraph->addVertex("4");
    myGraph->addVertex("5");
    myGraph->addVertex("6");


    std::cout << "All vertices have been added to the graph\n";


    // Create all edges
    std::vector<std::string> edgeList;

    edgeList.push_back("1");
    edgeList.push_back("4");
    myGraph->addEdge("3", edgeList);
    edgeList.clear();  // Clear the vector for the next set of edges

    edgeList.push_back("3");
    edgeList.push_back("2");
    edgeList.push_back("5");
    myGraph->addEdge("4", edgeList);
    edgeList.clear();

    edgeList.push_back("2");
    edgeList.push_back("0");
    myGraph->addEdge("1", edgeList);
    edgeList.clear();

    edgeList.push_back("1");
    edgeList.push_back("2");
    myGraph->addEdge("0", edgeList);
    edgeList.clear();

    edgeList.push_back("5");
    myGraph->addEdge("6", edgeList);
    edgeList.clear();

    // Show all relationships
    myGraph->showConnections();
    
    delete myGraph;
    return 0;
}