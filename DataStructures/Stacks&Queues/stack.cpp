#include <vector>
#include <./stack.h>


void StackImp::pop() {
    elements.pop_back();
}

int StackImp::top() {
    return elements.back();
}

void StackImp::push(int element) {
    elements.push_back(element);
}
