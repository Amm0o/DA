// THis is a file that has Linked List implementation.

#include <iostream>
#include <string>
#include <list>

int main() {

    std::list<int> l;

    for (int i = 0; i < 10; i++) {
        l.push_back(i);
    }

// iterate over the list
for (auto i = l.begin(); i != l.end(); i++) {
    std::cout << *i << std::endl;
}

// for (auto i = l.end(); i != l.begin(); i--){
//     std::cout << *i << std::endl;
// }

// print the list in reverse order
for (auto i = l.rbegin(); i != l.rend(); i++) {
    std::cout << *i << std::endl;
}


    return 0;
}