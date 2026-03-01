#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    for(int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL)
            head = newNode;
        else
            temp->next = newNode;

        temp = newNode;
    }
    return head;
}

// Get length of list
int getLength(struct Node* head) {
    int length = 0;
    while(head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

// Find intersection point
void findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    // Move pointer of longer list
    if(len1 > len2) {
        for(int i = 0; i < diff; i++)
            head1 = head1->next;
    } else {
        for(int i = 0; i < diff; i++)
            head2 = head2->next;
    }

    // Traverse both together
    while(head1 != NULL && head2 != NULL) {
        if(head1->data == head2->data) {
            printf("%d", head1->data);
            return;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    printf("No Intersection");
}

int main() {
    int n, m;

    scanf("%d", &n);
    struct Node* list1 = createList(n);

    scanf("%d", &m);
    struct Node* list2 = createList(m);

    findIntersection(list1, list2);

    return 0;
}
