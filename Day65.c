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

// DFS cycle detection
int dfs(int v, int parent) {
    visited[v] = 1;

    struct Node* temp = adj[v];
    while (temp) {
        int next = temp->vertex;

        if (!visited[next]) {
            if (dfs(next, v))
                return 1;
        }
        else if (next != parent) {
            return 1; // cycle found
        }

        temp = temp->next;
    }
    return 0;
}

// Check cycle in graph
int hasCycle(int n) {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1))
                return 1;
        }
    }
    return 0;
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

    if (hasCycle(n))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
