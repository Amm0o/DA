// O(n log n) time O(1) space

// Just use STL to implement heap sort quick sort will be better in most cases

#include <iostream>
#include <algorithm>
#include <vector>

void heapSort(std::vector<int>& arr) {
    // This will rearrange the elements into a heap
    std::make_heap(arr.begin(), arr.end());

    // Now we will sort the elements using heap sort
    std::sort_heap(arr.begin(), arr.end());
}

void printArray(std::vector<int>& arr) {
    for(int i : arr)
        std::cout << i << " ";
    std::cout << "\n";
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};

    std::cout << "Given array is: \n";
    printArray(arr);

    heapSort(arr);

    std::cout << "\nSorted array is: \n";
    printArray(arr);
    
    return 0;
}






