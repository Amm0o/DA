#include <iostream>
#include <unordered_map>

// Formula used F(n) = F(n-1) + F(n-2)
int calclFib(int n) { // Curently with this method the time complecity is --> 2^n REALLY BAD 
    if (n < 2) {
        return n;
    }
    return calclFib(n-1) + calclFib(n-2);
}

int calclFibGood(int n) { // O(n)
    static std::unordered_map<int,int> cache;
    if (cache.find(n) != cache.end()) {
        std::cout << "Cached: ";
        return cache[n];
    } else {
        if (n<2) {
            return n;
        } else {
            cache[n] = calclFib(n-1) + calclFib(n-2);
            std::cout << "Calculated: ";
            return cache[n];
        }
    }
}

int main() {
    

    std::cout << calclFibGood(7) << std::endl;
    std::cout << calclFibGood(7) << std::endl;;
    std::cout << calclFibGood(10) << std::endl;;
    std::cout << calclFibGood(10) << std::endl;;
    return 0;
}