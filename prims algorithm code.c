#include <stdio.h>
#define MAX 100



int minKey(int key[], int visited[], int n) {
    int min = 9999, min_index;

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0 && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}



void printMST(int parent[], int graph[MAX][MAX], int n) {
    printf("\nEdge \tWeight\n");
    for (int i = 1; i < n; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}



void primMST(int graph[MAX][MAX], int n) {
    int parent[MAX];
    int key[MAX];
    int visited[MAX];

    for (int i = 0; i < n; i++) {
        key[i] = 9999;
        visited[i] = 0;
    }

    key[0] = 0;

    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, visited, n);
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && visited[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, n);
}

int main() {
    int n;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    printf("(Enter 0 if no edge)\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST(graph, n);

    return 0;
}
