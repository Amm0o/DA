#include <iostream>
#include <unordered_map>



int memoizedOperation (int n) {
    static std::unordered_map<int,int> cache;

    if (cache.find(n) != cache.end()) {
        std::cout << "Cached operation: ";
        return cache[n];
    } else {
        std::cout << "New Operation: ";
        cache[n] = n * 2;
        return cache[n];
    }
}

int main() {


    std::cout << memoizedOperation(5) << std::endl; 
    std::cout << memoizedOperation(5) << std::endl; 
    std::cout << memoizedOperation(5) << std::endl; 
    return 0;
}