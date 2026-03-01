#include <stdio.h>

int main() {
    int n;

    // Read size
    scanf("%d", &n);

    if(n <= 0) return 0;

    int arr[n];

    // Read sorted array
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Two-pointer method
    int j = 0;   // Points to last unique element

    for(int i = 1; i < n; i++) {
        if(arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }

    // Print unique elements (0 to j)
    for(int i = 0; i <= j; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
