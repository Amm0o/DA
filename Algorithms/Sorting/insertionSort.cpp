// Not the best but in some sittuations really good
// For times when list is almost sorted or already sorted
// Best case scenarion O(n)

#include <iostream>

void insertionSort(int arr[], int size) {

    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int c = i-1;
        while (c >= 0 && arr[c] > key) {
            arr[c+1] = arr[c];
            c--;
        }

        arr[c+1] = key;
    }
}

int main () {
    int arr[5] = {8,1,6,0,4};
    int size = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr,size);
    for (auto n : arr) {
        std::cout << n << "->";
    }
    return 0;
}