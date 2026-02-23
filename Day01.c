#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);

    int arr[n + 1];  
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int pos, x;

    // Input position and element
    scanf("%d", &pos);
    scanf("%d", &x);

    // Convert 1-based position to 0-based index
    int index = pos - 1;

    // Shift elements to the right
    for(int i = n; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert element
    arr[index] = x;

    // Print updated array
    for(int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
