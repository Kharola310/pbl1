#ifndef DIJKSTRA_H
#define DIJKSTRA_H

void getgraph(int map_no, int src, int end, char *description);
int DijkstrasAlgo(int V, int **graph, char **names, int src, int end, int *dist);


void printf_map1();
void printf_map2();
void printf_map3();


void addDeliveryDetail(int map_no, int src, int end, int dist, char **names, char *description);
void displayAllDeliveryDetails();
int getDeliveryCount();
void printDivider();


#endif
