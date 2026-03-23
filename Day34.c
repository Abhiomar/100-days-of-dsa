#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Push
void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

// Pop
int pop(struct Node** top) {
    if (*top == NULL) {
        return -1; // underflow
    }
    struct Node* temp = *top;
    int value = temp->data;
    *top = temp->next;
    free(temp);
    return value;
}

// Evaluate postfix
int evaluatePostfix(char* exp) {
    struct Node* stack = NULL;
    int i = 0;

    while (exp[i] != '\0') {

        // Skip spaces
        if (exp[i] == ' ') {
            i++;
            continue;
        }

        // Operand
        if (isdigit(exp[i])) {
            int num = 0;

            // Handle multi-digit numbers
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }

            push(&stack, num);
            continue;
        }

        // Operator
        int val2 = pop(&stack);
        int val1 = pop(&stack);

        switch (exp[i]) {
            case '+': push(&stack, val1 + val2); break;
            case '-': push(&stack, val1 - val2); break;
            case '*': push(&stack, val1 * val2); break;
            case '/': push(&stack, val1 / val2); break;
        }

        i++;
    }

    return pop(&stack);
}

// Main
int main() {
    char exp[100];

    fgets(exp, sizeof(exp), stdin);

    int result = evaluatePostfix(exp);

    printf("%d", result);

    return 0;
}
