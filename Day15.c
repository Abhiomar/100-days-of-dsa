#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[m][n];
    int sum = 0;

    // Read matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate primary diagonal sum
    int limit = (m < n) ? m : n;  // Works even if matrix is not square

    for(int i = 0; i < limit; i++) {
        sum += matrix[i][i];
    }

    printf("%d", sum);

    return 0;
}
