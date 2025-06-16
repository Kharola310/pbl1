#include <limits.h>
#include <stdio.h>
#include "Dijkstra.h"

void printPath(int parent[], int j, char **names) {
    if (parent[j] == -1) {
        printf("%s", names[j]);
        return;
    }
    printPath(parent, parent[j], names);
    printf(" -> %s", names[j]);
}

void printSolution(int V, int start, int end, int dist[], int parent[], char **names) {
    printf("Your path from start to final destination: \n");
    printPath(parent, end, names);
    printf("\n");
    printf("The total distance is: %d\n", dist[end]);
}

int findminDistance(int V, int dist[], int included[]) {
    int min_distance = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!included[v] && dist[v] <= min_distance) {
            min_distance = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

int DijkstrasAlgo(int V, int **graph, char **names, int src, int end, int *dist) {
    int included[V], parent[V];
    for (int i = 0; i < V; i++) {
        included[i] = 0;
        dist[i] = INT_MAX;
        parent[i] = -1;
    }
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        int u = findminDistance(V, dist, included);
        included[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !included[v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
    printSolution(V, src, end, dist, parent, names);
    return dist[end];
}
