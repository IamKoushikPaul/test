#include <stdio.h>

int rbinsearch(int arr[], int l, int h, int key) {
    if (l > h) {
        return -1;
    }
    int mid = l + (h - l) / 2;
    if (arr[mid] == key) {
        return mid;
    } 
    else if (arr[mid] > key) {
        return rbinsearch(arr, l, mid - 1, key);
    } 
    else {
        return rbinsearch (arr, mid + 1, h, key);
    }
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 2;
    int result = rbinsearch (arr, 0, n - 1, key);

    if (result == -1) {
        printf("Key %d not found in the array\n", key);
    } else {
        printf("Key %d found at index %d\n", key, result);
    }
    return 0;
}
