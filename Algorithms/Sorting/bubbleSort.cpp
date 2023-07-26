
#include <iostream>


void bubbleSort(int arr[5], int size) {

    bool didSort = true;
    while (didSort) {
        for (int i = 0; i < size-1; i++) {
            didSort = false;
            if (arr[i] > arr[i+1]) {
                int pivot = arr[i + 1];
                arr[i+1] = arr[i];
                arr[i] = pivot;
                didSort = true;
            }
        }
    }
}

int main() {
    int arr[5] = {6,1,3,9,4};
    bubbleSort(arr, sizeof(arr)/sizeof(arr[0]));

    for (auto& n : arr) {
        std::cout << n << "->";
    }
    return 0;
}