// Not really an algorithm but very important to understand recursion.
// Use cases:
// 1. Look through folders recursively. --> Ls -R (R for recursive)
// Recursion is when a function calls itself.
// Recursion is very good when we have a task that has repeated subtasks.
// Caviat: Recursion can cause a stack overflow and crash the program. 
// This is dues to the fact that each function call takes up space on the stack.
// Address   | Function           | Local Variables | Return Address
// -------------------------------------------------------------------
// 0x00007FF | recursiveFunction  | counter=2       | 0x00001AA
// 0x00005CC | recursiveFunction  | counter=1       | 0x00001AA
// 0x00003BB | recursiveFunction  | counter=0       | 0x00001AA
// 0x00001AA | main               | ...             | ...
// ...       | ...                | ...             | ...


// ---------------------- Recursion ----------------------
// Eeach recursive function has to have a base case and a recursive case.


#include <iostream>

int recursion (int i) {
    if (i < 0 ) return i;
    std::cout << i << std::endl;
    return recursion(i - 1);
}

int main() {
    
    recursion(5);
    return 0;
}