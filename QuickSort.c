#include <stdio.h>

void quickSort(int arr[], int L, int H) {
    if (L < H) {
        int pivot = arr[L];
        int i = L;
        int j = H + 1;
        int temp;

        do {
            do {
                i++;
            } while (i <= H && arr[i] < pivot);

            do {
                j--;
            } while (arr[j] > pivot);

            if (i < j) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        } while (i < j);

        temp = arr[L];
        arr[L] = arr[j];
        arr[j] = temp;

        quickSort(arr, L, j - 1);
        quickSort(arr, j + 1, H);
    }
}

int main() {
    int arr[] = {10, 100, 20, 5, 30, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quickSort(arr, 0, size - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}