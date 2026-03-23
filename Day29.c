#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to rotate list
struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || k == 0)
        return head;

    struct Node* temp = head;
    int n = 1;

    // Find length
    while (temp->next != NULL) {
        temp = temp->next;
        n++;
    }

    // Make circular
    temp->next = head;

    k = k % n;
    int steps = n - k;

    temp = head;

    // Move to (n-k)th node
    for (int i = 1; i < steps; i++) {
        temp = temp->next;
    }

    // New head
    head = temp->next;

    // Break the circle
    temp->next = NULL;

    return head;
}

// Function to print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

// Main function
int main() {
    int n, k, x;

    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        struct Node* newNode = createNode(x);

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    scanf("%d", &k);

    head = rotateRight(head, k);

    printList(head);

    return 0;
}
