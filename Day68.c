#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[MAX];
int indegree[MAX];

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

// Add edge (directed)
void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    indegree[v]++; // increase indegree
}

// Topological Sort using Kahn's Algorithm
void topoSort(int n) {
    // Add all vertices with indegree 0 to queue
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    int count = 0;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        count++;

        struct Node* temp = adj[v];
        while (temp) {
            int next = temp->vertex;
            indegree[next]--;

            if (indegree[next] == 0)
                queue[rear++] = next;

            temp = temp->next;
        }
    }

    // Check for cycle
    if (count != n) {
        printf("\nCycle exists (Not a DAG)\n");
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
        indegree[i] = 0;
    }

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    topoSort(n);

    return 0;
}
