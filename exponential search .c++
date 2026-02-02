#include <iostream>
using namespace std;

// Binary Search function
int binarySearch(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Exponential Search function
int exponentialSearch(int arr[], int n, int x) {
    // If first element is the target
    if (arr[0] == x)
        return 0;

    int i = 1;
    while (i < n && arr[i] <= x)
        i *= 2;

    // Call binary search for the found range
    return binarySearch(arr, i / 2, min(i, n - 1), x);
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;

    int result = exponentialSearch(arr, n, x);

    if (result == -1)
        cout << "Element not found";
    else
        cout << "Element found at index " << result;

    return 0;
}
