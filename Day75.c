#include <stdio.h>

#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int sum = 0, maxLen = 0;

    // Hash map (sum -> first index)
    int hash[2 * MAX] = {0};  // for simplicity
    for (int i = 0; i < 2 * MAX; i++)
        hash[i] = -1;

    int offset = MAX; // handle negative sums

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0) {
            maxLen = i + 1;
        }

        if (hash[sum + offset] != -1) {
            int len = i - hash[sum + offset];
            if (len > maxLen)
                maxLen = len;
        } else {
            hash[sum + offset] = i;
        }
    }

    printf("%d\n", maxLen);

    return 0;
}
