#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    int max = 0;

    // Input + find max
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > max)
            max = arr[i];
    }

    // Create count array
    int count[max + 1];
    for (int i = 0; i <= max; i++)
        count[i] = 0;

    // Frequency count
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // Prefix sum
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    // Output array
    int output[n];

    // Build output (right to left for stability)
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Print sorted array
    for (int i = 0; i < n; i++)
        printf("%d ", output[i]);

    return 0;
}
