// O (n log n)
// Uses devide and conquer

// Merge sort
// Divide the array in half
// Sort each half
// Merge the two halves


#include <iostream>

// merge method
void merge(int arr[], int left, int middle, int right) {
    int sizeLeft = middle - left + 1;
    int sizeRight = right - middle;

    int leftArr[sizeLeft];
    int rightArr[sizeRight];

    for (int i = 0; i < sizeLeft; i++) {
        leftArr[i] = arr[left + i];
    }

    for (int i = 0; i < sizeRight; i++) {
        rightArr[i] = arr[middle + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < sizeLeft && j < sizeRight) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < sizeLeft) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < sizeRight) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// merge sort method
// Explain the code below
void mergeSort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }

    int middle = left + (right - left) / 2;
    mergeSort(arr, left, middle);
    mergeSort(arr, middle + 1, right);
    merge(arr, left, middle, right);
}

int main( ) {

    int arr[5] = {6,1,3,9,4};
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, size - 1);

    for (auto& n : arr) {
        std::cout << n << "->";
    }

    return 0;
}