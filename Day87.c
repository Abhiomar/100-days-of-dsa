#include <stdio.h>

// Simple sort (Bubble Sort)
void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Iterative Binary Search
int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Step 1: Sort array
    sort(arr, n);

    // Print sorted array
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    // Optional: search element
    int key;
    scanf("%d", &key);

    int result = binarySearch(arr, n, key);

    if (result != -1)
        printf("FOUND at index %d\n", result);
    else
        printf("NOT FOUND\n");

    return 0;
}
