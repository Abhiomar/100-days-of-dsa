#include <stdio.h>
#include <string.h>

#define EMPTY -1

int hashTable[100];

// Hash function
int hash(int key, int m) {
    return key % m;
}

// Insert using quadratic probing
void insert(int key, int m) {
    int index = hash(key, m);

    for (int i = 0; i < m; i++) {
        int newIndex = (index + i*i) % m;

        if (hashTable[newIndex] == EMPTY) {
            hashTable[newIndex] = key;
            return;
        }
    }

    printf("Hash Table Full\n");
}

// Search using quadratic probing
int search(int key, int m) {
    int index = hash(key, m);

    for (int i = 0; i < m; i++) {
        int newIndex = (index + i*i) % m;

        if (hashTable[newIndex] == key)
            return 1;

        if (hashTable[newIndex] == EMPTY)
            return 0;
    }

    return 0;
}

// Main
int main() {
    int m, q;
    scanf("%d", &m);  // table size
    scanf("%d", &q);  // number of operations

    // Initialize table
    for (int i = 0; i < m; i++)
        hashTable[i] = EMPTY;

    char op[10];
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key, m);
        }
        else if (strcmp(op, "SEARCH") == 0) {
            if (search(key, m))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}
