// Way to find a value within a list.
// Sequential each element in the list and compare it with the value.
// Time complexity: O(n)

#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    

    int value = 3;
    
    for (int i = 0; i < v.size(); i++) { // O(n)
        if(v[i] == value) {
            std::cout << "Found at index: " << i << std::endl;
            break;
        }
    }
    return 0;
}