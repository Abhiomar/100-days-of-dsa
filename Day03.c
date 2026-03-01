#include <stdio.h>

int main() {
    int n, k;
    int comparisons = 0;
    int found = 0;

    // Read size
    scanf("%d", &n);

    int arr[n];

    // Read elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read key
    scanf("%d", &k);

    // Linear Search
    for(int i = 0; i < n; i++) {
        comparisons++;
        if(arr[i] == k) {
            printf("Found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("Not Found\n");
    }

    printf("Comparisons = %d", comparisons);

    return 0;
}
