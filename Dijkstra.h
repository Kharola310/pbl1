#ifndef DIJKSTRA_H
#define DIJKSTRA_H

void getgraph(int map_no, int src, int end, char *description);
int DijkstrasAlgo(int V, int **graph, char **names, int src, int end, int *dist);

#endif
