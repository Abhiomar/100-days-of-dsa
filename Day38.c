#include <stdio.h>

#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

// Check empty
int isEmpty() {
    return front == -1;
}

// Check full
int isFull() {
    return (front == (rear + 1) % MAX);
}

// Push front
void push_front(int x) {
    if (isFull()) return;

    if (isEmpty()) {
        front = rear = 0;
    } else {
        front = (front - 1 + MAX) % MAX;
    }

    deque[front] = x;
}

// Push back
void push_back(int x) {
    if (isFull()) return;

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    deque[rear] = x;
}

// Pop front
void pop_front() {
    if (isEmpty()) return;

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Pop back
void pop_back() {
    if (isEmpty()) return;

    if (front == rear) {
        front = rear = -1;
    } else {
        rear = (rear - 1 + MAX) % MAX;
    }
}

// Get front
void getFront() {
    if (isEmpty()) printf("-1\n");
    else printf("%d\n", deque[front]);
}

// Get rear
void getBack() {
    if (isEmpty()) printf("-1\n");
    else printf("%d\n", deque[rear]);
}

// Size
void size() {
    if (isEmpty()) {
        printf("0\n");
        return;
    }

    if (rear >= front)
        printf("%d\n", rear - front + 1);
    else
        printf("%d\n", MAX - front + rear + 1);
}

// Display deque
void display() {
    if (isEmpty()) return;

    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Reverse deque (simple)
void reverse() {
    if (isEmpty()) return;

    int temp[MAX], i = 0;

    int idx = front;
    while (1) {
        temp[i++] = deque[idx];
        if (idx == rear) break;
        idx = (idx + 1) % MAX;
    }

    front = 0;
    rear = i - 1;

    for (int j = 0; j < i; j++) {
        deque[j] = temp[i - j - 1];
    }
}

// Sort (simple bubble sort)
void sort() {
    if (isEmpty()) return;

    int temp[MAX], i = 0;

    int idx = front;
    while (1) {
        temp[i++] = deque[idx];
        if (idx == rear) break;
        idx = (idx + 1) % MAX;
    }

    // Bubble sort
    for (int j = 0; j < i - 1; j++) {
        for (int k = 0; k < i - j - 1; k++) {
            if (temp[k] > temp[k + 1]) {
                int t = temp[k];
                temp[k] = temp[k + 1];
                temp[k + 1] = t;
            }
        }
    }

    front = 0;
    rear = i - 1;

    for (int j = 0; j < i; j++) {
        deque[j] = temp[j];
    }
}

// Main
int main() {
    int n, x;
    char op[20];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (op[0] == 'p' && op[5] == 'f') { // push_front
            scanf("%d", &x);
            push_front(x);
        }
        else if (op[0] == 'p' && op[5] == 'b') { // push_back
            scanf("%d", &x);
            push_back(x);
        }
        else if (op[0] == 'p' && op[4] == 'f') { // pop_front
            pop_front();
        }
        else if (op[0] == 'p' && op[4] == 'b') { // pop_back
            pop_back();
        }
        else if (op[0] == 'f') { // front
            getFront();
        }
        else if (op[0] == 'b') { // back
            getBack();
        }
        else if (op[0] == 's') { // size
            size();
        }
        else if (op[0] == 'r' && op[1] == 'e') { // reverse
            reverse();
        }
        else if (op[0] == 's' && op[1] == 'o') { // sort
            sort();
        }
    }

    // Final state
    display();

    return 0;
}
