// Divide and conquer O(n log n)
// Uses pivoting to sort the array
// Select a pivot point and move all elements smaller than the pivot to the left of it 
// and all elements larger than the pivot to the right of it
// Quick sort is the fastest on average the issue is the worst case which is O(n^2)

#include <iostream>



int partition(int arr[], int left, int right, int pivot) {
    while (left <= right) {
        while (arr[left] < pivot) {
            left++;
        }

        while (arr[right] > pivot) {
            right--;
        }

        if (left <= right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;

            left++;
            right--;
        }
    }
    return left;
}

void quickSort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }

    int pivot = arr[(left + right) / 2];
    int index = partition(arr, left, right, pivot);
    quickSort(arr, left, index - 1);
    quickSort(arr, index, right);
}


int main () {
    int arr[5] = {8,1,6,0,4};
    int size = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr,0,size-1);
    for (auto n : arr) {
        std::cout << n << "->";
    }
    return 0;
}