// if we know the list is sorted we can discard half of the list at each iteration. EX:
// 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 and we want to find 17.
// 1. We start at the middle of the list, 13, and compare it with 17.
// 2. Since 13 < 17, we discard the left half of the list. 
// 3. We now have 14, 15, 16, 17, 18 and we want to find 17.
// 4. We start at the middle of the list, 15, and compare it with 17.
// 5. Since 15 < 17, we discard the left half of the list.
// 6. We now have 16, 17, 18 and we want to find 17.
// 7. We start at the middle of the list, 17, and compare it with 17.
// 8. Since 17 == 17, we found the value.
// Time complexity: O(log n)
//
// In order for this to be possible, the list must be sorted. Or even better we should use a binary search tree to store the data.


#include <iostream>



bool binarySearch(int arr[], int l, int r, int n) {

    if (r >= l) {
        int mid = l + (r - 1) / 2; 


        // if element is present in the middle
        if(arr[mid] == n) return mid;

        // If element is lower than the element in the middle
        else if(arr[mid] > n) {
            return binarySearch(arr, l, mid - 1, n);
        } else { // If element is lower than the element in the middle
            return binarySearch(arr, mid + 1, r, n);
        }
        
    }

    // return -1 when element to present
    return false;

}

int binarySearchW (int arr[], int l, int r, int n ) {

    while (r>=l) {
        int mid = l + (r - 1) / 2;
        if (arr[mid] == n) return mid;
        else if(arr[mid] > n) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    // if not found
    return -1;
}

int main() {

    int array[10] = {1,2,3,4,5,6,7,8,9,10};

    int size = sizeof(array) / sizeof(array[0]);

    int found = binarySearchW(array, 0, size-1, 9);

    std::cout << found << std::endl;


}