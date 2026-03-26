#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Edge {
    int u, v, w;
};


int find(int parent[], int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}


void unionSet(int parent[], int u, int v) {
    int u_root = find(parent, u);
    int v_root = find(parent, v);
    parent[u_root] = v_root;
}


void sortEdges(struct Edge edges[], int e) {
    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, e;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    struct Edge edges[MAX];

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }


    sortEdges(edges, e);

    int parent[MAX];
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    printf("\nEdges in Minimum Spanning Tree:\n");

    int count = 0;
    for (int i = 0; i < e && count < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        int set_u = find(parent, u);
        int set_v = find(parent, v);

        if (set_u != set_v) {
            printf("%d - %d : %d\n", u, v, edges[i].w);
            unionSet(parent, set_u, set_v);
            count++;
        }
    }

    return 0;
}
