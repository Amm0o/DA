#include <iostream>
#include <string>


// Each recursive call to the function will receive a smaller string, with the front and back characters of the previous string removed. 
// This is a key part of the recursive process, 
// as it ensures that we're making progress towards the base case (a string of length 1 or less), at which point the recursion stops.

std::string reverseString(const std::string& str) {
    if (str.length() <= 1) {
        return str;
    } else {
        return str.back() + reverseString(str.substr(1, str.length() - 2)) + str.front();
    }
}

int main() {
    
    std::string str = "Angelo";
    std::cout << reverseString(str);
    return 0;
}
