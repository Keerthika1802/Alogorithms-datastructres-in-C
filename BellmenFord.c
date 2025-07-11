#include <stdio.h>
#include <stdlib.h>
#define INF 999

void printDistanceMatrix(int V, int distance[], int iteration) {
    printf("Iteration %d:  ", iteration);
    for (int i = 0; i < V; i++) {
        if (distance[i] == INF)
            printf("INF ");
        else
            printf("%d ", distance[i]);
    }
    printf("\n");
}

void BellmanFord(int V, int graph[V][V], int src) {
    int distance[V];
    for (int i = 0; i < V; i++) {
        distance[i] = INF;
    }
    distance[src] = 0;

    printf("Initial distances:\n");
    printDistanceMatrix(V, distance, 0);

    for (int i = 1; i <= V - 1; i++) {
        int updated = 0;
        int tempDistance[V];
        for (int k = 0; k < V; k++) {
            tempDistance[k] = distance[k];
        }
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                if (graph[u][v] != INF && distance[u] != INF && distance[u] + graph[u][v] < tempDistance[v]) {
                    tempDistance[v] = distance[u] + graph[u][v];
                    updated = 1;
                }
            }
        }
        for (int k = 0; k < V; k++) {
            distance[k] = tempDistance[k];
        }
        printDistanceMatrix(V, distance, i);
        if (!updated) {
            break;
        }
    }

    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != INF && distance[u] != INF && distance[u] + graph[u][v] < distance[v]) {
                printf("Negative weight cycle detected\n");
                return;
            }
        }
    }

    printf("Final distances from source %d:\n", src + 1);
    printDistanceMatrix(V, distance, V);
}

int main() {
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int graph[V][V];
    printf("Enter the adjacency matrix (use %d for no edge):\n", INF);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int src;
    printf("Enter source vertex (1 to %d): ", V);
    scanf("%d", &src);

    if (src < 1 || src > V) {
        printf("Invalid source vertex!\n");
    } else {
        BellmanFord(V, graph, src - 1);
    }
    return 0;
}
