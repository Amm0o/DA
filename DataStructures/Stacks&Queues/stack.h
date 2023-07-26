#ifndef STACKIMP_H
#define STACKIMP_H

#include <vector>
#include <stdexcept>

class StackImp {
    private:
        std::vector<int> elements;

    public:
        void push(int element);
        void pop();
        int top();
};

#endif  // STACKIMP_H
