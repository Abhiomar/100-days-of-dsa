#include <stdio.h>

// Check if painting is possible within maxTime
int isPossible(int arr[], int n, int k, int maxTime) {
    int painters = 1;
    int total = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxTime)
            return 0;

        if (total + arr[i] <= maxTime) {
            total += arr[i];
        } else {
            painters++;
            total = arr[i];
        }
    }

    return (painters <= k);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    int sum = 0, maxVal = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    int low = maxVal;
    int high = sum;
    int ans = high;

    // Binary search
    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}
