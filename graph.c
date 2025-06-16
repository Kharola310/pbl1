#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h> // Added for INT_MAX
#include "Dijkstra.h"
#include "DeliveryDetails.h"

#define MAX_LINE 100
#define MAX_NAME 50

void getgraph(int map_no, int src, int end, char *description) {
    FILE *file = fopen("graph.txt", "r");
    if (file == NULL) {
        printf("Could not open file.\n");
        exit(2);
    }

    char line[MAX_LINE];
    int size = 0, found = 0;

    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "# Graph", 7) == 0) {
            int gnum;
            sscanf(line, "# Graph %d", &gnum);
            if (gnum == map_no) {
                found = 1;
                break;
            }
        }
    }

    if (!found) {
        printf("Graph not found.\n");
        fclose(file);
        return;
    }

    fscanf(file, "%d\n", &size);

    if (src >= size || end >= size || src < 0 || end < 0) {
        printf("Invalid source or destination for the selected graph.\n");
        fclose(file);
        return;
    }

    // Allocate memory for graph and names
    int **graph = (int **)malloc(size * sizeof(int *));
    char **names = (char **)malloc(size * sizeof(char *));
    for (int i = 0; i < size; i++) {
        graph[i] = (int *)malloc(size * sizeof(int));
        names[i] = (char *)malloc(MAX_NAME * sizeof(char));
    }

    // Read until # Names
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "# Names", 7) == 0) break;
    }

    // Read names
    for (int i = 0; i < size; i++) {
        fgets(line, sizeof(line), file);
        line[strcspn(line, "\n")] = 0; // Remove newline
        strcpy(names[i], line);
    }

    // Read until # Matrix
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "# Matrix", 8) == 0) break;
    }

    // Read matrix
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            fscanf(file, "%d", &graph[i][j]);
        }
    }

    fclose(file);

    // Call Dijkstra's algorithm and get distance
    int dist[size];
    int final_dist = DijkstrasAlgo(size, graph, names, src, end, dist);

    // Add delivery details if distance is valid
    if (final_dist != INT_MAX) {
        addDeliveryDetail(map_no, src, end, final_dist, names, description);
    }

    // Free memory
    for (int i = 0; i < size; i++) {
        free(graph[i]);
        free(names[i]);
    }
    free(graph);
    free(names);
}
