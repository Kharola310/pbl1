#include <limits.h>
#include <stdio.h>
#include"Dijkstra.h"


int findminDistance(int V, int dist[], int included[])
{
    int min = INT_MAX, min_index;


    for (int v = 0; v < V; v++) {
        if (included[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}



void printPath(int parent[], int j )
{
    if(parent[j] == -1){
        printf("%d", j);
        return ;
    }
    printPath(parent, parent[j]);
    printf(" -> %d", j);

}
void printSolution(int V, int dist[],int parent[])
{
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d   ", i, dist[i]);
        printPath(parent,i);
        printf("\n");
    }
}



void DijkstrasAlgo(int V, int graph[V][V], int src)
{
    int included[V], dist[V], parent[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        included[i] = 0;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {

        int u = findminDistance(V,dist, included);


        included[u] = 1;


        for (int v = 0; v < V; v++) {

            if (!included[v] && graph[u][v]
                && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }


    printSolution(V,dist,parent);
}


