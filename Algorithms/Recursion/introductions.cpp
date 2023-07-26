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

// -------------------------------------------------------
// Anything that can be implemented recursively can be done using loops
//
// So why would we use recursion?
// --> Easier to write for some problems
// --> Help implement DRY --> DO NOT REPEATE YOUR SELF
// --> Usually recursion can be good when we don't know how many loops we will need
//    --> Good with Trees
// 
// Draw Back:
// High memory utilization due to stack overflow. 
//
// NOTE: Tail Call Optimization can eliminate the issue of the call stack increasing:
// Tail call optimization (TCO) is a compiler optimization that eliminates the 
// need for additional stack frames when a function call is the last operation in another function.
//
// In c++ it is not present by default on the compiler but we are able through configuration to add it when compiling using 
// for instance GCC


// ---------------------- When To Use? ----------------------
// -->  BFS + DFS
// -->  Some sort of soring algorithms
// -->  Every time we are using Trees consider recursion
// -->  Divide and conquer using Recursion
// RULES:
// 1. When a problem can be devided in subproblems that are instances of the initial problem
// 2. Each instance of the subproblem is identical
// 3. The solution to each subproblem can be combined to reach the solution


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