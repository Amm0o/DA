// Linear data structures 
// Theres no random action operation mainly use (push; pop)
// We would use this to control operations that expected (push; pop)

// Stacks:
// --> Push,Pop,Peek O(1)
// --> Lookup O(n)
// LIFO --> Last in First Out
// Usefull: 
// --> Need to know last item added;
// --> Browser history (go back and forward);
// --> ctrl + z or ctrl + y
// When function follow lifo(Last in First Out)
// --------------------------------------------

// Queues:
// FIFO --> First in First Out
// --> Push,Pop,Peek O(1)
// --> Lookup O(n)
// Usefull:
// --> Tickets website, first person in queue gets to be the firt to buy


// Stack implementation

#include "stack.h"
#include <iostream>

int main() {

    StackImp stack;

    // Fill the stack
    for (int i = 0; i < 10; i++) {
        stack.push(i);
    }


    // print the stack
    for (int i = 0; i < 10; i++) {
        std::cout << stack.top() << std::endl;
        stack.pop();
    }



    return 0;
}