#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];

// Queue
int queue[MAX];
int front = 0, rear = 0;

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected)
void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    struct Node* newNode2 = createNode(u);
    newNode2->next = adj[v];
    adj[v] = newNode2;
}

// BFS function
void bfs(int start) {
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        struct Node* temp = adj[v];
        while (temp) {
            int next = temp->vertex;
            if (!visited[next]) {
                visited[next] = 1;
                queue[rear++] = next;
            }
            temp = temp->next;
        }
    }
}

// Main
int main() {
    int n, m;
    scanf("%d", &n);  // vertices
    scanf("%d", &m);  // edges

    // Initialize
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    int start;
    scanf("%d", &start);

    bfs(start);

    return 0;
}
