#include <stdio.h>
#include <stdlib.h>

// Define Node structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    for(int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }

        temp = newNode;
    }

    // Make it circular
    if(temp != NULL)
        temp->next = head;

    // Traverse circular list
    if(head != NULL) {
        temp = head;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while(temp != head);
    }

    return 0;
}
