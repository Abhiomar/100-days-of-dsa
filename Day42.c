#include <stdio.h>

#define MAX 100

// Queue
int queue[MAX];
int front = -1, rear = -1;

// Stack
int stack[MAX];
int top = -1;

// Enqueue
void enqueue(int x) {
    if (rear == MAX - 1) return;

    if (front == -1) front = 0;
    queue[++rear] = x;
}

// Dequeue
int dequeue() {
    if (front == -1) return -1;

    int val = queue[front++];
    if (front > rear)
        front = rear = -1;

    return val;
}

// Push (stack)
void push(int x) {
    stack[++top] = x;
}

// Pop (stack)
int pop() {
    return stack[top--];
}

// Reverse queue
void reverseQueue() {
    // Step 1: move queue → stack
    while (front != -1) {
        push(dequeue());
    }

    // Step 2: move stack → queue
    while (top != -1) {
        enqueue(pop());
    }
}

// Display queue
void display() {
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
}

// Main
int main() {
    int n, x;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    reverseQueue();

    display();

    return 0;
}
