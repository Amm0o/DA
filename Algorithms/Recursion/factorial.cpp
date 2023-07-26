#include <iostream>

int factorial (int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1); 
}

int factorial2 (int n) {
    if (n == 0) return 1;

    for (int i = n - 1; i > 0; i--) {
        n *= i;
    }

    return n;
}

int main () {
    
    std::cout << "The factorial of 5 is(recursive): " << factorial(5) << std::endl;
    std::cout << "The factorial of 5 is(forl loop): " << factorial2(5) << std::endl;
    return 0;
}