#include <stdio.h>
#include <math.h>

int jumpSearch(int arr[], int n, int x) {
    int step = sqrt(n);
    int prev = 0;

    while (arr[(step < n ? step : n) - 1] < x) {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }

    for (int i = prev; i < (step < n ? step : n); i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 15;
    int index = jumpSearch(arr, n, x);
    if (index != -1)
        printf("Element %d found at index %d\n", x, index);
    else
        printf("Element %d not found\n", x);
    return 0;
}
