#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push
void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}

// Pop
void pop() {
    if (top == -1) {
        return; // ignore underflow for this problem
    }
    top--;
}

// Display
void display() {
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
}

// Main
int main() {
    int n, m, x;

    scanf("%d", &n);

    // Push elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        push(x);
    }

    scanf("%d", &m);

    // Pop m times
    for (int i = 0; i < m; i++) {
        pop();
    }

    // Display remaining stack
    display();

    return 0;
}
