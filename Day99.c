#include <stdio.h>
#include <stdlib.h>

// Structure for car
struct Car {
    int position;
    int speed;
};

// Compare for sorting (descending position)
int compare(const void *a, const void *b) {
    return ((struct Car*)b)->position - ((struct Car*)a)->position;
}

int main() {
    int n, target;
    scanf("%d %d", &n, &target);

    struct Car cars[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &cars[i].position);

    for (int i = 0; i < n; i++)
        scanf("%d", &cars[i].speed);

    // Step 1: Sort by position descending
    qsort(cars, n, sizeof(struct Car), compare);

    int fleets = 0;
    double lastTime = 0;

    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].position) / cars[i].speed;

        // New fleet
        if (time > lastTime) {
            fleets++;
            lastTime = time;
        }
        // else joins previous fleet
    }

    printf("%d\n", fleets);

    return 0;
}
