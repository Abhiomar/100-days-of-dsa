#include <stdio.h>
#include <stdlib.h>

// Compare function for sorting
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Check if we can place k cows with min distance = dist
int canPlace(int arr[], int n, int k, int dist) {
    int count = 1; // first cow at first stall
    int lastPos = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] - lastPos >= dist) {
            count++;
            lastPos = arr[i];
        }
        if (count >= k)
            return 1;
    }
    return 0;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Sort stall positions
    qsort(arr, n, sizeof(int), compare);

    int low = 1;
    int high = arr[n - 1] - arr[0];
    int ans = 0;

    // Binary search on answer
    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPlace(arr, n, k, mid)) {
            ans = mid;
            low = mid + 1; // try bigger distance
        } else {
            high = mid - 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}
