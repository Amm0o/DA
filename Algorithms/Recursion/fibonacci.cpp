#include <iostream>
#include <vector>


// Formula used F(n) = F(n-1) + F(n-2)
int fibonacci(int n) { // Exponential time O(2^n) --> Awfull time performance and space due to stack 
                       // This can be improved by using memoization and dynamic programming and it would become O(n)
    if (n < 2) return n;
    
    return fibonacci(n-1) + fibonacci(n-2); 
}

int fibonacciIt(int n) { // O(n)
    std::vector<int> vec;
    vec.push_back(0);
    vec.push_back(1);

    for (int i = 2; i < n + 1; i++) {
        vec.push_back(vec[i-1] + vec[i-2]);
    }

    return vec[n];




}


int main() {

    std::cout << "Fib recrusive index 5: " << fibonacci(40) << std::endl;
    std::cout << "Fib iterative index 5: " << fibonacciIt(8) << std::endl;
    return 0;
}