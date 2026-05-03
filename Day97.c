#include <stdio.h>
#include <stdlib.h>

// Structure for interval
struct Interval {
    int start, end;
};

// Compare function for sorting by start time
int compare(const void *a, const void *b) {
    return ((struct Interval*)a)->start - ((struct Interval*)b)->start;
}

// Min heap functions
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(int heap[], int i) {
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(int heap[], int size, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Interval arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d %d", &arr[i].start, &arr[i].end);

    // Step 1: Sort by start time
    qsort(arr, n, sizeof(struct Interval), compare);

    // Min heap to store end times
    int heap[n];
    int size = 0;

    // First meeting
    heap[size++] = arr[0].end;

    for (int i = 1; i < n; i++) {
        // If room is free
        if (arr[i].start >= heap[0]) {
            heap[0] = arr[i].end;
            heapifyDown(heap, size, 0);
        } else {
            // Need new room
            heap[size] = arr[i].end;
            heapifyUp(heap, size);
            size++;
        }
    }

    printf("%d\n", size);

    return 0;
}
