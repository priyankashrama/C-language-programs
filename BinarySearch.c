#include <stdio.h>

// A recursive binary search function. It returns
// location of x in given array arr[low..high] is present,
// otherwise -1
int binarySearch(int arr[], int low, int high, int x) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, low, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, high, x);
    }

    // We reach here when element is not
    // present in array
    return -1;
}

int main()
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1) printf("Element is not present in array");
    else printf("Element is present at index %d", result);
    return 0;
}

// Output
// Element is present at index 3

// Time Complexity: 
// -> Best Case: O(1)
// -> Average Case: O(log N)
// -> Worst Case: O(log N)
  
// Auxiliary Space: O(1), If the recursive call stack is considered then the auxiliary space will be O(log N).
