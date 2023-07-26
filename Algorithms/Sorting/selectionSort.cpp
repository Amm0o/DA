// Simple algorithm
// Scans the list for the smallest element for the one in the first position


#include <iostream>

void selectionSort(int array[], int sizeOfArray) {

    int* smallest;
    int indexSwap;

    for(int i = 0; i < sizeOfArray - 1 ; i++) {
        smallest = &array[i];
        indexSwap = i;
        for(int c = i + 1; c < sizeOfArray; c++) {
            if (array[c] < *smallest) {
                smallest = &array[c];
                indexSwap = c;
            }
        }
            int pivot = array[i];
            array[i] = *smallest;
            array[indexSwap] = pivot;
    }
}



int main() {
    
    int arr[5] = {8,1,6,0,4};
    int sizeOfArray = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, sizeOfArray);

    for (auto n : arr) {
        std::cout << n << "->";
    } 

    return 0;
}